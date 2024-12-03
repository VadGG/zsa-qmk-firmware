#include "combos.h"

bool is_left_ctrl_mod_pressed = false;
bool is_left_ctrl_mod_double_pressed = false;

bool is_left_ctrl_shift_mod_pressed = false;
bool is_left_ctrl_alt_mod_pressed = false;

bool is_right_ctrl_mod_pressed = false;
bool is_right_ctrl_shift_mod_pressed = false;
bool is_right_ctrl_alt_mod_pressed = false;

bool is_left_alt_mod_pressed = false;
bool is_left_alt_shift_mod_pressed = false;
bool is_left_alt_ctrl_mod_pressed = false;

bool is_right_alt_mod_pressed = false;
bool is_right_alt_shift_mod_pressed = false;
bool is_right_alt_ctrl_mod_pressed = false;

bool is_left_ctrl_pressed(void) {
  return is_left_ctrl_mod_pressed;
}

bool is_left_ctrl_shift_pressed(void) {
  return is_left_ctrl_mod_pressed && is_left_ctrl_shift_mod_pressed;
}

bool is_left_ctrl_alt_pressed(void) {
  return is_left_ctrl_mod_pressed && is_left_ctrl_alt_mod_pressed;
}




bool is_right_ctrl_pressed(void) {
  return is_right_ctrl_mod_pressed;
}

bool is_right_ctrl_shift_pressed(void) {
  return is_right_ctrl_mod_pressed && is_right_ctrl_shift_mod_pressed;
}

bool is_right_ctrl_alt_pressed(void) {
  return is_right_ctrl_mod_pressed && is_right_ctrl_alt_mod_pressed;
}

bool is_left_alt_pressed(void) {
  return is_left_alt_mod_pressed;
}
bool is_left_alt_shift_pressed(void) {
  return is_left_alt_mod_pressed && is_left_alt_shift_mod_pressed;
}
bool is_left_alt_ctrl_pressed(void) {
  return is_left_alt_mod_pressed && is_left_alt_ctrl_mod_pressed;
}

bool is_right_alt_pressed(void) {
  return is_right_alt_mod_pressed;
}
bool is_right_alt_shift_pressed(void) {
  return is_right_alt_mod_pressed && is_right_alt_shift_mod_pressed;
}
bool is_right_alt_ctrl_pressed(void) {
  return is_right_alt_mod_pressed && is_right_alt_ctrl_mod_pressed;
}

bool register_mod_on_hold(uint16_t keycode, bool pressed) {
    if (pressed) {
        // register_code(keycode);
        register_mods(MOD_BIT(keycode));
    } else {
        // unregister_code(keycode);
        unregister_mods(MOD_BIT(keycode));
    }

    return pressed;
}

bool process_modifider_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case LEFT_CTRL_COMBO:
      is_left_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      return false;
    case RIGHT_CTRL_COMBO:
      is_right_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      return false;
    case LEFT_ALT_COMBO:
      is_left_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
    case RIGHT_ALT_COMBO:
      is_right_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
  }

  return true;
}

bool process_combo_code_press(uint16_t keycode, keyrecord_t *record) {
    // if (is_left_ctrl_mod_pressed) {
    //     switch(keycode) {
    //         case KC_A:
    //         case KC_S:
    //             return false;
    //         case KC_D:
    //             is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
    //             return false;
    //         case KC_F:
    //             is_left_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, record->event.pressed);
    //             return false;
    //     }
    // }

    // if (is_right_ctrl_mod_pressed) {
    //     switch(keycode) {
    //         case KC_K:
    //             is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
    //             return false;
    //         case KC_J:
    //             is_right_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, record->event.pressed);
    //             return false;
    //     }
    // }

    // if (is_left_alt_mod_pressed ) {
    //     switch(keycode) {
    //         case KC_S:
    //             is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
    //             return false;
    //         case KC_A:
    //             is_left_alt_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, record->event.pressed);
    //             return false;
    //     }
    // }

    // if (is_right_alt_mod_pressed) {
    //     switch(keycode) {
    //         case KC_L:
    //             register_mod_on_hold(KC_LSFT, record->event.pressed);
    //             return false;
    //         case KC_SCLN:
    //             register_mod_on_hold(KC_LCTL, record->event.pressed);
    //             return false;
    //     }
    // }

    return true;
}

