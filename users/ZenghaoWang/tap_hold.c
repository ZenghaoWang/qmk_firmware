#include "keycodes.h"
#include "tap_dance.h"
#include "process_tap_dance.h"

// We want the weaker fingers to have longer tapping terms.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // windows pinky
        case HOME_A:
        case HOME_O:
            return TAPPING_TERM + 175;
        // alt ring finger
        case HOME_R:
        case HOME_I:
            return TAPPING_TERM + 100;
        case TD(TD_DOT):
            return TAPPING_TERM + 50;
        case LT_ENT_SYMBOLS:
            // So I don't hit enter by accident
            return TAPPING_TERM - 25;
        case LT_SPC_NAV:
            // Sometimes space doesn't register
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) { return true; }

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
        case HOME_A:
            return false;
        default:
            return true;
    }
}
