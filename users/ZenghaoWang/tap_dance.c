#include "tap_dance.h"
#include "quantum.h"
#include "process_tap_dance.h"
#include "keycodes.h"
#include "caps_word.h"

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

typedef enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, TRIPLE_TAP, TRIPLE_HOLD, MORE_TAPS, NONE } td_state_t;

static tap dance_state[37];

td_state_t dance_step(qk_tap_dance_state_t *state);

td_state_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    }
    return MORE_TAPS;
}

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_D);
        tap_code16(KC_D);
        tap_code16(KC_D);
    }
    if (state->count > 3) {
        tap_code16(KC_D);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            register_code16(KC_D);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(KC_SPACE));
            break;
        case DOUBLE_TAP:
            register_code16(KC_D);
            register_code16(KC_D);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_D);
            register_code16(KC_D);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP:
            unregister_code16(KC_D);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(KC_SPACE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_D);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_D);
            break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LALT(LCTL(LSFT(KC_P))));
        tap_code16(LALT(LCTL(LSFT(KC_P))));
        tap_code16(LALT(LCTL(LSFT(KC_P))));
    }
    if (state->count > 3) {
        tap_code16(LALT(LCTL(LSFT(KC_P))));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            register_code16(LALT(LCTL(LSFT(KC_P))));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_S)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LCTL(LSFT(KC_P))));
            register_code16(LALT(LCTL(LSFT(KC_P))));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LALT(LCTL(LSFT(KC_P))));
            register_code16(LALT(LCTL(LSFT(KC_P))));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP:
            unregister_code16(LALT(LCTL(LSFT(KC_P))));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_S)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LCTL(LSFT(KC_P))));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LALT(LCTL(LSFT(KC_P))));
            break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if (state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            register_code16(KC_H);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(LCTL(LSFT(KC_A))));
            break;
        case DOUBLE_TAP:
            register_code16(KC_H);
            register_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_H);
            register_code16(KC_H);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP:
            unregister_code16(KC_H);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(LCTL(LSFT(KC_A))));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_H);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_H);
            break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if (state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            register_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            register_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_ESCAPE);
            register_code16(KC_ESCAPE);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_TAB);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_ESCAPE);
            break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if (state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            register_code16(KC_LEFT);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(KC_LEFT));
            break;
        case DOUBLE_TAP:
            register_code16(KC_LEFT);
            register_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_LEFT);
            register_code16(KC_LEFT);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP:
            unregister_code16(KC_LEFT);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(KC_LEFT));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_LEFT);
            break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
        tap_code16(KC_DOWN);
    }
    if (state->count > 3) {
        tap_code16(KC_DOWN);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            register_code16(KC_DOWN);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(KC_DOWN));
            break;
        case DOUBLE_TAP:
            register_code16(KC_DOWN);
            register_code16(KC_DOWN);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_DOWN);
            register_code16(KC_DOWN);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP:
            unregister_code16(KC_DOWN);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(KC_DOWN));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_DOWN);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_DOWN);
            break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_UP);
        tap_code16(KC_UP);
        tap_code16(KC_UP);
    }
    if (state->count > 3) {
        tap_code16(KC_UP);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            register_code16(KC_UP);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(KC_UP));
            break;
        case DOUBLE_TAP:
            register_code16(KC_UP);
            register_code16(KC_UP);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_UP);
            register_code16(KC_UP);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP:
            unregister_code16(KC_UP);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(KC_UP));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_UP);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_UP);
            break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if (state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            register_code16(KC_RIGHT);
            break;
        case SINGLE_HOLD:
            register_code16(LALT(KC_RIGHT));
            break;
        case DOUBLE_TAP:
            register_code16(KC_RIGHT);
            register_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_RIGHT);
            register_code16(KC_RIGHT);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
        case SINGLE_HOLD:
            unregister_code16(LALT(KC_RIGHT));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RIGHT);
            break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if (state->count > 3) {
        tap_code16(KC_7);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            register_code16(KC_7);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_7));
            break;
        case DOUBLE_TAP:
            register_code16(KC_7);
            register_code16(KC_7);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_7);
            register_code16(KC_7);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP:
            unregister_code16(KC_7);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_7));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_7);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_7);
            break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if (state->count > 3) {
        tap_code16(KC_8);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            register_code16(KC_8);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_8));
            break;
        case DOUBLE_TAP:
            register_code16(KC_8);
            register_code16(KC_8);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_8);
            register_code16(KC_8);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP:
            unregister_code16(KC_8);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_8));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_8);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_8);
            break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(qk_tap_dance_state_t *state, void *user_data);
void dance_10_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_10_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_10(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if (state->count > 3) {
        tap_code16(KC_9);
    }
}

void dance_10_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            register_code16(KC_9);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_9));
            break;
        case DOUBLE_TAP:
            register_code16(KC_9);
            register_code16(KC_9);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_9);
            register_code16(KC_9);
    }
}

void dance_10_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP:
            unregister_code16(KC_9);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_9));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_9);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_9);
            break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(qk_tap_dance_state_t *state, void *user_data);
void dance_11_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_11_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_11(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
        tap_code16(LSFT(KC_SCOLON));
    }
    if (state->count > 3) {
        tap_code16(LSFT(KC_SCOLON));
    }
}

void dance_11_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_SCOLON));
            break;
        case SINGLE_HOLD:
            register_code16(KC_SCOLON);
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_SCOLON));
            register_code16(LSFT(KC_SCOLON));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LSFT(KC_SCOLON));
            register_code16(LSFT(KC_SCOLON));
    }
}

void dance_11_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP:
            unregister_code16(LSFT(KC_SCOLON));
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_SCOLON);
            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_SCOLON));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_SCOLON));
            break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(qk_tap_dance_state_t *state, void *user_data);
void dance_12_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_12_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_12(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if (state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_12_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            register_code16(KC_4);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_4));
            break;
        case DOUBLE_TAP:
            register_code16(KC_4);
            register_code16(KC_4);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_4);
            register_code16(KC_4);
    }
}

void dance_12_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP:
            unregister_code16(KC_4);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_4));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_4);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_4);
            break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(qk_tap_dance_state_t *state, void *user_data);
void dance_13_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_13_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_13(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if (state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_13_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            register_code16(KC_5);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_5));
            break;
        case DOUBLE_TAP:
            register_code16(KC_5);
            register_code16(KC_5);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_5);
            register_code16(KC_5);
    }
}

void dance_13_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP:
            unregister_code16(KC_5);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_5));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_5);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_5);
            break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(qk_tap_dance_state_t *state, void *user_data);
void dance_14_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_14_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_14(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if (state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_14_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            register_code16(KC_6);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_6));
            break;
        case DOUBLE_TAP:
            register_code16(KC_6);
            register_code16(KC_6);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_6);
            register_code16(KC_6);
    }
}

void dance_14_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP:
            unregister_code16(KC_6);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_6));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_6);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_6);
            break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(qk_tap_dance_state_t *state, void *user_data);
void dance_15_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_15_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_15(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LSFT(KC_5));
        tap_code16(LSFT(KC_5));
        tap_code16(LSFT(KC_5));
    }
    if (state->count > 3) {
        tap_code16(LSFT(KC_5));
    }
}

void dance_15_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            register_code16(LSFT(KC_5));
            break;
        case SINGLE_HOLD:
            register_code16(LSFT(KC_4));
            break;
        case DOUBLE_TAP:
            register_code16(LSFT(KC_5));
            register_code16(LSFT(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LSFT(KC_5));
            register_code16(LSFT(KC_5));
    }
}

void dance_15_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
        case SINGLE_HOLD:
            unregister_code16(LSFT(KC_4));
            break;
        case DOUBLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LSFT(KC_5));
            break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(qk_tap_dance_state_t *state, void *user_data);
void dance_16_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_16_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_16(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if (state->count > 3) {
        tap_code16(KC_1);
    }
}

void dance_16_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            register_code16(KC_1);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_1));
            break;
        case DOUBLE_TAP:
            register_code16(KC_1);
            register_code16(KC_1);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_1);
            register_code16(KC_1);
    }
}

void dance_16_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP:
            unregister_code16(KC_1);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_1));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_1);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_1);
            break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(qk_tap_dance_state_t *state, void *user_data);
void dance_17_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_17_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_17(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if (state->count > 3) {
        tap_code16(KC_2);
    }
}

void dance_17_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            register_code16(KC_2);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_2));
            break;
        case DOUBLE_TAP:
            register_code16(KC_2);
            register_code16(KC_2);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_2);
            register_code16(KC_2);
    }
}

void dance_17_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP:
            unregister_code16(KC_2);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_2));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_2);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_2);
            break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(qk_tap_dance_state_t *state, void *user_data);
void dance_18_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_18_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_18(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if (state->count > 3) {
        tap_code16(KC_3);
    }
}

void dance_18_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            register_code16(KC_3);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_3));
            break;
        case DOUBLE_TAP:
            register_code16(KC_3);
            register_code16(KC_3);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_3);
            register_code16(KC_3);
    }
}

void dance_18_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP:
            unregister_code16(KC_3);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_3));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_3);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_3);
            break;
    }
    dance_state[18].step = 0;
}
void on_dance_19(qk_tap_dance_state_t *state, void *user_data);
void dance_19_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_19_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_19(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
        tap_code16(KC_KP_MINUS);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_MINUS);
    }
}

void dance_19_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_MINUS);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_KP_MINUS));
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_MINUS);
            register_code16(KC_KP_MINUS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_MINUS);
            register_code16(KC_KP_MINUS);
    }
}

void dance_19_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_MINUS);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_KP_MINUS));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_MINUS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_MINUS);
            break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(qk_tap_dance_state_t *state, void *user_data);
void dance_20_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_20_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_20(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_KP_PLUS);
        tap_code16(KC_KP_PLUS);
        tap_code16(KC_KP_PLUS);
    }
    if (state->count > 3) {
        tap_code16(KC_KP_PLUS);
    }
}

void dance_20_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            register_code16(KC_KP_PLUS);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_KP_PLUS));
            break;
        case DOUBLE_TAP:
            register_code16(KC_KP_PLUS);
            register_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_KP_PLUS);
            register_code16(KC_KP_PLUS);
    }
}

void dance_20_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_KP_PLUS));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_KP_PLUS);
            break;
    }
    dance_state[20].step = 0;
}
void on_dance_21(qk_tap_dance_state_t *state, void *user_data);
void dance_21_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_21_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_21(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if (state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_21_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            register_code16(KC_0);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_0));
            break;
        case DOUBLE_TAP:
            register_code16(KC_0);
            register_code16(KC_0);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_0);
            register_code16(KC_0);
    }
}

void dance_21_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP:
            unregister_code16(KC_0);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_0));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_0);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_0);
            break;
    }
    dance_state[21].step = 0;
}
void on_dance_22(qk_tap_dance_state_t *state, void *user_data);
void dance_22_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_22_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_22(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
        tap_code16(KC_GRAVE);
    }
    if (state->count > 3) {
        tap_code16(KC_GRAVE);
    }
}

void dance_22_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            register_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            register_code16(LCTL(KC_GRAVE));
            break;
        case DOUBLE_TAP:
            register_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_GRAVE);
            register_code16(KC_GRAVE);
    }
}

void dance_22_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case SINGLE_HOLD:
            unregister_code16(LCTL(KC_GRAVE));
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_GRAVE);
            break;
    }
    dance_state[22].step = 0;
}
void on_dance_23(qk_tap_dance_state_t *state, void *user_data);
void dance_23_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_23_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_23(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_LEFT));
        tap_code16(LGUI(KC_LEFT));
        tap_code16(LGUI(KC_LEFT));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_LEFT));
    }
}

void dance_23_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_LEFT));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_LEFT)));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(KC_LEFT));
            register_code16(LGUI(KC_LEFT));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_LEFT));
            register_code16(LGUI(KC_LEFT));
    }
}

void dance_23_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_LEFT));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_LEFT)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(KC_LEFT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_LEFT));
            break;
    }
    dance_state[23].step = 0;
}
void on_dance_24(qk_tap_dance_state_t *state, void *user_data);
void dance_24_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_24_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_24(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_DOWN));
        tap_code16(LGUI(KC_DOWN));
        tap_code16(LGUI(KC_DOWN));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_DOWN));
    }
}

void dance_24_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_DOWN));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(KC_D));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(KC_DOWN));
            register_code16(LGUI(KC_DOWN));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_DOWN));
            register_code16(LGUI(KC_DOWN));
    }
}

void dance_24_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_DOWN));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(KC_D));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(KC_DOWN));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_DOWN));
            break;
    }
    dance_state[24].step = 0;
}
void on_dance_25(qk_tap_dance_state_t *state, void *user_data);
void dance_25_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_25_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_25(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_UP));
        tap_code16(LGUI(KC_UP));
        tap_code16(LGUI(KC_UP));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_UP));
    }
}

void dance_25_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[25].step = dance_step(state);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_UP));
            break;
        case SINGLE_HOLD:
            register_code16(KC_F11);
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(KC_UP));
            register_code16(LGUI(KC_UP));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_UP));
            register_code16(LGUI(KC_UP));
    }
}

void dance_25_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[25].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_UP));
            break;
        case SINGLE_HOLD:
            unregister_code16(KC_F11);
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(KC_UP));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_UP));
            break;
    }
    dance_state[25].step = 0;
}
void on_dance_26(qk_tap_dance_state_t *state, void *user_data);
void dance_26_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_26_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_26(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LGUI(KC_RIGHT));
        tap_code16(LGUI(KC_RIGHT));
        tap_code16(LGUI(KC_RIGHT));
    }
    if (state->count > 3) {
        tap_code16(LGUI(KC_RIGHT));
    }
}

void dance_26_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[26].step = dance_step(state);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            register_code16(LGUI(KC_RIGHT));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_RIGHT)));
            break;
        case DOUBLE_TAP:
            register_code16(LGUI(KC_RIGHT));
            register_code16(LGUI(KC_RIGHT));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LGUI(KC_RIGHT));
            register_code16(LGUI(KC_RIGHT));
    }
}

void dance_26_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[26].step) {
        case SINGLE_TAP:
            unregister_code16(LGUI(KC_RIGHT));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_RIGHT)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LGUI(KC_RIGHT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LGUI(KC_RIGHT));
            break;
    }
    dance_state[26].step = 0;
}
void on_dance_27(qk_tap_dance_state_t *state, void *user_data);
void dance_27_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_27_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_27(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_7)));
        tap_code16(LCTL(LGUI(KC_7)));
        tap_code16(LCTL(LGUI(KC_7)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_7)));
    }
}

void dance_27_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[27].step = dance_step(state);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_7)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_7)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_7)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_7)));
            register_code16(LCTL(LGUI(KC_7)));
    }
}

void dance_27_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[27].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_7)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_7)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_7)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_7)));
            break;
    }
    dance_state[27].step = 0;
}
void on_dance_28(qk_tap_dance_state_t *state, void *user_data);
void dance_28_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_28_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_28(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_8)));
        tap_code16(LCTL(LGUI(KC_8)));
        tap_code16(LCTL(LGUI(KC_8)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_8)));
    }
}

void dance_28_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[28].step = dance_step(state);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_8)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_8)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_8)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_8)));
            register_code16(LCTL(LGUI(KC_8)));
    }
}

void dance_28_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[28].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_8)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_8)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_8)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_8)));
            break;
    }
    dance_state[28].step = 0;
}
void on_dance_29(qk_tap_dance_state_t *state, void *user_data);
void dance_29_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_29_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_29(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_9)));
        tap_code16(LCTL(LGUI(KC_9)));
        tap_code16(LCTL(LGUI(KC_9)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_9)));
    }
}

void dance_29_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[29].step = dance_step(state);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_9)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_9)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_9)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_9)));
            register_code16(LCTL(LGUI(KC_9)));
    }
}

void dance_29_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[29].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_9)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_9)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_9)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_9)));
            break;
    }
    dance_state[29].step = 0;
}
void on_dance_30(qk_tap_dance_state_t *state, void *user_data);
void dance_30_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_30_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_30(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_4)));
        tap_code16(LCTL(LGUI(KC_4)));
        tap_code16(LCTL(LGUI(KC_4)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_4)));
    }
}

void dance_30_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[30].step = dance_step(state);
    switch (dance_state[30].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_4)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_4)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_4)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_4)));
            register_code16(LCTL(LGUI(KC_4)));
    }
}

void dance_30_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[30].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_4)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_4)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_4)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_4)));
            break;
    }
    dance_state[30].step = 0;
}
void on_dance_31(qk_tap_dance_state_t *state, void *user_data);
void dance_31_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_31_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_31(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_5)));
        tap_code16(LCTL(LGUI(KC_5)));
        tap_code16(LCTL(LGUI(KC_5)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_5)));
    }
}

void dance_31_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[31].step = dance_step(state);
    switch (dance_state[31].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_5)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_5)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_5)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_5)));
            register_code16(LCTL(LGUI(KC_5)));
    }
}

void dance_31_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[31].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_5)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_5)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_5)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_5)));
            break;
    }
    dance_state[31].step = 0;
}
void on_dance_32(qk_tap_dance_state_t *state, void *user_data);
void dance_32_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_32_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_32(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_6)));
        tap_code16(LCTL(LGUI(KC_6)));
        tap_code16(LCTL(LGUI(KC_6)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_6)));
    }
}

void dance_32_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[32].step = dance_step(state);
    switch (dance_state[32].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_6)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_6)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_6)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_6)));
            register_code16(LCTL(LGUI(KC_6)));
    }
}

void dance_32_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[32].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_6)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_6)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_6)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_6)));
            break;
    }
    dance_state[32].step = 0;
}
void on_dance_33(qk_tap_dance_state_t *state, void *user_data);
void dance_33_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_33_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_33(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_1)));
        tap_code16(LCTL(LGUI(KC_1)));
        tap_code16(LCTL(LGUI(KC_1)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_1)));
    }
}

void dance_33_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[33].step = dance_step(state);
    switch (dance_state[33].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_1)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_1)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_1)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_1)));
            register_code16(LCTL(LGUI(KC_1)));
    }
}

void dance_33_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[33].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_1)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_1)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_1)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_1)));
            break;
    }
    dance_state[33].step = 0;
}
void on_dance_34(qk_tap_dance_state_t *state, void *user_data);
void dance_34_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_34_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_34(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_2)));
        tap_code16(LCTL(LGUI(KC_2)));
        tap_code16(LCTL(LGUI(KC_2)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_2)));
    }
}

void dance_34_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[34].step = dance_step(state);
    switch (dance_state[34].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_2)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_2)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_2)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_2)));
            register_code16(LCTL(LGUI(KC_2)));
    }
}

void dance_34_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[34].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_2)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_2)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_2)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_2)));
            break;
    }
    dance_state[34].step = 0;
}
void on_dance_35(qk_tap_dance_state_t *state, void *user_data);
void dance_35_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_35_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_35(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_3)));
        tap_code16(LCTL(LGUI(KC_3)));
        tap_code16(LCTL(LGUI(KC_3)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_3)));
    }
}

void dance_35_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[35].step = dance_step(state);
    switch (dance_state[35].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_3)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_3)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_3)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_3)));
            register_code16(LCTL(LGUI(KC_3)));
    }
}

void dance_35_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[35].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_3)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_3)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_3)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_3)));
            break;
    }
    dance_state[35].step = 0;
}
void on_dance_36(qk_tap_dance_state_t *state, void *user_data);
void dance_36_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_36_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_36(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 3) {
        tap_code16(LCTL(LGUI(KC_0)));
        tap_code16(LCTL(LGUI(KC_0)));
        tap_code16(LCTL(LGUI(KC_0)));
    }
    if (state->count > 3) {
        tap_code16(LCTL(LGUI(KC_0)));
    }
}

void dance_36_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[36].step = dance_step(state);
    switch (dance_state[36].step) {
        case SINGLE_TAP:
            register_code16(LCTL(LGUI(KC_0)));
            break;
        case SINGLE_HOLD:
            register_code16(LGUI(LSFT(KC_0)));
            break;
        case DOUBLE_TAP:
            register_code16(LALT(LGUI(KC_0)));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(LGUI(KC_0)));
            register_code16(LCTL(LGUI(KC_0)));
    }
}

void dance_36_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[36].step) {
        case SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_0)));
            break;
        case SINGLE_HOLD:
            unregister_code16(LGUI(LSFT(KC_0)));
            break;
        case DOUBLE_TAP:
            unregister_code16(LALT(LGUI(KC_0)));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(LCTL(LGUI(KC_0)));
            break;
    }
    dance_state[36].step = 0;
}

void on_dot(qk_tap_dance_state_t *state, void *user_data) {
    // If we're trying to type a > then ignore tap dance.
    if ((get_mods() & MOD_MASK_SHIFT)) {
        tap_code(KC_DOT);
        return;
    }

    switch (state->count) {
        case 2:
            tap_code(KC_SPC);
            add_oneshot_mods(MOD_BIT(KC_LSHIFT));
            break;

        case 3:
            tap_code(KC_BSPC);
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        default:
            tap_code(KC_DOT);
            break;
    }
};

void dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t step = dance_step(state);
    wait_ms(10);
    switch (step) {
        // holding dot produces a question mark, to remain consistent with auto shift
        case SINGLE_HOLD:
        case DOUBLE_HOLD:
            tap_code(KC_BSPC);
            tap_code16(KC_RABK);
            break;
        case TRIPLE_HOLD:
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            tap_code(KC_BSPC);
            tap_code16(KC_RABK);
            tap_code16(KC_RABK);
            tap_code16(KC_RABK);
            break;
    }
}

void flash_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (dance_step(state)) {
        case SINGLE_TAP:
            // Type the flash command
            SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_DELAY(100));
            SEND_STRING(SS_TAP(X_ENT));
            break;
        case SINGLE_HOLD:
            // Type the compile command
            SEND_STRING("qmk compile -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_DELAY(100));
            SEND_STRING(SS_TAP(X_ENT));
            break;
        case DOUBLE_TAP:
            // Open qmk msys
            SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(500) "QMK MSYS" SS_DELAY(500) SS_TAP(X_ENT) SS_DELAY(3000));
            // Type the flash command
            SEND_STRING("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_DELAY(100));
            SEND_STRING(SS_TAP(X_ENT));
            break;
        default:
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_D_WOX]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [TD_SS_SNIP]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [TD_H_TODO]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [TD_ESC_TAB]         = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
    [TD_NAV_LEFT]        = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
    [TD_NAV_DOWN]        = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
    [TD_NAV_UP]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
    [TD_NAV_RIGHT]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
    [TD_7_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
    [TD_8_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
    [TD_9_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
    [TD_COLON_SEMICOLON] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
    [TD_4_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
    [TD_5_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
    [TD_6_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
    [TD_PERC_DOLLAR]     = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
    [TD_1_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
    [TD_2_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
    [TD_3_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
    [TD_MINUS_ZOOM]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
    [TD_PLUS_ZOOM]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
    [TD_0_CTRL]          = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
    [TD_BTICK_CTRL]      = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
    [TD_WINDOW_LEFT]     = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
    [TD_WINDOW_DOWN]     = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
    [TD_WINDOW_UP]       = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_25, dance_25_finished, dance_25_reset),
    [TD_WINDOW_RIGHT]    = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_26, dance_26_finished, dance_26_reset),
    [TD_APP_7]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_27, dance_27_finished, dance_27_reset),
    [TD_APP_8]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_28, dance_28_finished, dance_28_reset),
    [TD_APP_9]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_29, dance_29_finished, dance_29_reset),
    [TD_APP_4]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_30, dance_30_finished, dance_30_reset),
    [TD_APP_5]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_31, dance_31_finished, dance_31_reset),
    [TD_APP_6]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_32, dance_32_finished, dance_32_reset),
    [TD_APP_1]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_33, dance_33_finished, dance_33_reset),
    [TD_APP_2]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_34, dance_34_finished, dance_34_reset),
    [TD_APP_3]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_35, dance_35_finished, dance_35_reset),
    [TD_APP_0]           = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_36, dance_36_finished, dance_36_reset),
    [TD_DOT]             = ACTION_TAP_DANCE_FN_ADVANCED(on_dot, dot_finished, NULL),
    [TD_FLASH]           = ACTION_TAP_DANCE_FN(flash_finished),

};
