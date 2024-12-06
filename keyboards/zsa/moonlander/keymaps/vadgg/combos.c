#include "combos.h"

bool is_left_ctrl_mod_pressed = false;
bool is_left_ctrl_shift_mod_pressed = false;

bool is_left_ctrl_pressed(void) {
  return is_left_ctrl_mod_pressed;
}
bool is_left_ctrl_shift_pressed(void) {
  return  is_left_ctrl_shift_mod_pressed;
}

bool is_right_ctrl_mod_pressed = false;
bool is_right_ctrl_shift_mod_pressed = false;

bool is_right_ctrl_pressed(void) {
  return is_right_ctrl_mod_pressed;
}
bool is_right_ctrl_shift_pressed(void) {
  return is_right_ctrl_shift_mod_pressed;
}

bool is_left_alt_mod_pressed = false;
bool is_left_alt_shift_mod_pressed = false;

bool is_left_alt_pressed(void) {
  return  is_left_alt_mod_pressed;
}
bool is_left_alt_shift_pressed(void) {
  return is_left_alt_shift_mod_pressed;
}

bool is_right_alt_mod_pressed = false;
bool is_right_alt_shift_mod_pressed = false;

bool is_right_alt_pressed(void) {
  return is_right_alt_mod_pressed;
}
bool is_right_alt_shift_pressed(void) {
  return is_right_alt_shift_mod_pressed;
}


bool is_left_ctrl_alt_mod_pressed = false;
bool is_right_ctrl_alt_mod_pressed = false;

bool is_left_ctrl_alt_pressed(void) {
  return is_left_ctrl_alt_mod_pressed;
}
bool is_right_ctrl_alt_pressed(void) {
  return is_right_ctrl_alt_mod_pressed;
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

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

bool process_modifider_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CURLY_BRACKETS_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
        }
        return false;
    case LEFT_CTRL_COMBO:
      is_left_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      if (!is_left_ctrl_mod_pressed) {
          is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case LEFT_CTRL_SHIFT_COMBO:
      is_left_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case RIGHT_CTRL_COMBO:
      is_right_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      if (!is_right_ctrl_mod_pressed) {
          is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case RIGHT_CTRL_SHIFT_COMBO:
      is_right_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case LEFT_ALT_COMBO:
      is_left_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      if (!is_left_alt_mod_pressed) {
          is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case LEFT_ALT_SHIFT_COMBO:
      is_left_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case RIGHT_ALT_COMBO:
      is_right_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      if (!is_right_alt_mod_pressed) {
          is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case RIGHT_ALT_SHIFT_COMBO:
      is_right_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;
    case LEFT_CTRL_ALT_COMBO:
      is_left_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_left_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
    case RIGHT_CTRL_ALT_COMBO:
      is_right_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_right_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
  }

  return true;
}

bool process_combo_code_press(uint16_t keycode, keyrecord_t *record) {
    if (is_left_ctrl_mod_pressed) {
        switch (keycode) {
            case KC_F:
              is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }
    if (is_left_alt_mod_pressed) {
        switch (keycode) {
            case KC_A:
              is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }

    if (is_right_ctrl_mod_pressed) {
        switch (keycode) {
            case KC_H:
              is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }
    if (is_right_alt_mod_pressed) {
        switch (keycode) {
            case KC_L:
              is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }

    return true;
}

