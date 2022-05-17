/**
 * Caps word: enable capslock and then disable it after typing a word
 */

#pragma once
#include "keycodes.h"

bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);
void process_caps_word(uint16_t keycode, const keyrecord_t *record);
