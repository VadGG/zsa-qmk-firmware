#pragma once

#include QMK_KEYBOARD_H

// Define custom keycodes
enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// Convenience macros
#define KC_VIM_END S(KC_4)
#define KC_VIM_START S(KC_6)
#define KC_LESS_THAN LSFT(KC_COMMA)
#define KC_MORE_THAN LSFT(KC_DOT)
#define KC_BACKSPACE_WORD LALT(KC_BACKSPACE)
