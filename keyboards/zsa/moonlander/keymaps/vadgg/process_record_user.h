#pragma once

#include "helpers.h"
#include "processors/functions_record_user.h"

#include "combos.h"


void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
  if (!process_modifider_combo_event(combo_index, pressed)) {
      return;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_combo_code_press(keycode, record)) { return false; }
    
    switch(keycode) {
        case OPEN_BRACKET:
            if (record->event.pressed) {
                tap_code16(KC_LEFT_BRACKET);
                tap_code16(KC_RIGHT_BRACKET);
                tap_code16(KC_LEFT);
                // send_string("[]");
                return false;
            }
            break;
         // triple_tap(KC_GRAVE);
        case TO_NUM_LAYER:
            if (record->event.pressed) {
                active_num_layer();
            }
            return true;
    }

    if (is_on_num_layer_active()) {
        switch(keycode) {
            case KC_BACKSPACE:
            case KC_1:
            case KC_2:
            case KC_3:
            case KC_4:
            case KC_5:
            case KC_6:
            case KC_7:
            case KC_8:
            case KC_9:
            case KC_0:
            case KC_COMM:
            case KC_DOT:
            case KC_EQUAL:
            case KC_UNDERSCORE:
            case KC_PERCENT:
            case KC_ASTERISK:
            case KC_EXCLAIM:
            case KC_MINUS:
            case KC_PLUS:
            case KC_NO:
                return true;
            default:
                if (record->event.pressed) {
                    tap_code16(keycode);
                }
                deactivate_num_layer();
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

