#pragma once

#include QMK_KEYBOARD_H

enum combos {
  LEFT_CTRL_COMBO,
  LEFT_CTRL_SHIFT_COMBO,

  RIGHT_CTRL_COMBO,
  RIGHT_CTRL_SHIFT_COMBO,

  LEFT_ALT_COMBO,
  LEFT_ALT_SHIFT_COMBO,

  RIGHT_ALT_COMBO,
  RIGHT_ALT_SHIFT_COMBO,
};

bool is_left_ctrl_pressed(void);
bool is_left_ctrl_shift_pressed(void);

bool is_right_ctrl_pressed(void);
bool is_right_ctrl_shift_pressed(void);

bool is_left_alt_pressed(void);
bool is_left_alt_shift_pressed(void);

bool is_right_alt_pressed(void);
bool is_right_alt_shift_pressed(void);

bool process_modifider_combo_event(uint16_t combo_index, bool pressed);

bool register_mod_on_hold(uint16_t keycode, bool pressed);

bool process_combo_code_press(uint16_t keycode, keyrecord_t *record);

