#pragma once
#include "quantum.h"
#include "keycodes.h"
#include "layers.h"

/**
 * We can use these blocks in place of series of keycodes in all our keymaps that use this layout,
 * so that we only have to change the layout in one place.
 */

#define __BASE_L1__ KC_Q, KC_W, LT_F_WINDOW, KC_P, KC_B
#define __BASE_L2__ HOME_A, HOME_R, HOME_S, HOME_T, KC_G
#define __BASE_L3__ KC_Z, KC_X, KC_C, TD(TD_D_WOX), KC_V

#define __BASE_R1__ KC_J, KC_L, LT_U_APP, KC_Y, KC_QUOT
#define __BASE_R2__ KC_M, HOME_N, HOME_E, HOME_I, HOME_O
#define __BASE_R3__ KC_K, TD(TD_H_TODO), KC_COMM, TD(TD_DOT), KC_SLSH

#define __MOD_ROW_L__ KC_LGUI, KC_LALT, KC_LSHIFT, KC_LCTRL
#define __MOD_ROW_R__ KC_RCTRL, KC_RSHIFT, KC_RALT, KC_RGUI

#define __NUM_ROW_2 LSFT(KC_B), KC_N, KC_E, LSFT(KC_W), LSFT(KC_G)

#define __THUMB_CLUSTER_BASE_L__ LT_SPC_NAV, LT_TAB_MOUSE, LT_ESC_MEDIA
#define __THUMB_CLUSTER_BASE_R__ LT_DEL_FN, LT_ENT_SYMBOLS, LT_BSPC_NUMPAD

// #define __NAV_L1__
// #define __NAV_L2__
// #define __NAV_L3__

// #define __NAV_R1__
// #define __NAV_R2__
// #define __NAV_R3__
