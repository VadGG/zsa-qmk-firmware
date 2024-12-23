#include "combos.h"
#include "keymap.h"

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
    case SQUARE_BRACKETS_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_LEFT_BRACKET, KC_RIGHT_BRACKET);
        }
        return false;
    case ROUND_BRACKETS_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_LEFT_PAREN, KC_RIGHT_PAREN);
        }
        return false;
    case ANGLE_BRACKETS_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
        }
        return false;
    case DOUBLE_QUOTES_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_DOUBLE_QUOTE, KC_DOUBLE_QUOTE);
        }
        return false;
    case SINGLE_QUOTES_COMBO:
        // send_string("{}");
        if (pressed) {
          double_parens_left(KC_QUOTE, KC_QUOTE);
        }
        return false;
    case DASH_ARROW_LEFT:
        // send_string("{}");
        if (pressed) {
          tap_code16(KC_LEFT_ANGLE_BRACKET);
          tap_code16(KC_MINUS);
        }
        return false;
    case EQUAL_ARROW_LEFT:
        // send_string("{}");
        if (pressed) {
          tap_code16(KC_LEFT_ANGLE_BRACKET);
          tap_code16(KC_EQUAL);
        }
        return false;
    case DASH_ARROW_RIGHT:
        // send_string("{}");
        if (pressed) {
          tap_code16(KC_MINUS);
          tap_code16(KC_RIGHT_ANGLE_BRACKET);
        }
        return false;
    case EQUAL_ARROW_RIGHT:
        // send_string("{}");
        if (pressed) {
          tap_code16(KC_EQUAL);
          tap_code16(KC_RIGHT_ANGLE_BRACKET);
        }
        return false;
    case ELIXIR_PIPE:
        // send_string("{}");
        if (pressed) {
          tap_code16(KC_PIPE);
          tap_code16(KC_RIGHT_ANGLE_BRACKET);
        }
        return false;
    case LEFT_CTRL_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_left_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      if (!is_left_ctrl_mod_pressed) {
          is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case LEFT_CTRL_SHIFT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_left_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case RIGHT_CTRL_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_right_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      if (!is_right_ctrl_mod_pressed) {
          is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case RIGHT_CTRL_SHIFT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_right_ctrl_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case LEFT_ALT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_left_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      if (!is_left_alt_mod_pressed) {
          is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case LEFT_ALT_SHIFT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_left_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;

    case RIGHT_ALT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_right_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      if (!is_right_alt_mod_pressed) {
          is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, false);
      }
      return false;
    case RIGHT_ALT_SHIFT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_right_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, pressed);
      return false;
    case LEFT_CTRL_ALT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_left_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_left_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
    case RIGHT_CTRL_ALT_COMBO:
      if (!IS_LAYER_ON(BASE)) {
          return true;
      }
      is_right_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LCTL, pressed);
      is_right_ctrl_alt_mod_pressed = register_mod_on_hold(KC_LEFT_ALT, pressed);
      return false;
  }

  return true;
}

bool process_combo_code_press(uint16_t keycode, keyrecord_t *record) {
    if (is_left_ctrl_mod_pressed) {
        switch (keycode) {
            case KC_V:
              is_left_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }
    if (is_left_alt_mod_pressed) {
        switch (keycode) {
            case KC_V:
              is_left_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }

    if (is_right_ctrl_mod_pressed) {
        switch (keycode) {
            case KC_N:
              is_right_ctrl_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }
    if (is_right_alt_mod_pressed) {
        switch (keycode) {
            case KC_N:
              is_right_alt_shift_mod_pressed = register_mod_on_hold(KC_LSFT, record->event.pressed);
              return false;
        }
    }

    return true;
}


// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
//     /* Disable combo `SOME_COMBO` on layer `_LAYER_A` */
//     switch (combo_index) {

//         case LEFT_CTRL_COMBO:
//         case LEFT_CTRL_SHIFT_COMBO:
//         case RIGHT_CTRL_COMBO:
//         case RIGHT_CTRL_SHIFT_COMBO:
//         case LEFT_ALT_COMBO:
//         case LEFT_ALT_SHIFT_COMBO:
//         case RIGHT_ALT_COMBO:
//         case RIGHT_ALT_SHIFT_COMBO:
//         case LEFT_CTRL_ALT_COMBO:
//         case RIGHT_CTRL_ALT_COMBO:
//         case DOUBLE_QUOTES_COMBO:
//             if (!layer_state_is(BASE)) {
//                 return false;
//             }
//     }

//     return true;
// }
