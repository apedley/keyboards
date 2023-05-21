/* Copyright 2020 yushakobo
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
#include "apedley.h"
#include "qmk_rc.h"
#include "print.h"
#include "raw_hid.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  SEND_RAW = NEWER_SAFE_RANGE,
  ADJUST,
  RGBRST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LT_RAISE LT(_RAISE, KC_ENT)
#define LT_LOWER LT(_LOWER, KC_ENT)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |Adjust| Esc  | Alt  | GUI  |Lower |Lower |Space |Space |Raise |Raise | Left | Down |  Up  |Right |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      LT_RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LT_LOWER,
      KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,  QK_LEAD, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |  (   |   )  |  F12 |      |      | Home | End  |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, UPDIR,   KC_UP,   SELWORD, _______, _______,                   KC_MINUS,KC_EQUAL,DM_REC1, DM_PLY1, DM_REC2, DM_PLY2,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   KC_PGUP, KC_PGDN, KC_HOME, KC_END, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______,  _______,
      _______, _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | CAPS |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |      |PageDn|PageUp|      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, UPDIR,   KC_UP,   SELWORD, _______, _______,                   KC_UNDS, KC_PLUS, _______, _______, _______, _______,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______, _______, _______,  _______,
      _______, _______, _______, _______, _______, _______, KC_SPC,  KC_ENT,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |Aud on|Audoff| Mac  |             | Win  |Qwerty|Colemk|Dvorak|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, QK_BOOT, _______, _______, _______, AG_NORM,                   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
      KC_CAPS, KC_MAKE, _______, _______, _______, AG_SWAP,                   RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
      _______, DB_TOGG, _______, _______, _______, _______, _______, _______, RGBRST,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, KC_MAKE, QK_BOOT, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______
      )
};

// clang-format on

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (debug_enable) {
        dprint("Received USB data from host system:\n");
        // dprintf("%d\n", data);
        for (int i = 0; i < length; i++) {
            dprintf("%d ", data[i]);
        }
        dprintf("\n");
        raw_hid_send(data, length);
    }
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}

#endif

int RGB_current_mode;
layer_state_t currentLayerState;

layer_state_t layer_state_set_keymap(layer_state_t state) {
  currentLayerState = state;


#ifdef RAW_ENABLE
//   uint8_t highest_layer = get_highest_layer(currentLayerState);
//   uint8_t qmk_rc_layer_buffer[QMK_RC_BUFFER_MAX] = {0, 1, 0, 0, 0, 0, highest_layer, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0};

//   if (debug_enable) {
//     print("raw_hid_send layer\n");
//   }
//   raw_hid_send(qmk_rc_layer_buffer, QMK_RC_BUFFER_MAX);
#endif
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  return true;
}
