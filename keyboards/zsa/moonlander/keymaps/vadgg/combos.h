#pragma once

#include QMK_KEYBOARD_H

enum combos {
  LEFT_CTRL_COMBO,
  RIGHT_CTRL_COMBO,
  LEFT_ALT_COMBO,
  RIGHT_ALT_COMBO,
};


bool process_modifider_combo_event(uint16_t combo_index, bool pressed);

bool register_mod_on_hold(uint16_t keycode, bool pressed);

bool process_combo_code_press(uint16_t keycode, keyrecord_t *record);

