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
#include "keymap.h"
#include "helpers.h"

#include "combos.h"

const uint16_t PROGMEM custom_left_ctrl[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM custom_left_alt[] = {KC_G, KC_F, COMBO_END};
const uint16_t PROGMEM custom_right_ctrl[] = {KC_SCLN, KC_L, COMBO_END};
const uint16_t PROGMEM custom_right_alt[] = {KC_H, KC_J, COMBO_END};

const uint16_t PROGMEM to_num[] = {KC_SPACE, KC_ENT, COMBO_END};

const uint16_t PROGMEM qmk_boot[] = {KC_R, KC_TAB, COMBO_END};
const uint16_t PROGMEM arr_panic[] = {KC_UP, KC_DOWN, COMBO_END};

combo_t key_combos[] = {
    [LEFT_CTRL_COMBO] = COMBO_ACTION(custom_left_ctrl),
    [LEFT_ALT_COMBO] = COMBO_ACTION(custom_left_alt),

    [RIGHT_CTRL_COMBO] = COMBO_ACTION(custom_right_ctrl),
    [RIGHT_ALT_COMBO] = COMBO_ACTION(custom_right_alt),


    COMBO(to_num, TO_NUM_LAYER),
    COMBO(qmk_boot, QK_BOOT),
    COMBO(arr_panic, TO(BASE)),
};


// ------------- COMBO ---------------
// const uint16_t PROGMEM custom_esc[] = {KC_D, KC_S, COMBO_END};
// const uint16_t PROGMEM custom_tab[] = {KC_D, KC_S, COMBO_END};


// const uint16_t PROGMEM custom_enter[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM custom_colon[] = {KC_H, KC_J, COMBO_END};

// const uint16_t PROGMEM custom_backspace[] = {KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM custom_backspace_word[] = {KC_I, KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM custom_delete_word[] = {KC_W, KC_E, KC_R, COMBO_END};




// ------------- END COMBO ---------------
#include "tap_dance.h"


// -----------------------------------
// -----------------------------------
#include "process_record_user.h"
// -----------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_GRAVE,                  KC_1,                      KC_2,                      KC_3,                      KC_4,                      KC_5,                      KC_F11,                    KC_F12,                    KC_6,                      KC_7,                      KC_8,                      KC_9,                      KC_0,                      KC_BACKSPACE,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_TAB,                    KC_Q,                      KC_W,                      KC_E,                      KC_R,                      KC_T,                      KC_MINUS,                  KC_EQUAL,                  KC_Y,                      KC_U,                      KC_I,                      KC_O,                      KC_P,                      KC_MINUS,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_ESCAPE,                 KC_A,                      KC_S,                      KC_D,                      KC_F,                      KC_G,                      TD(TD_LEFT_BRACKET),       KC_RIGHT_BRACKET,          KC_H,                      KC_J,                      KC_K,                      KC_L,                      KC_SCLN,                   KC_QUOTE,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_LSFT,                   KC_Z,                      KC_X,                      KC_C,                      KC_V,                      KC_B,                                                                            KC_N,                      KC_M,                      KC_COMM,                    KC_DOT,                   KC_SLASH,                  KC_BACKSLASH,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_LCTL,                   KC_LEFT_GUI,               KC_LEFT_ALT,               KC_DOWN,                   KC_UP,                                                SGUI(KC_4),                KC_PRINT_SCREEN,                                      KC_LEFT,                   KC_RIGHT,                   KC_LEFT_ALT,              KC_LEFT_GUI,               KC_LEFT_CTRL,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    MO(_LMOD),                 KC_NO,                     KC_NO,                     QK_REPEAT_KEY,             KC_ENT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),

    [_LMOD] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_F12,                    KC_F1,                     KC_F2,                     KC_F3,                     KC_F4,                     KC_F5,                     _______,                   _______,                   KC_F6,                     KC_F7,                     KC_F8,                     KC_F9,                     KC_F10,                    KC_F11,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   KC_LEFT_GUI,               KC_LEFT_ALT,               KC_LSFT,                   KC_LEFT_CTRL,              _______,                   _______,                   _______,                   _______,                   KC_LEFT_CTRL,              KC_LSFT,                   KC_LEFT_ALT,               KC_LEFT_GUI,                   _______,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                   _______,                                                                         _______,                   _______,                   _______,                   _______,                   _______,                   _______,        
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   KC_KB_VOLUME_DOWN,         KC_KB_VOLUME_UP,                                      _______,                   _______,                                              _______,                   _______,                   _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    _______,                   KC_TRANSPARENT,            _______,                   _______,                   _______,                   _______
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),

    [_RMOD] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_F12,                    KC_F1,                     KC_F2,                     KC_F3,                     KC_F4,                     KC_F5,                     KC_NO,                     KC_NO,                     KC_F6,                     KC_F7,                     KC_F8,                     KC_F9,                     KC_F10,                    KC_F11,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_DELETE,                 _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                    _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   KC_LEFT_GUI,               KC_LEFT_CTRL,              KC_LEFT_ALT,                KC_LSFT,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                   _______,                                                                         _______,                   _______,                   _______,                    _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                                              _______,                   _______,                                              KC_KB_VOLUME_DOWN,         KC_KB_VOLUME_UP,            _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    _______,                   KC_NO,                     KC_NO,                     KC_TRANSPARENT,            KC_LSFT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),

    [_NUM] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_BACKSPACE,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        KC_NO,                     KC_J,                      KC_NO,                     KC_ASTERISK,               KC_EXCLAIM,                KC_P,                      KC_NO,                     KC_NO,                     KC_PLUS,                   KC_SLASH,                  KC_NO,                     KC_NO,                     KC_DOT,                    KC_NO,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        TO_BASE,                   KC_6,                      KC_4,                      KC_0,                      KC_2,                      KC_K,                      KC_NO,                     KC_NO,                     KC_MINUS,                  KC_3,                      KC_1,                      KC_5,                      KC_7,                      KC_NO,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_NO,                     KC_COMM,                   KC_NO,                     LSFT(KC_G),                KC_8,                      KC_NO,                                                                           KC_EQUAL,                  KC_9,                      KC_LEFT_BRACKET,           KC_LEFT_PAREN,             KC_UNDERSCORE,             KC_NO,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                                                KC_NO,                     KC_NO,                                                KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,                     KC_NO,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    _______,                   KC_NO,                     KC_NO,                     _______,                   KC_LSFT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),

    [NUM] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   LSFT(KC_F1),               LSFT(KC_F2),               LSFT(KC_F3),               LSFT(KC_F4),               LSFT(KC_F5),               _______,                   _______,                   LSFT(KC_F6),               LSFT(KC_F7),               LSFT(KC_F8),               LSFT(KC_F9),               LSFT(KC_F10),              _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   KC_GRAVE,                  KC_QUOTE,                  LSFT(KC_QUOTE),            KC_LEFT_PAREN,             KC_RIGHT_PAREN,            _______,                   _______,                   TD(TD_BACKSPACE),          KC_7,                      KC_8,                      KC_9,                      KC_DOT,                    _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_TRANSPARENT,            KC_COMM,                   KC_MINUS,                  KC_DOLLAR,                 KC_LEFT_CURLY_BRACE,       KC_RIGHT_CURLY_BRACE,      _______,                   _______,                   KC_BACKSPACE,              KC_4,                      KC_5,                      KC_6,                      KC_COMM,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   LSFT(KC_GRAVE),            KC_SLASH,                  KC_DOT,                    KC_RIGHT_BRACKET,          KC_LEFT_BRACKET,                                                                 KC_0,                      KC_1,                      KC_2,                      KC_3,                      KC_SLASH,                  _______,        
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                  _______,                    _______,                                              _______,                   _______,                                              _______,                   _______,                   _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    _______,                   _______,                   _______,                   _______,                   KC_LSFT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),
    [_CUSTOM_MOD] = LAYOUT(
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        TO(BASE),                   KC_F1,                     KC_F2,                     KC_F3,                     KC_F4,                     KC_F5,                     KC_NO,                     KC_NO,                     KC_F6,                     KC_F7,                     KC_F8,                     KC_F9,                     KC_F10,                    KC_F11,
     //|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                   _______,                    _______,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   KC_LSFT,                   KC_LEFT_ALT,               KC_LEFT_CTRL,              KC_LEFT_GUI,               _______,                   _______,                   KC_LEFT_GUI,               KC_LEFT_CTRL,              KC_LEFT_ALT,                KC_LSFT,                   _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        KC_TRANSPARENT,            _______,                   _______,                   _______,                   _______,                   _______,                                                                         _______,                   _______,                   _______,                   _______,                    _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
        _______,                   _______,                   _______,                   _______,                   _______,                                              _______,                   _______,                                              KC_KB_VOLUME_DOWN,         KC_KB_VOLUME_UP,           _______,                    _______,                   _______,
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
                                                                                                                    KC_SPC,                    _______,                   KC_NO,                     KC_NO,                     _______,                   KC_LSFT
     //|-----------------------------------------------------------------------------------------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|--------------------------|-----------------------------------------------------------------------------------------------------------|
    ),
};



// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // tap_code16(MY_CUSTOM_MOD_TOGGLE);
            if (!is_custom_mod_set()) {
                ctrl_key_toggle = false;
            } else {
                ctrl_key_toggle = !ctrl_key_toggle;
            }
            break;
        case TD_SINGLE_HOLD:
            // layer_on(_CUSTOM_MOD);
            ctrl_key_held = false;
            clear_mon_selectors();

            if (layer_state_is(_CUSTOM_MOD)) {
                // If already set, then switch it off
                layer_off(_CUSTOM_MOD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_CUSTOM_MOD);
            }
            break;
        case TD_DOUBLE_TAP:
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_CUSTOM_MOD);
        ctrl_key_toggle = is_custom_mod_set();
    } else if (ql_tap_state.state == TD_DOUBLE_TAP) {
        // layer_off(_CUSTOM_MOD);
    }
    ql_tap_state.state = TD_NONE;
}

static bool left_bracket_held = false; // Tracks if the key is held

void td_left_bracket_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
         if (!state->pressed) {
            // Single tap sends [
            tap_code16(KC_LEFT_BRACKET);
        } else {
            // Single hold starts sending [
            left_bracket_held = true;
            register_code(KC_LEFT_BRACKET);
        }
    } else if (state->count == 2) {
        process_record_user(OPEN_BRACKET, &(keyrecord_t){.event = {.pressed = true}});
        process_record_user(OPEN_BRACKET, &(keyrecord_t){.event = {.pressed = false}});
    }
}

void td_left_bracket_reset(tap_dance_state_t *state, void *user_data) {
    if (left_bracket_held) {
        unregister_code(KC_LEFT_BRACKET);
        left_bracket_held = false;
    }
}
// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [MY_CMOD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset),
    [TD_BACKSPACE] = ACTION_TAP_DANCE_DOUBLE(KC_BACKSPACE, KC_BACKSPACE_WORD), 
    [TD_LEFT_BRACKET] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_left_bracket_finished, td_left_bracket_reset),

    [TD_1F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1), 
    [TD_2F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2), 
    [TD_3F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3), 
    [TD_4F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4), 
    [TD_5F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5), 
    [TD_6F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6), 
    [TD_7F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7), 
    [TD_8F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8), 
    [TD_9F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9), 
    [TD_0F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10), 



    
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_CMOD:
            return 100;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 175;
        default:
            return TAPPING_TERM;
    }
}


#include "rgb.h"


