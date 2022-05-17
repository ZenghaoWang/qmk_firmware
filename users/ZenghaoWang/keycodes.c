/**
 * Keycodes that are not keyboard specific, such as macros
 */
#include "keycodes.h"
#include "caps_word.h"
#include "process_key_override.h"

// Attribute indicates that it can be replaced by a keymap level function
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

uint8_t  mod_state;
uint8_t  oneshot_mod_state;
uint16_t last_keycode;

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT_BSPC_NUMPAD, KC_DELETE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL  // Null terminate the array of overrides!
};

// Used for the alt tab macro
void matrix_scan_user(void) {  // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {  // the number of milliseconds before the window is selected.
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state         = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    process_caps_word(keycode, record);

    switch (keycode) {
        case KC_CAPS_WORD:
            if (record->event.pressed) {
                if (caps_word_on) {
                    caps_word_disable();
                    return false;
                } else {
                    caps_word_enable();
                    return false;
                }
            }
        case MACRO_MUTE_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ENTER) SS_DELAY(100) "/mute all" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            break;
        case MACRO_PASTE_OVER:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
            }
            break;
        case MACRO_COPY_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_C)));
            }
            break;
        case MACRO_CUT_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LCTL(SS_TAP(X_X)));
            }
            break;
        case MACRO_DEL_ALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_DELETE));
            }
            break;
        case MACRO_WIN_POWER_OPTS:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_X)) SS_DELAY(600) SS_TAP(X_U));
            }
            break;
        case MACRO_SPLIT_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_W)) SS_DELAY(200) SS_LGUI(SS_TAP(X_LEFT)));
            }
            break;

        case MACRO_SPLIT_TAB_SCREEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_W)) SS_DELAY(200) SS_LGUI(SS_LSFT(SS_TAP(X_LEFT))));
            }
            break;

        /**
         * When rolling o into u, somethings the windows key triggers on the o. We want to send o u instead
         * of win-u
         */
        case KC_U:
            /*
            Detect the tap.
            We're only interested in overriding the tap behaviour
            in a certain cicumstance. The hold behaviour can stay the same.
            */
            if (record->tap.count > 0) {
                // Detect right Shift
                if (get_mods() & MOD_BIT(KC_RGUI)) {
                    // temporarily disable right gui
                    // so that we can send KC_O and KC_U
                    // without triggering gui.
                    unregister_mods(MOD_BIT(KC_RGUI));
                    tap_code(KC_O);
                    tap_code(KC_U);
                    // restore the mod state
                    add_mods(MOD_BIT(KC_RGUI));
                    // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
                    return false;
                }
            }
            /*else process RCTL_T(KC_N) as usual.*/
            return true;

        case MACRO_ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case KC_ESC: {
            clear_mods();
            clear_oneshot_mods();
            clear_oneshot_locked_mods();
            break;
        }
    }
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
};
