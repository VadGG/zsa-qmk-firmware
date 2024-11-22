#pragma once

// Define custom keycodes
enum custom_keycodes {
    VRSN = SAFE_RANGE,
    MY_CUSTOM_MOD_TOGGLE,
    MY_CUSTOM_MOD_HOLD,
};


// Convenience macros
#define KC_VIM_END S(KC_4)
#define KC_VIM_START S(KC_6)
#define KC_LESS_THAN LSFT(KC_COMMA)
#define KC_MORE_THAN LSFT(KC_DOT)
#define KC_BACKSPACE_WORD LALT(KC_BACKSPACE)


enum layers {
    BASE,  // default layer
    NAV,  // navidation
    NUM,  // numbers
    _CUSTOM_MOD
};

