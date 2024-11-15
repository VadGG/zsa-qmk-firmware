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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_GRAVE,       KC_1,            KC_2,                 KC_3,                 KC_4,                KC_5,    LSFT(KC_COMMA),           LSFT(KC_DOT),         KC_6,               KC_7,               KC_8,             KC_9,            KC_0,             KC_BACKSPACE,
        KC_TAB,         KC_Q,            KC_W,                 KC_E,                 KC_R,                KC_T,    KC_MINUS,                 KC_EQUAL,             KC_Y,               KC_U,               KC_I,             KC_O,            KC_P,             KC_MINUS,
        KC_ESCAPE,      KC_A,            KC_S,         KC_D,         KC_F,        KC_G,    KC_LEFT_BRACKET,          KC_RIGHT_BRACKET,     KC_H,       KC_J,       KC_K,             KC_L,            KC_SEMICOLON,     KC_QUOTE,
        KC_LSFT,        KC_Z,            KC_X,                 KC_C,                 KC_V,                KC_B,                                                    KC_N,               KC_M,               KC_COMM,          KC_DOT,          KC_SLASH,         KC_BACKSLASH,
        KC_LEFT_CTRL,   KC_LEFT_GUI,     KC_LEFT_ALT,          KC_DOWN,              KC_UP,            SGUI(KC_4),                 RCTL_T(KC_ESC),                 KC_LEFT,            KC_RIGHT,           KC_LEFT_ALT,    KC_LEFT_GUI,       KC_LEFT_CTRL,
                                                                                       KC_SPC,  KC_LSFT, _______,        _______,  MO(NAV),  KC_ENT
    ),

    [NAV] = LAYOUT(
        _______,       KC_F1,             KC_F2,               KC_F3,                 KC_F4,              KC_F5,            KC_F6,             KC_F7,              KC_F8,          KC_F9,             KC_F10,             KC_F11,             KC_F12,          KC_DELETE,
        _______,       _______,           _______,             _______,               _______,            _______,          _______,           _______,            KC_LEFT,        KC_DOWN,           KC_UP,            KC_RIGHT,            _______,         _______,
        TO(BASE),       _______,          KC_LEFT_CTRL,        KC_LEFT_ALT,           KC_LEFT_GUI,        _______,          _______,           _______,            KC_H,           KC_J,                 KC_K,              KC_L,           KC_VIM_END,         _______,
        _______,       _______,           _______,             _______,               _______,            _______,                                                 KC_HOME,           KC_PGDN,              KC_PGUP,               KC_INS,               KC_VIM_START,         _______,        
        _______,       _______,           _______,             _______,               _______,       _______,                                             _______,            _______,           _______,            _______,            _______,         _______,
                                                                                             _______, _______, _______,                      _______, KC_TRANSPARENT, _______
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
#define F_NUM_COLOR {83, 58, 255}      // bright purple
#define F10_11_12_NUM_COLOR {152, 62, 255}      // bright purple

#define HOME_KEYS_COLOR {255, 202, 58}      // bright purple

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
           NUM_COLOR, ALPHA_COLOR,  ALPHA_COLOR,  ALPHA_COLOR, MODIFIER_COLOR, 
           // TOP LEFT -----> Column 03 starting with 02 
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, MODIFIER_COLOR, 
           // TOP LEFT -----> Column 04 starting with 03
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, ARROW_COLOR ,
           // TOP LEFT -----> Column 05 starting with 04
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,  ALPHA_COLOR, ARROW_COLOR , 
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
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,     SYMBOLS_COLOR,  ARROW_COLOR ,
           // TOP RIGHT -----> Last column starting with 7
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR,     ALPHA_COLOR, ARROW_COLOR, 
           // TOP RIGHT -----> Last column starting with 6
           NUM_COLOR, ALPHA_COLOR,  HOMEROW_MODS_COLOR, ALPHA_COLOR,  
           // TOP LEFT -----> Column 07 starting with >
           SYMBOLS_COLOR, SYMBOLS_COLOR,  SYMBOLS_COLOR,

           //  Right Thumb Keys,                           // Special red button
           SPACE_COLOR, LAYER_SWITCH_COLOR,  NO_COLOR,     NO_COLOR},

      [NAV] = {
           // TOP LEFT -----> Column 01 starting with `
           F_NUM_COLOR, NO_COLOR,  LAYER_SWITCH_COLOR,  NO_COLOR, NO_COLOR, 
           // TOP LEFT -----> Column 02 starting with 01 
           F_NUM_COLOR, NO_COLOR,  NO_COLOR,  NO_COLOR, NO_COLOR, 
           // TOP LEFT -----> Column 03 starting with 02 
           F_NUM_COLOR, NO_COLOR,  MODIFIER_COLOR,  NO_COLOR, NO_COLOR, 
           // TOP LEFT -----> Column 04 starting with 03
           F_NUM_COLOR, NO_COLOR,  MODIFIER_COLOR,  NO_COLOR, NO_COLOR,
           // TOP LEFT -----> Column 05 starting with 04
           F_NUM_COLOR, NO_COLOR,  MODIFIER_COLOR,  NO_COLOR, NO_COLOR, 
           // TOP LEFT -----> Column 06 starting with 05
           F_NUM_COLOR, NO_COLOR,  NO_COLOR,  NO_COLOR, 
           // TOP LEFT -----> Column 07 starting with <
           F_NUM_COLOR, NO_COLOR,  NO_COLOR,

           //  Left Thumb Keys,                           // Special red button
           NO_COLOR, SHIFT_COLOR,  NO_COLOR,     NO_COLOR,

           // TOP RIGHT -----> Last column starting with backspace
           DEL_COLOR, NO_COLOR,  NO_COLOR,  NO_COLOR,        NO_COLOR, 
           // TOP RIGHT -----> Last column starting with 0
           F10_11_12_NUM_COLOR , NO_COLOR,  SYMBOLS_COLOR ,  SYMBOLS_COLOR ,    NO_COLOR, 
           // TOP RIGHT -----> Last column starting with 9
           F10_11_12_NUM_COLOR , ARROW_COLOR,  ALPHA_COLOR,     HOME_KEYS_COLOR,  NO_COLOR, 
           // TOP RIGHT -----> Last column starting with 8
           F10_11_12_NUM_COLOR , ARROW_COLOR,  ALPHA_COLOR,     HOME_KEYS_COLOR,  NO_COLOR,
           // TOP RIGHT -----> Last column starting with 7
           F_NUM_COLOR,          ARROW_COLOR,  ALPHA_COLOR,     HOME_KEYS_COLOR, NO_COLOR, 
           // TOP RIGHT          -----> Last column starting with 6
           F_NUM_COLOR,          ARROW_COLOR,  ALPHA_COLOR,     HOME_KEYS_COLOR,  
           // TOP LEFT -         ----> Column 07 starting with >
           F_NUM_COLOR,          NO_COLOR,  NO_COLOR,

           //  Right Thumb Keys,                           // Special red button
           NO_COLOR, LAYER_SWITCH_COLOR,  NO_COLOR,     NO_COLOR},
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
        case NAV:
          set_layer_color(NAV);
          break;
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


