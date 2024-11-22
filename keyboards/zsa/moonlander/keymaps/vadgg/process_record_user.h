#pragma once

#include "helpers.h"
#include "processors/functions_record_user.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }

    if (is_on_mod_selector_layer()) {
        if (record->event.pressed) {
                switch (keycode) {
                    case KC_LEFT_CTRL:
                    case KC_RIGHT_CTRL:
                        ctrl_layer_ctrl_active = !ctrl_layer_ctrl_active;
                        return false;

                    case KC_LEFT_GUI:
                    case KC_RIGHT_GUI:
                        ctrl_layer_cmd_active = !ctrl_layer_cmd_active;
                        return false;

                    case KC_LEFT_ALT:
                    case KC_RIGHT_ALT:
                        ctrl_layer_alt_active = !ctrl_layer_alt_active;
                        return false;

                    case KC_LSFT: // Toggle SHIFT modifier
                    case KC_RSFT:
                        ctrl_layer_shift_active = !ctrl_layer_shift_active;
                        return false;

                    default:
                        return true;
                }
            }
    } 
    
    if (is_custom_mod_set() && is_on_moddable_layer()) {
        if (record->event.pressed) {
            if (!is_custom_mod_on()) {
                return true;
            }

            if (!is_moddable_key(keycode)) {
                return true;
            }

            // Apply modifiers only for the current key press
            if (ctrl_layer_cmd_active) {
                register_mods(MOD_BIT(KC_LGUI)); // COMMAND
            } 

            if (ctrl_layer_ctrl_active) {
                register_mods(MOD_BIT(KC_LCTL)); // CTRL
            }

            if (ctrl_layer_alt_active) {
                register_mods(MOD_BIT(KC_LALT)); // ALT
            }

            if (ctrl_layer_shift_active) {
                register_mods(MOD_BIT(KC_LSFT)); // SHIFT
            }

            // Send the key with the current modifiers
            tap_code16(keycode);

            // Unregister all modifiers after the key press
            clear_mods();

            return false;
        }
    }

    return true; // Process the keycode normally in other layers
}


// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MY_CTRL_ACTIVATE:
//             return TAPPING_TERM + 1750;
//         default:
//             return TAPPING_TERM;
//     }
// }

