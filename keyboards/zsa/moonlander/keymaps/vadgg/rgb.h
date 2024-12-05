#pragma once

#include <stdint.h>

#include "combos.h"

static inline uint8_t min(uint8_t a, float b) {
    return (b < a) ? (uint8_t)b : a;
}

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
#define LEVEL_0_BRIGHTNESS 20
#define BASE_BRIGHTNESS 40
#define LEVEL_1_BRIGHTNESS 60

#define COLOR_OFF HSB(0, 0, 0)

#define COLOR_MODIFIER  HSB(40, 93, LEVEL_0_BRIGHTNESS)     // Orange

#define COLOR_LAYER    HSB(255, 81, 100)     // Bright purple

#define COLOR_SHIFT    HSB(200, 100, 100)     // Blue
#define COLOR_ALT      HSB(125, 100, 100)      // Orangish yellow
#define COLOR_CTRL     HSB(350, 100, 100)      // Orange
#define COLOR_GUI      HSB(50, 100, 100)     // Light blue

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

hsb_color get_mod_color_based_on_mod_status(bool is_mod_state, bool is_toggled_on, hsb_color color) {
    if (is_on_mod_selector_layer()) {
        return is_toggled_on ?(hsb_color){color.h, color.s, 100} :(hsb_color){color.h, color.s, 5};
    }

    if (!is_mod_state) {
        return (hsb_color){color.h, color.s, 30};
    }

    return is_toggled_on ?(hsb_color){color.h, color.s, 100} :(hsb_color){color.h, color.s, 5};
}


hsb_color get_mod_combo_color(bool is_active, bool is_pressed, hsb_color mod_color, hsb_color default_color) {
    if (!is_active) {
        return default_color;
    }

    return is_pressed ? (hsb_color){mod_color.h, mod_color.s, 100} : (hsb_color){mod_color.h, mod_color.s, 30};
}



hsb_color reduce_brightness(hsb_color color, float percent_brightness) {
    return (hsb_color){color.h, color.s, color.b * percent_brightness};
}
// Helper function to blend HSB colors
hsb_color blend_hsb_colors(hsb_color base_color, hsb_color mod_color, float percent_hue) {
    // Average the hues
    uint16_t avg_hue = (base_color.h * (percent_hue) + mod_color.h * (1 - percent_hue));
    
    // Keep base color's saturation, but increase brightness
    uint8_t blended_saturation = base_color.s;
    uint8_t blended_brightness = min(255, base_color.b * 2); // 50% brighter
    
    return (hsb_color){
        .h = (uint8_t)avg_hue,
        .s = blended_saturation,
        .b = blended_brightness
    };
}



// Function to get the base color for a key without mod blending
hsb_color get_base_key_color(uint16_t keycode, uint8_t layer) {
    hsb_color alpha_color = (hsb_color)HSB(180, 30, LEVEL_0_BRIGHTNESS);
    switch(keycode) {
        case KC_S:
            if (is_left_ctrl_alt_pressed()) {
                return get_mod_combo_color(true, is_left_ctrl_alt_pressed(), (hsb_color)COLOR_CTRL, alpha_color);
            } else {
                return get_mod_combo_color(true, is_left_ctrl_pressed(), (hsb_color)COLOR_CTRL, alpha_color);
            }
        case KC_D:
            return get_mod_combo_color(true, is_left_ctrl_pressed(), (hsb_color)COLOR_CTRL, alpha_color);
        case KC_F:
            if (!is_left_ctrl_alt_pressed()) {
                return get_mod_combo_color(is_left_ctrl_pressed(), is_left_ctrl_shift_pressed(), (hsb_color)COLOR_SHIFT, reduce_brightness((hsb_color)COLOR_SHIFT, 0.05));
            } else {
                return alpha_color;
            }
            
        case KC_K:
        case KC_J:
            return get_mod_combo_color(true, is_right_ctrl_pressed(), (hsb_color)COLOR_CTRL, alpha_color);
        case KC_H:
            return get_mod_combo_color(is_right_ctrl_pressed(), is_right_ctrl_shift_pressed(), (hsb_color)COLOR_SHIFT, reduce_brightness((hsb_color)COLOR_SHIFT, 0.05));

        case KC_C:
            if (is_left_ctrl_alt_pressed()) {
                return get_mod_combo_color(true, is_left_ctrl_alt_pressed(), (hsb_color)COLOR_ALT, alpha_color);
            } else {
                return get_mod_combo_color(true, is_left_alt_pressed(), (hsb_color)COLOR_ALT, alpha_color);
            }
        case KC_V:
            return get_mod_combo_color(true, is_left_alt_pressed(), (hsb_color)COLOR_ALT, alpha_color);
        case KC_B:
            if (!is_left_ctrl_alt_pressed()) {
                return get_mod_combo_color(is_left_alt_pressed(), is_left_alt_shift_pressed(), (hsb_color)COLOR_SHIFT, reduce_brightness((hsb_color)COLOR_SHIFT, 0.05));
            } else {
                return alpha_color;
            }
        case KC_COMM:
        case KC_M:
            return get_mod_combo_color(true, is_right_alt_pressed(), (hsb_color)COLOR_ALT, alpha_color);
        case KC_N:
            return get_mod_combo_color(is_right_alt_pressed(), is_right_alt_shift_pressed(), (hsb_color)COLOR_SHIFT, reduce_brightness((hsb_color)COLOR_SHIFT, 0.05));

        case KC_O:
        case KC_I:
            return (hsb_color)HSB(0, 80, BASE_BRIGHTNESS);
        case KC_P:
            return (hsb_color)HSB(0, 80, LEVEL_0_BRIGHTNESS);
    }

    switch (keycode) {
        case KC_A ... KC_Z:
            return alpha_color;
        case KC_1 ... KC_0:
            return (hsb_color)HSB(130, 90, BASE_BRIGHTNESS);
        case KC_F1 ... KC_F12:
            return (hsb_color)HSB(170, 90, LEVEL_1_BRIGHTNESS);
        case DU_1F1:
        case DU_2F2:
        case DU_3F3:
        case DU_4F4:
        case DU_5F5:
        case DU_6F6:
        case DU_7F7:
        case DU_8F8:
        case DU_9F9:
        case DU_0F10:
            return (hsb_color)HSB(150, 70, LEVEL_1_BRIGHTNESS);
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
            return (hsb_color)HSB(35, 80, BASE_BRIGHTNESS);
        case KC_TAB:
            return (hsb_color)HSB(70, 50, BASE_BRIGHTNESS);
        case KC_SPC:
            return (hsb_color)HSB(80, 50, BASE_BRIGHTNESS);
        case KC_ESC:
            return (hsb_color)HSB(300, 80, BASE_BRIGHTNESS);
        case KC_ENT:
            return (hsb_color)HSB(150, 90, BASE_BRIGHTNESS);
        case KC_BSPC:
            return (hsb_color)HSB(0, 80, BASE_BRIGHTNESS);
        case KC_DEL:
            return (hsb_color)HSB(0, 100, BASE_BRIGHTNESS);
        case KC_GRAVE:
        case KC_LT:
        case KC_GT:
        case KC_BSLS:
        case KC_SCLN:
        case KC_QUOT:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
            return (hsb_color)HSB(180, 80, LEVEL_0_BRIGHTNESS);
        case KC_LEFT_PAREN: 
        case KC_RIGHT_PAREN: 
        case KC_LEFT_CURLY_BRACE: 
        case KC_RIGHT_CURLY_BRACE: 
        case KC_LEFT_BRACKET: 
        case KC_RIGHT_BRACKET: 
            return (hsb_color)HSB(280, 80, LEVEL_0_BRIGHTNESS);
        case KC_MINS:
        case KC_PLUS:
        case KC_EQUAL:
        case KC_KP_ASTERISK:
        case KC_PERCENT:
            return (hsb_color)HSB(325, 60, LEVEL_0_BRIGHTNESS);
        case HOME_D:
        case HOME_K:
            return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_shift_mod_on(), (hsb_color)COLOR_SHIFT);
        case HOME_S:
        case HOME_L:
            return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_alt_mod_on(), (hsb_color)COLOR_ALT);
        case HOME_SCLN:
        case HOME_A:
            return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_gui_mod_on(), (hsb_color)COLOR_GUI);
        case HOME_F:
        case HOME_J:
            return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_ctrl_mod_on(), (hsb_color)COLOR_CTRL);
        case KC_TRANSPARENT:
            if (layer == BASE) {
                return (hsb_color)COLOR_OFF;
            } else {
                return (hsb_color)HSB(90, 10, LEVEL_0_BRIGHTNESS);
            }
            return (hsb_color)HSB(280, 60, BASE_BRIGHTNESS);
        case KC_NO:
          return (hsb_color)COLOR_OFF;
        default:
            return (hsb_color)HSB(150, 10, BASE_BRIGHTNESS);
    }
}

// Function to get the final key color, potentially blending with modifier
hsb_color get_key_color(uint16_t keycode, uint8_t row, uint8_t col, uint8_t layer) {
    if (IS_QK_LAYER_TAP(keycode) || IS_QK_TO(keycode) || IS_QK_MOMENTARY(keycode)) {
        return (hsb_color)COLOR_LAYER;
    }

    if (is_modifier_key(keycode)) {
        switch (keycode) {
            case KC_LEFT_ALT:
            case KC_RIGHT_ALT:
                return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_alt_mod_on(), (hsb_color)COLOR_ALT);
            case KC_LSFT:
            case KC_RSFT:
                return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_shift_mod_on(), (hsb_color)COLOR_SHIFT);
            case KC_LEFT_GUI:
            case KC_RIGHT_GUI:
                return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_gui_mod_on(), (hsb_color)COLOR_GUI);
            case KC_LEFT_CTRL:
            case KC_RIGHT_CTRL:
                return get_mod_color_based_on_mod_status(is_custom_mod_on(), is_ctrl_mod_on(), (hsb_color)COLOR_CTRL);
            default:
                if (!is_on_mod_selector_layer()) {
                    return get_mod_color_based_on_mod_status(is_custom_mod_set(), false, (hsb_color)COLOR_MODIFIER);
                }
        }
    }

    if (is_on_mod_selector_layer()) {
        return (hsb_color)COLOR_OFF;
    }

    // Custom mod color blending logic
    if (is_custom_mod_on()) {
        hsb_color base_color = get_base_key_color(keycode, layer);
        hsb_color mod_color = (hsb_color){0};
        bool has_mod_color = false;

        // Check which modifier is on and set mod color accordingly
        if (is_alt_mod_on()) {
            mod_color = (hsb_color)COLOR_ALT;
            has_mod_color = true;
        } else if (is_shift_mod_on()) {
            mod_color = (hsb_color)COLOR_SHIFT;
            has_mod_color = true;
        } else if (is_ctrl_mod_on()) {
            mod_color = (hsb_color)COLOR_CTRL;
            has_mod_color = true;
        } else if (is_gui_mod_on()) {
            mod_color = (hsb_color)COLOR_GUI;
            has_mod_color = true;
        }

        // If a modifier is active, blend the colors
        if (has_mod_color) {
            return blend_hsb_colors(base_color, mod_color, 0.9);
        }
    }

    // Get base key color for all other cases
    return get_base_key_color(keycode, layer);
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



