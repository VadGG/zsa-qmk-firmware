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
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// COMBOS
const uint16_t PROGMEM custom_esc[] = {KC_J, KC_K, COMBO_END};

combo_t                key_combos[] = {
    COMBO(custom_esc, KC_ESC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRAVE,       KC_1,            KC_2,          KC_3,         KC_4,    KC_5,    LSFT(KC_COMMA),           LSFT(KC_DOT),      KC_6,       KC_7,       KC_8,             KC_9,            KC_0,             KC_BACKSPACE,
        KC_TAB,         KC_Q,            KC_W,          KC_E,         KC_R,    KC_T,    KC_MINUS,                 KC_EQUAL,          KC_Y,       KC_U,       KC_I,             KC_O,            KC_P,             KC_MINUS,
        KC_ESCAPE,      KC_A,            KC_S,          KC_D,         KC_F,    KC_G,    KC_LEFT_BRACKET,          KC_RIGHT_BRACKET,  KC_H,       KC_J,       KC_K,             KC_L,            KC_SEMICOLON,     KC_QUOTE,
        KC_LSFT,        KC_Z,            KC_X,          KC_C,         KC_V,    KC_B,                                                 KC_N,       KC_M,       KC_COMM,          KC_DOT,          KC_SLASH,         KC_BACKSLASH,
        KC_LEFT_CTRL,   KC_LEFT_GUI,     KC_LEFT_ALT,   KC_DOWN,      KC_UP,    SGUI(KC_4),                 RCTL_T(KC_ESC),                  KC_LEFT,   KC_RIGHT,          KC_LEFT_ALT,    KC_LEFT_GUI,       KC_LEFT_CTRL,
                                                                           KC_SPC,  KC_LSFT, KC_NO,        KC_NO,  KC_TAB,  KC_ENT
    ),

    [SYMB] = LAYOUT(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EE_CLR,  _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [MDIA] = LAYOUT(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}


#define DRIVER_LED_TOTAL 72
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();

  // ML_LED_3(!get_autoshift_state());
}


#define NORMAL_COLOR {178, 219, 191}    // light green
#define SHIFT_COLOR {95, 237, 102}    // green
#define MODIFIER_COLOR {252, 171, 16}  // orange
#define ARROW_COLOR {0, 145, 173}      // blue

#define SYMBOLS_COLOR {76, 185, 68}      // dark pastel green

#define ESC_COLOR {219, 34, 42}      // red
#define SPACE_COLOR {242, 200, 65}      // yellow
#define DEL_COLOR {239, 29, 49}      // bright red

#define NUM_COLOR {140, 162, 250}      // light purple
#define ALPHA_COLOR {31, 39, 27}    // Black olive

#define HOMEROW_MODS_COLOR { 255, 251, 70 } // bright yellow

#define LAYER_SWITCH_COLOR { 97, 48, 255 } // bright purple


#define TEST_COLOR { 9, 232, 94 } // bright green

#define NO_COLOR { 0, 0, 0 } 

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
      [BASE] = {
           // TOP LEFT -----> Column 01 starting with `
           NUM_COLOR, SPACE_COLOR,  ESC_COLOR,  SHIFT_COLOR, MODIFIER_COLOR, 
           // TOP LEFT -----> Column 02 starting with 01 
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, MODIFIER_COLOR, 
           // TOP LEFT -----> Column 03 starting with 02 
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, MODIFIER_COLOR, 
           // TOP LEFT -----> Column 04 starting with 03
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, NUM_COLOR,
           // TOP LEFT -----> Column 05 starting with 04
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, NUM_COLOR, 
           // TOP LEFT -----> Column 06 starting with 05
           NUM_COLOR, ALPHA_COLOR,  ALPHA_COLOR,  ALPHA_COLOR, 
           // TOP LEFT -----> Column 07 starting with <
           SYMBOLS_COLOR, SYMBOLS_COLOR,  SYMBOLS_COLOR,

           //  Left Thumb Keys,                           // Special red button
           SPACE_COLOR, SHIFT_COLOR,  NO_COLOR,     NO_COLOR,

           // TOP RIGHT -----> Last column starting with backspace
           DEL_COLOR, SYMBOLS_COLOR,  SYMBOLS_COLOR,    SYMBOLS_COLOR, MODIFIER_COLOR, 
           // TOP RIGHT -----> Last column starting with 0
           NUM_COLOR, ALPHA_COLOR,  SYMBOLS_COLOR, SYMBOLS_COLOR,  MODIFIER_COLOR, 
           // TOP RIGHT -----> Last column starting with 9
           NUM_COLOR, ALPHA_COLOR, ALPHA_COLOR,     SYMBOLS_COLOR,  MODIFIER_COLOR, 
           // TOP RIGHT -----> Last column starting with 8
           NUM_COLOR, ALPHA_COLOR,  ALPHA_COLOR,     SYMBOLS_COLOR,  ARROW_COLOR ,
           // TOP RIGHT -----> Last column starting with 7
           NUM_COLOR, ALPHA_COLOR,  ALPHA_COLOR,     ALPHA_COLOR, ARROW_COLOR , 
           // TOP RIGHT -----> Last column starting with 6
           NUM_COLOR, ALPHA_COLOR,  ALPHA_COLOR, ALPHA_COLOR,  
           // TOP LEFT -----> Column 07 starting with >
           SYMBOLS_COLOR, SYMBOLS_COLOR,  SYMBOLS_COLOR,
           //  Right Thumb Keys,                           // Special red button
           SPACE_COLOR, LAYER_SWITCH_COLOR,  NO_COLOR,     NO_COLOR},
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };

    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );

    // HSV hsv = {
    //   .h = pgm_read_byte(&ledmap[layer][i][0]),
    //   .s = pgm_read_byte(&ledmap[layer][i][1]),
    //   .v = pgm_read_byte(&ledmap[layer][i][2]),
    // };
    // if (!hsv.h && !hsv.s && !hsv.v) {
    //     rgb_matrix_set_color( i, 0, 0, 0 );
    // } else {
    //     RGB rgb = hsv_to_rgb( hsv );
    //     float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    //     rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    // }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case BASE:
      set_layer_color(BASE);
        // rgb_matrix_indicators_user();
      // rgb_matrix_set_color_all(18, 38, 58);
      break;
    // case SYMB:
    //   set_layer_color(SYMB);
    //   break;
    // case SYM2:
    //   rgb_matrix_set_color_all(200, 200,  255);
    //   break;
    // case MEDI:
    //   set_layer_color(MEDI);
    //   break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return false;
}


