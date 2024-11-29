#pragma once

// Define custom keycodes
enum custom_keycodes {
    VRSN = SAFE_RANGE,
    MY_CUSTOM_MOD_TOGGLE,
    MY_CUSTOM_MOD_HOLD,
    TO_NUM_LAYER,
    IN_GRAVE,

    OPEN_BRACKET
};


// Convenience macros
#define KC_VIM_END S(KC_4)
#define KC_VIM_START S(KC_6)
#define KC_LESS_THAN LSFT(KC_COMMA)
#define KC_MORE_THAN LSFT(KC_DOT)
#define KC_BACKSPACE_WORD LALT(KC_BACKSPACE)

#define TO_BASE TO(BASE)

#define DU_1F1 TD(TD_1F1)
#define DU_2F2 TD(TD_2F2)
#define DU_3F3 TD(TD_3F3)
#define DU_4F4 TD(TD_4F4)
#define DU_5F5 TD(TD_5F5)
#define DU_6F6 TD(TD_6F6)
#define DU_7F7 TD(TD_7F7)
#define DU_8F8 TD(TD_8F8)
#define DU_9F9 TD(TD_9F9)
#define DU_0F10 TD(TD_0F10)

enum layers {
    BASE,  // default layer
    _LMOD,
    _RMOD,
    _NUM,
    NAV,  // navidation
    NUM,  // numbers
    _CUSTOM_MOD
};

