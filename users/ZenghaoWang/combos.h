#pragma once

#include "quantum.h"
#include "process_combo.h"

// combos must always be tapped, not held.
bool get_combo_must_tap(uint16_t index, combo_t *combo) { return true; }

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    if (combo->keys[0] == LT_BSPC_NUMPAD) {
        return COMBO_TERM + 50;
    }

    return COMBO_TERM;
}
