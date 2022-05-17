#include "layers.h"
#include "action_layer.h"
#include "process_combo.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case Z_GAMING:
            combo_disable();
            break;
        default:
            combo_enable();
            break;
    }
    return layer_state_set_keymap(state);
}
