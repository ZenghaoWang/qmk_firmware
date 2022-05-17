/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "users/ZenghaoWang/tap_dance.h"
#include "users/ZenghaoWang/keycodes.h"
#include "users/ZenghaoWang/layout.h"
#include "users/ZenghaoWang/layers.h"

#define LAYOUT_ortho_4x12_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [Z_BASE] = LAYOUT_ortho_4x12_wrapper(
        __BASE_L1__,         MACRO_SECRET_2,          MACRO_SECRET_1,                    __BASE_R1__,
        __BASE_L2__,         AUTOCRT,                   KC_NO,                             __BASE_R2__,
        __BASE_L3__,         KC_NO,                   KC_NO,                             __BASE_R3__,
        KC_NO,               KC_NO,                   OSM(MOD_LSFT),                     __THUMB_CLUSTER_BASE_L__,   __THUMB_CLUSTER_BASE_R__, KC_UNDS, KC_NO, KC_NO),

    [Z_NAV] = LAYOUT_ortho_4x12_wrapper(
        KC_NO,         LALT(KC_F4), KC_F2,   KC_F5,         KC_NO,            KC_NO,                     KC_NO,                KC_APP,              MACRO_PASTE_OVER,      MACRO_COPY_ALL,   MACRO_CUT_ALL,          KC_NO,
        __MOD_ROW_L__, KC_NO,       KC_NO,   KC_NO,         TD(TD_NAV_LEFT),  TD(TD_NAV_DOWN),           TD(TD_NAV_UP),        TD(TD_NAV_RIGHT),    LCTL(KC_C),
        KC_NO,         KC_NO,       KC_NO,   KC_NO,         KC_NO,            KC_NO,                     KC_NO,                KC_HOME,             KC_PGDN,               KC_PGUP,          KC_END,                 KC_INS,
        KC_NO,         KC_NO,       KC_NO,   KC_NO,         KC_NO,            KC_NO,                     MACRO_DEL_ALL,        KC_ENT,              LCTL(KC_V),            LCTL(KC_Z),       LCTL(KC_Y),             KC_NO      ),

    [Z_MOUSE] = LAYOUT_ortho_4x12_wrapper(
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,            KC_NO,            KC_NO,            KC_NO,    KC_NO,   KC_NO,
          __MOD_ROW_L__, KC_NO, KC_NO, KC_NO,            KC_MS_L,          KC_MS_D,          KC_MS_U,  KC_MS_R, KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,            KC_WH_L,          KC_WH_D,          KC_WH_U,  KC_WH_R, KC_NO,
          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_BTN3,          KC_BTN2,          KC_BTN1,          KC_SNIP,    KC_NO,   KC_NO),

    [Z_MEDIA] = LAYOUT_ortho_4x12_wrapper(
         KC_NO,       KC_NO,   KC_NO,   KC_NO,                  KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                               KC_NO,   KC_NO,
         __MOD_ROW_L__, KC_NO,   KC_NO,   KC_NO,                  KC_MPRV,                        KC_VOLD,                        KC_VOLU,                        KC_MNXT,                        KC_NO,
         KC_NO,       KC_NO,   KC_NO,   KC_NO,                  KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                          KC_NO,                               KC_NO,   KC_NO,
         KC_NO,       KC_NO,   KC_NO,   KC_NO,                  KC_NO,                          KC_NO,                          LSFT(LCTL(LALT(KC_S))),         KC_MUTE,                        KC_MPLY,                        LGUI(KC_K),                          KC_NO,   KC_NO),

    [Z_NUMPAD] = LAYOUT_ortho_4x12_wrapper(
        KC_LBRC,                 TD(TD_7_CTRL),     TD(TD_8_CTRL),    TD(TD_9_CTRL),    KC_RBRC, KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,
        KC_COLON,                TD(TD_4_CTRL),     TD(TD_5_CTRL),    TD(TD_6_CTRL),    KC_ASTR, KC_NO,    KC_NO,    KC_NO,    __MOD_ROW_R__,
        TD(TD_PERC_DOLLAR),      TD(TD_1_CTRL),     TD(TD_2_CTRL),    TD(TD_3_CTRL),    KC_PSLS, KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,
        KC_NO,                   TD(TD_MINUS_ZOOM), TD(TD_PLUS_ZOOM), TD(TD_0_CTRL),    KC_EQL,  KC_DOT,   KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO),

    [Z_SYMBOLS] = LAYOUT_ortho_4x12_wrapper(
        KC_EXLM,        TD(TD_BTICK_CTRL),             KC_AT,                KC_HASH,           KC_DOLLAR,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TILD,        KC_ASTR,                       KC_LEFT_PAREN,        KC_RIGHT_PAREN,    KC_PERC,        KC_NO, KC_NO,   KC_NO,   __MOD_ROW_R__,
        KC_AMPERSAND,   KC_CIRC,                       KC_LCBR,              KC_RCBR,           KC_NO,          KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,          KC_NO,                         KC_PIPE,              KC_MINS,           LGUI(KC_DOT),   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO   ),

    [Z_FN] = LAYOUT_ortho_4x12_wrapper(
        MACRO_SECRET_2,                  KC_F7,                  KC_F8,                                 KC_F9,      KC_F12,                  KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        MACRO_SECRET_1,                  KC_F4,                  KC_F5,                                 KC_F6,      KC_F11,                  KC_NO, KC_NO, KC_NO,  __MOD_ROW_R__,
        KC_NO,                           KC_F1,                  KC_F2,                                 KC_F3,      KC_F10,                  KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,                           KC_NO,                  MACRO_WIN_POWER_OPTS,                  LGUI(KC_L), TD(TD_FLASH),            KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO   ),

    [Z_WINDOW] = LAYOUT_ortho_4x12_wrapper(
         KC_NO, KC_NO,                             KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO,              KC_NO,                   MACRO_SPLIT_TAB,              MACRO_SPLIT_TAB_SCREEN,                   KC_NO,                                   KC_NO,
         KC_NO, KC_NO,                             KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO,              TD(TD_WINDOW_LEFT),      TD(TD_WINDOW_DOWN),           TD(TD_WINDOW_UP),                         TD(TD_WINDOW_RIGHT),                     LCTL(LALT(KC_F9)),
         KC_NO, KC_NO,                             KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO,              LCTL(LGUI(KC_LEFT)),     LCTL(LGUI(KC_F4)),            LCTL(LGUI(KC_D)),                         LCTL(LGUI(KC_RIGHT)),                    KC_NO,
         KC_NO, KC_NO,                             KC_NO, KC_NO,                KC_NO, KC_NO,   LGUI(LALT(KC_D)),   LGUI(KC_A),              LGUI(KC_TAB),                 LCTL(LSFT(KC_ESC)),                       KC_NO,                                   KC_NO),

    [Z_APP] = LAYOUT_ortho_4x12_wrapper(
         KC_NO, TD(TD_APP_7), TD(TD_APP_8),                TD(TD_APP_9), KC_NO,                  KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, TD(TD_APP_4), TD(TD_APP_5),                TD(TD_APP_6), KC_NO,                  KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, TD(TD_APP_1), TD(TD_APP_2),                TD(TD_APP_3), KC_NO,                  KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
         KC_NO, KC_NO,        LSFT(LCTL(LALT(KC_SPC))),    TD(TD_APP_0), KC_NO,                  KC_NO, KC_NO,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO ),
    // Placeholder layer to provide the right handedness for the bilateral combinations heuristic.
    [Z_HANDS] = LAYOUT_ortho_4x12_wrapper(
        KC_L, KC_L, KC_L, KC_L, KC_L, KC_L, KC_R, KC_R, KC_R, KC_R, KC_R, KC_R,
        KC_L, KC_L, KC_L, KC_L, KC_L, KC_L, KC_R, KC_R, KC_R, KC_R, KC_R, KC_R,
        KC_L, KC_L, KC_L, KC_L, KC_L, KC_L, KC_R, KC_R, KC_R, KC_R, KC_R, KC_R,
        KC_L, KC_L, KC_L, KC_L, KC_L, KC_L, KC_R, KC_R, KC_R, KC_R, KC_R, KC_R
    )};

// clang-format on
