#include QMK_KEYBOARD_H
#include "version.h"
#include "users/ZenghaoWang/tap_dance.h"
#include "users/ZenghaoWang/keycodes.h"
#include "users/ZenghaoWang/layout.h"
#include "users/ZenghaoWang/layers.h"

#define LAYOUT_moonlander_wrapper(...) LAYOUT_moonlander(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [Z_BASE] = LAYOUT_moonlander_wrapper(
    KC_NO,    KC_TRANSPARENT, LSFT(LCTL(KC_TAB)),                 MACRO_ALT_TAB,                 LCTL(KC_TAB),  KC_TRANSPARENT, KC_MUTE, KC_MEDIA_PLAY_PAUSE,   KC_NO, KC_TRANSPARENT, KC_NO, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,
    TG(Z_GAMING),          __BASE_L1__, KC_VOLU, KC_MNXT,   __BASE_R1__,       KC_TRANSPARENT,
    KC_NO,    __BASE_L2__, KC_VOLD, KC_MPRV,   __BASE_R2__,         KC_TRANSPARENT,
    KC_TRANSPARENT, __BASE_L3__, __BASE_R3__,       KC_TRANSPARENT,
    KC_HOME, KC_PGDN, KC_PGUP, KC_END, OSM(MOD_LSFT), TD(TD_SS_SNIP), LCTL(LSFT(KC_B)), KC_UNDS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    __THUMB_CLUSTER_BASE_L__, __THUMB_CLUSTER_BASE_R__
  ),

  [Z_GAMING] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_AUDIO_MUTE,                                  KC_MEDIA_PLAY_PAUSE,KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    KC_TRANSPARENT, KC_Q, KC_W, KC_F,           KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,                                KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           KC_TRANSPARENT, KC_SCOLON,      KC_BSLASH,
    TD(TD_ESC_TAB),    KC_A,           KC_R,           KC_S,           KC_T,           KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,                                                                KC_MEDIA_PREV_TRACK,KC_TRANSPARENT, KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,
    MACRO_MUTE_ALL,     KC_Z, KC_X, KC_C, KC_D, KC_V,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_SLASH,       KC_LSHIFT,
    LGUI_T(KC_GRAVE),KC_CAPSLOCK,    KC_LALT,        KC_LEFT,        KC_SPACE,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    TOGGLE_LAYER_COLOR,
    KC_LALT,        KC_LSHIFT,      KC_LCTRL,                       KC_DELETE,      KC_ENTER,       KC_BSPACE
  ),

  [Z_NAV] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          LALT(KC_F4),    KC_F2,          KC_F5,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_APP,          MACRO_PASTE_OVER,     MACRO_COPY_ALL,     MACRO_CUT_ALL,     KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, __MOD_ROW_L__,       KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, TD(TD_NAV_LEFT),    TD(TD_NAV_DOWN),    TD(TD_NAV_UP),    TD(TD_NAV_RIGHT),    LCTL(KC_C),     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_INSERT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_Y),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                          MACRO_DEL_ALL,     KC_ENTER,       LCTL(KC_V)
  ),

  [Z_MOUSE] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, __MOD_ROW_L__,  KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_SNIP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                 KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1
  ),

  [Z_MEDIA] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          TOGGLE_LAYER_COLOR,RGB_MOD,        RGB_HUD,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, __MOD_ROW_L__,       KC_NO,          KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,RGB_HUI,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,        KC_NO,KC_NO, KC_NO,KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, LGUI(KC_K),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 LALT(LCTL(LSFT(KC_S))),KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE
  ),

  [Z_NUMPAD] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,
    KC_TRANSPARENT,                 KC_LBRACKET,              TD(TD_7_CTRL),                    TD(TD_8_CTRL),              TD(TD_9_CTRL),                   KC_RBRACKET,              KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_NO,                          KC_TRANSPARENT,           KC_NO,                 KC_NO,           KC_NO,                          KC_TRANSPARENT,
    KC_TRANSPARENT,                 KC_COLON,   TD(TD_4_CTRL),                   TD(TD_5_CTRL),             TD(TD_6_CTRL),                   KC_KP_ASTERISK,           KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_RCTL, KC_RSHIFT, KC_RALT, KC_RGUI,                        KC_TRANSPARENT,
    KC_TRANSPARENT,                 TD(TD_PERC_DOLLAR),       TD(TD_1_CTRL),                   TD(TD_2_CTRL),             TD(TD_3_CTRL),                   KC_PSLS,                 KC_NO,                          KC_NO,                    KC_NO,                          KC_NO,                    KC_NO,                          KC_TRANSPARENT,
    KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 TD(TD_MINUS_ZOOM),             TD(TD_PLUS_ZOOM),                   KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,           KC_TRANSPARENT,                 KC_TRANSPARENT,
    TD(TD_0_CTRL),                   KC_EQUAL,                 KC_DOT,                         KC_NO,                    KC_TRANSPARENT,                 KC_TRANSPARENT
  ),

  [Z_SYMBOLS] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        TD(TD_BTICK_CTRL),           KC_AT,          KC_HASH,        KC_DLR,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        KC_ASTR, KC_LPRN,        KC_RPRN,        KC_PERC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          __MOD_ROW_R__,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR,        KC_CIRC,        KC_LCBR,        KC_RCBR,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PIPE,      KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MINUS,       LGUI(KC_DOT),   KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO
  ),

  [Z_FN] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MACRO_SECRET_2,          KC_F7,          KC_F8,          KC_F9,          KC_F12,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, MACRO_SECRET_1,          KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          __MOD_ROW_R__,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F10,                                         KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MACRO_WIN_POWER_OPTS,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SYSTEM_SLEEP, TD(TD_FLASH), KC_NO,                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [Z_WINDOW] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, MACRO_SPLIT_TAB,     MACRO_SPLIT_TAB_SCREEN,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, TD(TD_WINDOW_LEFT),   TD(TD_WINDOW_DOWN),   TD(TD_WINDOW_UP),   TD(TD_WINDOW_RIGHT),   LCTL(LALT(KC_F9)), KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_F4)), LCTL(LGUI(KC_D)), LCTL(LGUI(KC_RIGHT)), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, LCTL(LSFT(KC_ESCAPE)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 LALT(LGUI(KC_D)),LGUI(KC_A),     LGUI(KC_TAB)
  ),

  [Z_APP] = LAYOUT_moonlander_wrapper(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TD(TD_APP_7),   TD(TD_APP_8),   TD(TD_APP_9),   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          TD(TD_APP_4),   TD(TD_APP_5),   TD(TD_APP_6),   KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TD(TD_APP_1),   TD(TD_APP_2),   TD(TD_APP_3),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LCTL(LSFT(KC_SPACE))),KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    TD(TD_APP_0),   KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

// clang-format on

// // RGB stuff
// extern rgb_config_t rgb_matrix_config;

// void keyboard_post_init_user(void) {
//     rgb_matrix_enable();

// #ifdef CONSOLE_ENABLE
//     debug_enable = true;
// //   debug_matrix=true;
// //   debug_keyboard=true;
// // debug_mouse=true;
// #endif
// }

// // clang-format off
// const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
//     [1] = { {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255},
//     {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255}, {118,255,255} },

//     [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,252,255}, {0,0,0}, {31,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,252,255}, {31,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,252,255}, {31,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,252,255}, {31,252,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,255,255}, {31,252,255}, {0,0,0}, {0,0,0}, {31,255,255}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {31,252,255}, {105,255,255}, {105,255,255}, {0,205,155}, {0,0,0}, {31,252,255}, {105,255,255}, {105,255,255}, {0,205,155}, {0,0,0}, {0,0,0}, {105,255,255}, {105,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {31,252,255}, {31,252,255}, {31,252,255}, {0,0,0} },

//     [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {0,0,0}, {0,0,0}, {10,249,254}, {0,0,0}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {10,249,254}, {10,249,254}, {0,0,0}, {0,0,0}, {10,249,254}, {10,249,254}, {0,0,0}, {0,0,0}, {0,0,0}, {10,249,254}, {10,249,254}, {10,249,254}, {0,0,0} },

//     [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,251,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,251,254}, {0,0,0}, {0,0,0}, {243,251,254}, {0,0,0}, {243,251,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,251,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {33,255,255}, {243,222,234}, {0,0,0}, {0,0,0}, {33,255,255}, {243,251,254}, {85,203,158}, {0,0,0}, {0,0,0}, {105,255,255}, {243,251,254}, {134,255,213}, {0,0,0}, {0,0,0}, {105,255,255}, {243,251,254}, {0,0,255}, {146,250,246}, {0,0,0}, {0,0,0}, {243,251,254}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,251,254}, {243,251,254}, {243,251,254}, {0,0,0} },

//     [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {218,247,248}, {133,249,246}, {0,0,0}, {0,0,0}, {85,255,255}, {85,255,255}, {85,255,255}, {0,0,0}, {0,0,0}, {85,255,255}, {85,255,255}, {85,255,255}, {133,249,246}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {133,249,246}, {0,0,0}, {10,225,255}, {133,249,246}, {133,249,246}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {133,249,246}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0} },

//     [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {133,250,252}, {133,250,252}, {0,0,0}, {0,0,0}, {133,250,252}, {133,250,252}, {133,250,252}, {0,0,0}, {0,0,0}, {133,250,252}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0}, {133,250,252}, {10,225,255}, {10,225,255}, {0,0,0}, {133,250,252}, {133,250,252}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {133,250,252}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0} },

//     [7] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {249,250,244}, {249,250,244}, {0,0,0}, {0,0,0}, {249,250,244}, {249,250,244}, {249,250,244}, {0,0,0}, {0,0,0}, {249,250,244}, {249,250,244}, {249,250,244}, {249,250,244}, {0,0,0}, {249,250,244}, {249,250,244}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {249,250,244}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {249,250,244}, {0,0,0}, {0,0,0}, {249,250,244}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0} },

//     [8] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {146,250,246}, {146,250,246}, {0,0,0}, {0,0,0}, {146,250,246}, {146,250,246}, {146,250,246}, {0,0,0}, {0,0,0}, {146,250,246}, {146,250,246}, {146,250,246}, {146,250,246}, {0,0,0}, {0,0,0}, {146,250,246}, {146,250,246}, {0,0,0}, {0,0,0}, {0,0,0}, {146,250,246}, {146,250,246}, {146,250,246}, {0,0,0} },

//     [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {205,255,255}, {205,255,255}, {205,255,255}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {205,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

// };

// // clang-format on

// void set_layer_color(int layer) {
//     for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
//         HSV hsv = {
//             .h = pgm_read_byte(&ledmap[layer][i][0]),
//             .s = pgm_read_byte(&ledmap[layer][i][1]),
//             .v = pgm_read_byte(&ledmap[layer][i][2]),
//         };
//         if (!hsv.h && !hsv.s && !hsv.v) {
//             rgb_matrix_set_color(i, 0, 0, 0);
//         } else {
//             RGB   rgb = hsv_to_rgb(hsv);
//             float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//             rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
//         }
//     }
// }

// void rgb_matrix_indicators_user(void) {
//     if (keyboard_config.disable_layer_led) {
//         return;
//     }
//     switch (biton32(layer_state)) {
//         case 1:
//             set_layer_color(1);
//             break;
//         case 2:
//             set_layer_color(2);
//             break;
//         case 3:
//             set_layer_color(3);
//             break;
//         case 4:
//             set_layer_color(4);
//             break;
//         case 5:
//             set_layer_color(5);
//             break;
//         case 6:
//             set_layer_color(6);
//             break;
//         case 7:
//             set_layer_color(7);
//             break;
//         case 8:
//             set_layer_color(8);
//             break;
//         case 9:
//             set_layer_color(9);
//             break;
//         default:
//             if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
//             break;
//     }
// }

// bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case RGB_SLD:
//             if (record->event.pressed) {
//                 rgblight_mode(1);
//             }
//             return false;
//         case HSV_129_255_255:
//             if (record->event.pressed) {
//                 rgblight_mode(1);
//                 rgblight_sethsv(129, 255, 255);
//             }
//             return false;
//         case HSV_79_255_255:
//             if (record->event.pressed) {
//                 rgblight_mode(1);
//                 rgblight_sethsv(79, 255, 255);
//             }
//             return false;
//         case HSV_209_255_255:
//             if (record->event.pressed) {
//                 rgblight_mode(1);
//                 rgblight_sethsv(209, 255, 255);
//             }
//             return false;
//     }
//     return true;
// }
