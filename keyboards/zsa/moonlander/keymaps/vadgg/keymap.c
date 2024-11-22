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
#include "keymap.h"
#include "helpers.h"


// ------------- COMBO ---------------
const uint16_t PROGMEM custom_esc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qmk_boot[] = {KC_R, KC_TAB, COMBO_END};
const uint16_t PROGMEM arr_panic[] = {KC_UP, KC_DOWN, COMBO_END};

combo_t                key_combos[] = {
    COMBO(custom_esc, KC_ESC),
    COMBO(qmk_boot, QK_BOOT),
    COMBO(arr_panic, TO(BASE)),
};
// ------------- END COMBO ---------------



#include "tap_dance.h"

// -----------------------------------
// -----------------------------------
#include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_GRAVE,                   KC_1,                      KC_2,                      KC_3,                      KC_4,                      KC_5,                       KC_LESS_THAN,             KC_MORE_THAN,              KC_6,                      KC_7,                      KC_8,                       KC_9,                     KC_0,                       KC_BACKSPACE,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_TAB,                    KC_Q,                      KC_W,                      KC_E,                      KC_R,                      KC_T,                       KC_MINUS,                 KC_EQUAL,                  KC_Y,                      KC_U,                      KC_I,                       KC_O,                     KC_P,                       KC_MINUS,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_ESCAPE,                 KC_A,                      KC_S,                      KC_D,                      KC_F,                      KC_G,                       KC_LEFT_BRACKET,          KC_RIGHT_BRACKET,          KC_H,                      KC_J,                      KC_K,                       KC_L,                     KC_SEMICOLON,               KC_QUOTE,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_LSFT,                   KC_Z,                      KC_X,                      KC_C,                      KC_V,                      KC_B,                                                                            KC_N,                      KC_M,                      KC_COMM,                    KC_DOT,                   KC_SLASH,                   KC_BACKSLASH,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_LEFT_CTRL,              KC_LEFT_GUI,               KC_LEFT_ALT,               KC_DOWN,                   KC_UP,                                                 SGUI(KC_4),               KC_PRINT_SCREEN,                                      KC_LEFT,                   KC_RIGHT,                   KC_LEFT_ALT,              KC_LEFT_GUI,                KC_LEFT_CTRL,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    MO(NAV),                    _______,                  TD(MY_CMOD),             MO(NAV),                   KC_ENT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),

    [NAV] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   KC_F1,                     KC_F2,                     KC_F3,                     KC_F4,                     KC_F5,                     _______,                   _______,                   KC_F6,                     KC_F7,                     KC_F8,                     KC_F9,                     KC_F10,                    KC_F11,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   KC_ESCAPE,                 _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   KC_C,                      KC_V,                      KC_X,                      KC_Z,                      KC_F12,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   KC_LSFT,                   KC_LEFT_ALT,               KC_LEFT_CTRL,              KC_LEFT_GUI,               _______,                   _______,                   _______,                   KC_LEFT,                   KC_DOWN,                   KC_UP,                     KC_RIGHT,                  _______,                   _______,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   KC_PAGE_UP,                KC_PAGE_DOWN,              _______,                                                                         _______,                   KC_BACKSPACE,              KC_BACKSPACE_WORD,         KC_TAB,                    KC_DELETE,                 _______,        
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                                              _______,                   _______,                                              _______,                   _______,                   _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                                        _______,         _______,         _______,                   _______,         KC_TRANSPARENT,         _______
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),
    [NUM] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_GRAVE,                  LSFT(KC_F1),               LSFT(KC_F2),               LSFT(KC_F3),               LSFT(KC_F4),               LSFT(KC_F5),               _______,                   _______,                   LSFT(KC_F6),               LSFT(KC_F7),               LSFT(KC_F8),               LSFT(KC_F9),               LSFT(KC_F10),              _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   KC_BACKSLASH,              KC_QUOTE,                  KC_COMMA,                  KC_DOT,                    _______,                   _______,                   _______,                   _______,                   KC_7,                      KC_8,                      KC_9,                      KC_DOT,                    _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   KC_MINUS,                  KC_EQUAL,                  LSFT(KC_9),                LSFT(KC_0),                _______,                   _______,                   _______,                   _______,                   KC_4,                      KC_5,                      KC_6,                      KC_COMM,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_TRANSPARENT,            _______,                   _______,                   KC_LEFT_BRACKET,           KC_RIGHT_BRACKET,          _______,                                                                         KC_0,                      KC_1,                      KC_2,                      KC_3,                      KC_SLASH,                  _______,        
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                  _______,                    _______,                                              _______,                   _______,                                              _______,                   _______,                   _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                                        _______,         _______,         _______,                   _______,         _______,         _______
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),
    [_CUSTOM_MOD] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   KC_F1,                     KC_F2,                     KC_F3,                     KC_F4,                     KC_F5,                     KC_NO,                     KC_NO,                     KC_F6,                     KC_F7,                     KC_F8,                     KC_F9,                     KC_F10,                    KC_F11,
     //|--------------    ---------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   KC_Q,                      KC_W,                      KC_E,                      KC_R,                      KC_T,                      KC_MINUS,                  KC_PLUS,                   KC_Y,                      KC_U,                      KC_I,                      KC_O,                      KC_P,                      KC_F12,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        TO(BASE),                  KC_LSFT,                   KC_LEFT_ALT,               KC_LEFT_CTRL,              KC_LEFT_GUI,               KC_G,                      KC_LEFT_BRACKET,           KC_RIGHT_BRACKET,          KC_H,                      KC_J,                      KC_K,                      KC_L,                      KC_SEMICOLON,              KC_LEFT_GUI,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_LSFT,                   KC_Z,                      KC_X,                      KC_C,                      KC_V,                      KC_B,                                                                            KC_N,                      KC_M,                      KC_COMM,                   KC_DOT,                    KC_SLASH,                  KC_BACKSLASH,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_LEFT_CTRL,              KC_LEFT_GUI,               KC_LEFT_ALT,               KC_DOWN,                   KC_UP,                                                KC_NO,                     KC_NO,                                                KC_LEFT,                   KC_RIGHT,                  KC_LEFT_ALT,               KC_LEFT_GUI,               KC_LEFT_CTRL,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                               KC_SPC,         KC_KB_VOLUME_DOWN,         KC_NO,                     KC_NO,         KC_KB_VOLUME_UP,         KC_LSFT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

// Helper struct for HSB colors
typedef struct {
    uint8_t h; // 0-255 (0-360 degrees)
    uint8_t s; // 0-255 (0-100%)
    uint8_t b; // 0-255 (0-100%)
} hsb_color;

// Helper structs for color types
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_color;

// Helper macro to define HSB colors - h: 0-360, s: 0-100, b: 0-100
#define HSB(h, s, b) { \
    (uint8_t)((h) * 255 / 360), \
    (uint8_t)((s) * 255 / 100), \
    (uint8_t)((b) * 255 / 100) \
}

// Color definitions using HSB values
#define COLOR_NORMAL    HSB(220, 98, 33)    // Dark blue

#define COLOR_OFF HSB(0, 0, 0)

#define COLOR_TRANSPARENT_BASE HSB(0, 0, 0)
#define COLOR_TRANSPARENT_OTHER HSB(90, 18, 10)

#define COLOR_MODIFIER  HSB(40, 93, 99)     // Orange
#define COLOR_ARROW    HSB(353, 63, 69)     // Redwood
#define COLOR_SYMBOL   HSB(112, 63, 79)     // Dark pastel green
#define COLOR_ESC      HSB(358, 84, 86)     // Red
#define COLOR_SPACE    HSB(47, 73, 95)      // Yellow
#define COLOR_DELETE   HSB(355, 87, 94)     // Bright red

#define COLOR_NUMBER   HSB(252, 26, 76)     // Grayish purple
#define COLOR_FUNCTION HSB(311, 87, 71)     // Bright purple
#define COLOR_ALPHA    HSB(210, 27, 15)     // Black olive

#define COLOR_LAYER    HSB(255, 81, 100)     // Bright purple
#define COLOR_HOMEROW  HSB(59, 72, 100)      // Bright yellow

#define COLOR_SHIFT    HSB(230, 88, 100)     // Purple
#define COLOR_ALT      HSB(45, 88, 100)      // Orangish yellow
#define COLOR_CTRL     HSB(28, 88, 100)      // Orange
#define COLOR_GUI      HSB(190, 88, 100)     // Light blue

#define COLOR_UNKNOWN      HSB(0, 0, 100)     // White


// Helper function for HSB to RGB conversion
static inline rgb_color hsb_to_rgb(hsb_color hsb) {
    rgb_color rgb = {0, 0, 0};
    
    uint8_t region, remainder, p, q, t;
    
    if (hsb.s == 0) {
        rgb.r = rgb.g = rgb.b = hsb.b;
        return rgb;
    }
    
    region = hsb.h / 43;
    remainder = (hsb.h - (region * 43)) * 6; 
    
    p = (hsb.b * (255 - hsb.s)) >> 8;
    q = (hsb.b * (255 - ((hsb.s * remainder) >> 8))) >> 8;
    t = (hsb.b * (255 - ((hsb.s * (255 - remainder)) >> 8))) >> 8;
    
    switch (region) {
        case 0:
            rgb.r = hsb.b; rgb.g = t; rgb.b = p;
            break;
        case 1:
            rgb.r = q; rgb.g = hsb.b; rgb.b = p;
            break;
        case 2:
            rgb.r = p; rgb.g = hsb.b; rgb.b = t;
            break;
        case 3:
            rgb.r = p; rgb.g = q; rgb.b = hsb.b;
            break;
        case 4:
            rgb.r = t; rgb.g = p; rgb.b = hsb.b;
            break;
        default:
            rgb.r = hsb.b; rgb.g = p; rgb.b = q;
            break;
    }
    
    return rgb;
}

hsb_color get_color_based_on_mod_status(bool is_mod_state, bool is_toggled_on, hsb_color color) {
    if (is_on_mod_selector_layer()) {
        return is_toggled_on ?(hsb_color){color.h, color.s, 100} :(hsb_color){color.h, color.s, 5};
    }

    if (!is_mod_state) {
        return (hsb_color){color.h, color.s, 30};
    }

    return is_toggled_on ?(hsb_color){color.h, color.s, 100} :(hsb_color){color.h, color.s, 5};
}

hsb_color get_key_color(uint16_t keycode, uint8_t row, uint8_t col, uint8_t layer) {
    // Check for transparent keys
    if (keycode == KC_TRANSPARENT) {
        if (layer == BASE) {
            return (hsb_color)COLOR_TRANSPARENT_BASE;
        } else {
            return (hsb_color)COLOR_TRANSPARENT_OTHER;
        }
    }

    if (IS_QK_LAYER_TAP(keycode) || IS_QK_TO(keycode) || IS_QK_MOMENTARY(keycode)) {
        return (hsb_color)COLOR_LAYER;
    }

    if (is_modifier_key(keycode)) {
        switch (keycode) {
            case KC_LEFT_ALT:
            case KC_RIGHT_ALT:
                return get_color_based_on_mod_status(is_custom_mod_on(), is_alt_mod_on(), (hsb_color)COLOR_ALT);
            case KC_LSFT:
            case KC_RSFT:
                return get_color_based_on_mod_status(is_custom_mod_on(), is_shift_mod_on(), (hsb_color)COLOR_SHIFT);
            case KC_LEFT_GUI:
            case KC_RIGHT_GUI:
                return get_color_based_on_mod_status(is_custom_mod_on(), is_gui_mod_on(), (hsb_color)COLOR_GUI);
            case KC_LEFT_CTRL:
            case KC_RIGHT_CTRL:
                return get_color_based_on_mod_status(is_custom_mod_on(), is_ctrl_mod_on(), (hsb_color)COLOR_CTRL);
            default:
                if (!is_on_mod_selector_layer()) {
                    return get_color_based_on_mod_status(is_custom_mod_set(), false, (hsb_color)COLOR_MODIFIER);
                }
        }
    }     

    if (is_on_mod_selector_layer()) {
        return (hsb_color)COLOR_OFF;
    }

    if (keycode >= KC_A && keycode <= KC_Z) {
        return (hsb_color)COLOR_ALPHA;
    }

    if (keycode >= KC_1 && keycode <= KC_0) {
        return (hsb_color)COLOR_NUMBER;
    }

    if (keycode >= KC_F1 && keycode <= KC_F12) {
        return (hsb_color)COLOR_FUNCTION;
    }

    switch (keycode) {
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
            return (hsb_color)COLOR_ARROW;
        case KC_TAB:
        case KC_SPC:
            return (hsb_color)COLOR_SPACE;
        case KC_ESC:
            return (hsb_color)COLOR_ESC;
        case KC_BSPC:
        case KC_DEL:
            return (hsb_color)COLOR_DELETE;
        case KC_GRAVE:
        case KC_LT:
        case KC_GT:
            return (hsb_color)COLOR_SYMBOL;
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
            return (hsb_color)COLOR_SYMBOL;
        default:
            return (hsb_color)COLOR_UNKNOWN;
    }


    return (hsb_color)COLOR_NORMAL;
}

bool rgb_matrix_indicators_user(void) {
    if (keyboard_config.disable_layer_led) { return false; }
    
    uint8_t current_layer = get_highest_layer(layer_state);
    
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index >= DRIVER_LED_TOTAL) continue;
            
            uint16_t keycode = keymap_key_to_keycode(current_layer, (keypos_t){.row = row, .col = col});
            hsb_color hsb = get_key_color(keycode, row, col, current_layer);
            rgb_color rgb = hsb_to_rgb(hsb);
            
            rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
    }
    
    return false;
}










// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // tap_code16(MY_CUSTOM_MOD_TOGGLE);
            ctrl_key_toggle = !ctrl_key_toggle;
            break;
        case TD_SINGLE_HOLD:
            // layer_on(_CUSTOM_MOD);
            ctrl_key_held = true;
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_CUSTOM_MOD)) {
                // If already set, then switch it off
                layer_off(_CUSTOM_MOD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_CUSTOM_MOD);
            }
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        // layer_off(_CUSTOM_MOD);
        ctrl_key_held = false;
    } else if (ql_tap_state.state == TD_DOUBLE_TAP) {
        layer_off(_CUSTOM_MOD);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [MY_CMOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 175;
        default:
            return TAPPING_TERM;
    }
}
