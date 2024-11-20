/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "version.h"

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_HUE 0
#define RGB_MATRIX_STARTUP_SAT 0
#define RGB_MATRIX_STARTUP_VAL 0

enum layers {
    BASE,  // default layer
    NAV,  // navidation
    NUM,  // numbers
    CTRL
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// COMBOS
const uint16_t PROGMEM custom_esc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qmk_boot[] = {KC_R, KC_TAB, COMBO_END};
const uint16_t PROGMEM arr_panic[] = {KC_UP, KC_DOWN, COMBO_END};

combo_t                key_combos[] = {
    COMBO(custom_esc, KC_ESC),
    COMBO(qmk_boot, QK_BOOT),
    COMBO(arr_panic, TO(BASE)),
};

#define KC_VIM_END S(KC_4)
#define KC_VIM_START S(KC_6)

#define KC_LESS_THAN LSFT(KC_COMMA)
#define KC_MORE_THAN LSFT(KC_DOT)

#define KC_BACKSPACE_WORD LALT(KC_BACKSPACE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRAVE,                  KC_1,            KC_2,                 KC_3,                 KC_4,                KC_5,    KC_LESS_THAN,             KC_MORE_THAN,         KC_6,               KC_7,               KC_8,             KC_9,            KC_0,             KC_BACKSPACE,
        KC_TAB,                    KC_Q,            KC_W,                 KC_E,                 KC_R,                KC_T,    KC_MINUS,                 KC_EQUAL,             KC_Y,               KC_U,               KC_I,             KC_O,            KC_P,             KC_MINUS,
        LT(NUM, KC_ESCAPE),                 KC_A,            KC_S,                 KC_D,                 KC_F,                KC_G,    KC_LEFT_BRACKET,          KC_RIGHT_BRACKET,     KC_H,               KC_J,               KC_K,             KC_L,            KC_SEMICOLON,     KC_QUOTE,
        KC_LSFT,                   KC_Z,            KC_X,                 KC_C,                 KC_V,                KC_B,                                                    KC_N,               KC_M,               KC_COMM,          KC_DOT,          KC_SLASH,         KC_BACKSLASH,
        KC_LEFT_CTRL,              KC_LEFT_GUI,     KC_LEFT_ALT,          KC_DOWN,              KC_UP,            SGUI(KC_4),                 KC_PRINT_SCREEN,                 KC_LEFT,            KC_RIGHT,           KC_LEFT_ALT,    KC_LEFT_GUI,       KC_LEFT_CTRL,
                                                                                       KC_SPC,  MO(NAV), _______,        _______,  MO(CTRL),  KC_ENT
    ),

    [NAV] = LAYOUT(
        KC_F12,        KC_F1,             KC_F2,               KC_F3,                 KC_F4,              KC_F5,            _______,             _______,          KC_F6,             KC_F7,                KC_F8,                KC_F9,                 KC_F10,              KC_F11,
        _______,       KC_ESCAPE,         _______,             _______,               _______,            _______,          _______,           _______,            _______,           KC_C,                 KC_V,                  KC_X,                 KC_Z,                _______,
        _______,       KC_LSFT,           KC_LEFT_ALT,         KC_LEFT_CTRL,           KC_LEFT_GUI,        _______,          _______,       _______,               KC_LEFT,           KC_DOWN,              KC_UP,                 KC_RIGHT,             _______,          _______,
        _______,       _______,           _______,             KC_PAGE_UP,             KC_PAGE_DOWN,            _______,                                           _______,           KC_BACKSPACE,         KC_BACKSPACE_WORD,     KC_TAB,               KC_DELETE,        _______,        
        _______,       _______,           _______,             _______,               _______,       _______,                                             _______,                    _______,         _______,                _______,            _______,              _______,
                                                                                             _______, _______, _______,                      _______, KC_TRANSPARENT, _______
    ),
    [NUM] = LAYOUT(
        KC_GRAVE,              LSFT(KC_F1),       LSFT(KC_F2),          LSFT(KC_F3),             LSFT(KC_F4),      LSFT(KC_F5),            _______,             _______,          LSFT(KC_F6),         LSFT(KC_F7),       LSFT(KC_F8),          LSFT(KC_F9),      LSFT(KC_F10),              _______,
        _______,               KC_BACKSLASH,      KC_QUOTE,             KC_COMMA,               KC_DOT,            _______,                _______,             _______,            _______,           KC_7,              KC_8,                 KC_9,             KC_DOT,                _______,
        _______,               KC_MINUS,          KC_EQUAL,             LSFT(KC_9),             LSFT(KC_0),           _______,                  _______,            _______,            _______,           KC_4,              KC_5,                 KC_6,             KC_COMM,          _______,
        KC_TRANSPARENT,        _______,           _______,              KC_LEFT_BRACKET,        KC_RIGHT_BRACKET,            _______,                                                          KC_0,           KC_1,              KC_2,                 KC_3,             KC_SLASH,        _______,        
        _______,               _______,           _______,             _______,               _______,       _______,                                             _______,                    _______,         _______,                _______,            _______,              _______,
                                                                                             _______, _______, _______,                      _______, _______, _______
    ),
    [CTRL] = LAYOUT(
        KC_F12,                  KC_F1,           KC_F2,                KC_F3,                KC_F4,               KC_F5,   _______,                  _______,          KC_F6,             KC_F7,                KC_F8,                KC_F9,                 KC_F10,              KC_F11,
        KC_TAB,                  KC_Q,            KC_W,                 KC_E,                 KC_R,                KC_T,    KC_MINUS,                 KC_PLUS,             KC_Y,               KC_U,               KC_I,             KC_O,            KC_P,             KC_QUOTE,
        TO(BASE),                KC_A,            KC_S,                 KC_D,                 KC_F,                KC_G,    KC_LEFT_BRACKET,          KC_RIGHT_BRACKET,     KC_H,               KC_J,               KC_K,             KC_L,            KC_SEMICOLON,     KC_ENT,
        _______,                 KC_Z,            KC_X,                 KC_C,                 KC_V,                KC_B,                                                    KC_N,               KC_M,               KC_COMM,          KC_DOT,          KC_SLASH,         KC_BACKSLASH,
        _______,                 KC_LEFT_GUI,     KC_LEFT_ALT,          KC_DOWN,              KC_UP,                        KC_NO,                 KC_NO,                 KC_LEFT,            KC_RIGHT,           KC_LEFT_ALT,    KC_LEFT_GUI,       KC_LEFT_CTRL,
                                                                                                      KC_SPC,  KC_KB_VOLUME_DOWN, _______,        _______,  KC_KB_VOLUME_UP,  KC_LSFT
    ),
};

bool ctrl_layer_cmd_active = false;
bool ctrl_layer_alt_active = false;
bool ctrl_layer_shift_active = false;

//Layer change hook to reset states and clear modifiers
// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Reset modifier states when leaving CTRL layer
//     if (get_highest_layer(state) != CTRL) {
//         cleanup_ctrl_layer_modifier();
        
//     }
//     return state;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Get the current active layer
    uint8_t current_layer = get_highest_layer(layer_state);

    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }

    if (current_layer != CTRL) {
        return true;
    }

    if (record->event.pressed) {
            if (IS_LAYER_ON(CTRL)) {
                switch (keycode) {
                    case KC_TAB: // Use COMMAND modifier for the next key press
                        ctrl_layer_cmd_active = !ctrl_layer_cmd_active;
                        return false;

                    case KC_SPACE: // Toggle ALT modifier
                        ctrl_layer_alt_active = !ctrl_layer_alt_active;
                        return false;

                    case KC_LSFT: // Toggle SHIFT modifier
                    case KC_RSFT:
                        ctrl_layer_shift_active = !ctrl_layer_shift_active;
                        return false;

                    default:
                        // Apply modifiers only for the current key press
                        if (ctrl_layer_cmd_active) {
                            register_mods(MOD_BIT(KC_LGUI)); // COMMAND
                        } else {
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

                        // Reset one-time modifiers (like COMMAND)
                        return false;
                }
            }
        }

        return true; // Process the keycode normally in other layers
}




#define DRIVER_LED_TOTAL 72
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();

  // ML_LED_3(!get_autoshift_state());
}



// Helper macro to convert hex to RGB
#define HEX_TO_RGB(hex) \
    { ((hex) >> 16) & 0xFF, ((hex) >> 8) & 0xFF, (hex) & 0xFF }

// Color definitions using hex values
#define COLOR_NORMAL    HEX_TO_RGB(0x001f54)    // Example using your hex code
#define COLOR_TRANSPARENT_OTHER HEX_TO_RGB(0x161A14)

#define COLOR_MODIFIER  HEX_TO_RGB(0xfcab10)    // orange
#define COLOR_ARROW    HEX_TO_RGB(0xaf3e4d)     // redwood
#define COLOR_SYMBOL   HEX_TO_RGB(0x4cb944)     // dark pastel green
#define COLOR_ESC      HEX_TO_RGB(0xdb222a)     // red
#define COLOR_SPACE    HEX_TO_RGB(0xf2c841)     // yellow
#define COLOR_DELETE   HEX_TO_RGB(0xef1d31)     // bright red
#define COLOR_NUMBER   HEX_TO_RGB(0x998fc2)     // grayish purple
#define COLOR_FUNCTION HEX_TO_RGB(0xb5179e)     // bright purple
#define COLOR_ALPHA    HEX_TO_RGB(0x1f271b)     // Black olive

#define COLOR_CTRL_ALPHA    HEX_TO_RGB(0xFF801F)     // orange
#define COLOR_CTRL_SHIFT_ALPHA    HEX_TO_RGB(0x1F39FF)     // purple
#define COLOR_CTRL_ALT_ALPHA    HEX_TO_RGB(0xFFCB1F)     // orange
#define COLOR_CTRL_ALT_SHIFT_ALPHA    HEX_TO_RGB(0xFF1F7C)     // red

#define COLOR_CMD_ALPHA    HEX_TO_RGB(0xFF801F)     // light blue
#define COLOR_CMD_SHIFT_ALPHA    HEX_TO_RGB(0x1F66FF)     // light purple
#define COLOR_CMD_ALT_ALPHA    HEX_TO_RGB(0xBFFF1F)     // brigh green
#define COLOR_CMD_ALT_SHIFT_ALPHA    HEX_TO_RGB(0xFF1F7C)     // bright purple


#define COLOR_LAYER    HEX_TO_RGB(0x6130ff)     // bright purple
#define COLOR_HOMEROW  HEX_TO_RGB(0xfffb46)     // bright yellow

#define COLOR_SHIFT    HEX_TO_RGB(0x1F39FF)     // purple
#define COLOR_ALT      HEX_TO_RGB(0xFFCB1F)     // orangish yellow
#define COLOR_CTRL     HEX_TO_RGB(0xFF801F)     // orange
#define COLOR_GUI      HEX_TO_RGB(0x1FE1FF)     // light blue

// Helper function to check key types
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

// Helper function to create RGB color from hex
static inline rgb_color hex_to_rgb(uint32_t hex) {
    return (rgb_color)HEX_TO_RGB(hex);
}

rgb_color get_key_color(uint16_t keycode, uint8_t row, uint8_t col, uint8_t layer) {
    // Check for transparent keys
    if (keycode == KC_TRANSPARENT) {
        if (layer == BASE) {
            // No color (off) for transparent keys in base layer
            return (rgb_color){0, 0, 0};
        } else {
            // Dark color for transparent keys in other layers
            return (rgb_color)COLOR_TRANSPARENT_OTHER;
        }
    }

    // Check for arrow keys in any layer first
    switch (keycode) {
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
            return (rgb_color)COLOR_ARROW;
    }

    if (keycode >= KC_F1 && keycode <= KC_F12) {
        return (rgb_color)COLOR_FUNCTION;
    }
    // Handle shift keys and modifiers
    if (keycode == KC_LSFT || keycode == KC_RSFT || 
        (IS_QK_MOD_TAP(keycode) && ((QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT))) {
        return (rgb_color)COLOR_SHIFT;
    }

    if (keycode == KC_LEFT_ALT || keycode == KC_RIGHT_ALT || 
        (IS_QK_MOD_TAP(keycode) && ((QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT))) {
        return (rgb_color)COLOR_ALT;
    }

    if (keycode == KC_LEFT_CTRL || keycode == KC_RIGHT_CTRL || 
        (IS_QK_MOD_TAP(keycode) && ((QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT))) {
        return (rgb_color)COLOR_CTRL;
    }

    if (keycode == KC_LEFT_GUI || keycode == KC_LEFT_GUI || 
        (IS_QK_MOD_TAP(keycode) && ((QK_MOD_TAP_GET_MODS(keycode) & MOD_MASK_SHIFT) == MOD_MASK_SHIFT))) {
        return (rgb_color)COLOR_GUI;
    }

    // Handle other modifiers
    if (IS_QK_MOD_TAP(keycode) || IS_MODIFIER_KEYCODE(keycode)) {
        return (rgb_color)COLOR_MODIFIER;
    }

    // Handle basic keycodes
    if (IS_QK_BASIC(keycode)) {
        switch (keycode) {
            case KC_TAB:
            case KC_SPC:
                return (rgb_color)COLOR_SPACE;
            case KC_ESC:
                return (rgb_color)COLOR_ESC;
            case KC_BSPC:
            case KC_DEL:
                return (rgb_color)COLOR_DELETE;
            case KC_GRAVE:
            case KC_LT:    // <
            case KC_GT:    // >
                return (rgb_color)COLOR_SYMBOL;
            default:
                // Check number range
                if (keycode >= KC_1 && keycode <= KC_0) {
                    return (rgb_color)COLOR_NUMBER;
                }
                // Check letter range and home row
                if (keycode >= KC_A && keycode <= KC_Z) {
                    // if (row == 2 && (col >= 1 && col <= 10)) {
                    //     return (rgb_color)COLOR_HOMEROW;
                    // }
                    switch (layer) {
                        case CTRL:
                            if (ctrl_layer_cmd_active && ctrl_layer_alt_active && ctrl_layer_shift_active) {
                                return (rgb_color) COLOR_CMD_ALT_SHIFT_ALPHA;
                            }
                            else if (ctrl_layer_cmd_active && ctrl_layer_shift_active) {
                                return (rgb_color) COLOR_CMD_SHIFT_ALPHA;
                            }
                            else if (ctrl_layer_cmd_active && ctrl_layer_alt_active) {
                                return (rgb_color) COLOR_CMD_ALT_ALPHA;
                            }
                            else if (ctrl_layer_cmd_active) {
                                return (rgb_color) COLOR_CMD_ALPHA;
                            }
                            else if (!ctrl_layer_cmd_active && ctrl_layer_alt_active && ctrl_layer_shift_active) {
                                return (rgb_color) COLOR_CTRL_ALT_SHIFT_ALPHA;
                            }
                            else if (!ctrl_layer_cmd_active && ctrl_layer_shift_active) {
                                return (rgb_color) COLOR_CTRL_SHIFT_ALPHA;
                            }
                            else if (!ctrl_layer_cmd_active && ctrl_layer_alt_active) {
                                return (rgb_color) COLOR_CTRL_ALT_ALPHA;
                            }
                            else if (!ctrl_layer_cmd_active) {
                                return (rgb_color) COLOR_CTRL_ALPHA;
                            }
                            break;
                        default:
                            return (rgb_color)COLOR_ALPHA;
                    }

                }
                // Check symbols
                switch (keycode) {
                    case KC_MINS:
                    case KC_EQL:
                    case KC_LBRC:
                    case KC_RBRC:
                    case KC_BSLS:
                    case KC_SCLN:
                    case KC_QUOT:
                    case KC_COMM:
                    case KC_DOT:
                    case KC_SLSH:
                        return (rgb_color)COLOR_SYMBOL;
                }
        }
    }

    // Handle layer changes
    if (IS_QK_LAYER_TAP(keycode) || IS_QK_TO(keycode) || IS_QK_MOMENTARY(keycode)) {
        return (rgb_color)COLOR_LAYER;
    }

    // Check layer-specific colors

    // Default color for unmatched keys
    return (rgb_color)COLOR_NORMAL;
}

// Replace the existing rgb_matrix_indicators_user function
bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) { return false; }
    
    uint8_t current_layer = get_highest_layer(layer_state);
    
    // Iterate through all keys
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            // Skip if this position doesn't have an LED
            if (index >= DRIVER_LED_TOTAL) continue;
            
            uint16_t keycode = keymap_key_to_keycode(current_layer, (keypos_t){.row = row, .col = col});
            rgb_color color = get_key_color(keycode, row, col, current_layer);
            
            rgb_matrix_set_color(index, color.r, color.g, color.b);
        }
    }
    
    return false;
}
