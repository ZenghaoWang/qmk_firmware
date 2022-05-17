#pragma once

// ========= Tapping settings ================
#undef TAPPING_TERM
#define TAPPING_TERM 175

// Allows for different tapping terms on a per-key basis.
#define TAPPING_TERM_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

/* Tapping this number of times holds the key until tapped once again. */
// With the default value of 5, I kept activating this by accident.
#define ONESHOT_TAP_TOGGLE 99

// Force chords to be on different hands to prevent accidental mod activations when rolling keys.
#define BILATERAL_COMBINATIONS 500
#define PREVENT_STUCK_MODIFIERS

// ========= Combo settings ================
#define COMBO_TERM 35
// Combos must be tapped, not held. This will let us use combos involving mod taps/layer taps.
#define COMBO_MUST_TAP_PER_COMBO
// ========= Mouse settings ================
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 25

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10

// ========= Mouse wheel settings ================
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 100

#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 203

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 15

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 15

// ========= Auto Shift settings ================
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define NO_AUTO_SHIFT_TAB
#define NO_AUTO_SHIFT_NUMERIC
#define NO_AUTO_SHIFT_ALPHA

// ========= Misc settings ================
#ifdef AUDIO_ENABLE
// #define STARTUP_SONG SONG(MARIO_THEME)
// #define GOODBYE_SONG SONG(MARIO_GAMEOVER)
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define GOODBYE_SONG STARTUP_SONG
#endif
#define USB_SUSPEND_WAKEUP_DELAY 0

#define ORYX_CONFIGURATOR

// volume: max = 4095U
#define AUDIO_DAC_SAMPLE_MAX 2500U

// space saving combined with the flto flag in rules.mk
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
