#pragma once

#include "keymap.h"



bool ctrl_layer_ctrl_active = false;
bool ctrl_layer_cmd_active = false;
bool ctrl_layer_alt_active = false;
bool ctrl_layer_shift_active = false;

bool is_on_mod_selector_layer(void) {
  return IS_LAYER_ON(CTRL);
}

bool is_on_moddable_layer(void) {
  return IS_LAYER_ON(BASE);
}

bool is_ctrl_mod_on(void) {
  return ctrl_layer_ctrl_active;
}

bool is_gui_mod_on(void) {
  return ctrl_layer_cmd_active;
}

bool is_alt_mod_on(void) {
  return ctrl_layer_alt_active;
}

bool is_shift_mod_on(void) {
  return ctrl_layer_shift_active;
}

bool is_any_mod_on(void) {
  return is_ctrl_mod_on() || is_gui_mod_on() || is_alt_mod_on() || is_shift_mod_on();
}

bool is_moddable_key(uint16_t keycode) {
  return IS_QK_BASIC(keycode);
}

bool is_modifier_key(uint16_t keycode) {
  return IS_MODIFIER_KEYCODE(keycode);
}
