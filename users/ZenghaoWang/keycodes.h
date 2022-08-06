#pragma once
#include "keyboards/moonlander/moonlander.h"
#include "keyboards/bastardkb/charybdis/charybdis.h"
#include "layers.h"

enum zenghao_keycodes {
    // Press enter, then send the string /mute_all, then press enter
    MACRO_MUTE_ALL = CHARYBDIS_SAFE_RANGE,
    MACRO_PASTE_OVER,
    MACRO_COPY_ALL,
    MACRO_CUT_ALL,
    MACRO_DEL_ALL,
    // Bring up the windows power options menu.
    MACRO_WIN_POWER_OPTS,
    // Detatch a tab from the current browser window and send it to the left half of the current screen.
    MACRO_SPLIT_TAB,
    // Detatch a tab from the current browser window and send it to the monitor to the left.
    MACRO_SPLIT_TAB_SCREEN,
    MACRO_SECRET_1,
    MACRO_SECRET_2,
    MACRO_ALT_TAB,
    MACRO_ALT_SHIFT_TAB,
    KC_CAPS_WORD,
    // Start of enum for all keymap specific keys
    ZENGHAO_SAFE_RANGE
};

// Aliases for home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)

// Windows screenshot shortcut
#define KC_SNIP LGUI(LSFT(KC_S))

#define LT_F_WINDOW LT(Z_WINDOW, KC_F)
#define LT_U_APP LT(Z_APP, KC_U)

// layer toggles
#define LT_SPC_NAV LT(Z_NAV, KC_SPC)
#define LT_TAB_MOUSE LT(Z_MOUSE, KC_TAB)
#define LT_ESC_MEDIA LT(Z_MEDIA, KC_ESC)
#define LT_DEL_FN LT(Z_FN, KC_DEL)
#define LT_BSPC_NUMPAD LT(Z_NUMPAD, KC_BSPC)
#define LT_ENT_SYMBOLS LT(Z_SYMBOLS, KC_ENT)
