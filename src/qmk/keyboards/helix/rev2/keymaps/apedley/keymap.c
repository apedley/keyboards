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
#include "raw_hid.h"
#include "print.h"

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  SEND_RAW = NEWER_SAFE_RANGE,
  ADJUST,
  RGBRST,
  UPSPC,
  NEWTAB,
};

enum combos {
  QW_ESC,
  DF_TAB,
  PBSLS_BSPC,
  IO_MINUS,
  OP_EQUAL,
  COMMA_DOT,
  XC_LDR
};



enum tap_dance_codes {
  TD_SEMI_COLON,
  TD_SLASH_BSLS,
  TD_MINUS_EQUAL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   */
  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGUP, KC_PGDN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      QK_REP,  KC_LCTL, KC_LGUI, KC_LALT, KC_LBRC, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  /* Lower
   */
  [_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_F12,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, NEWTAB,                    KC_MINUS,KC_EQUAL,_______, DM_REC1, DM_PLY1, KC_F11,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
      _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_HOME, KC_END,  KC_HOME,  KC_END, KC_HOME, KC_END,  _______, _______, KC_DEL,  _______,
      _______, _______, _______, _______, KC_LPRN, _______, KC_ENT,   UPSPC,  _______, KC_RPRN, _______, _______, _______, _______
      ),

  /* Raise
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
      KC_F12,  UPDIR,   KC_UP,   SELWORD, KC_PGUP, NEWTAB,                    KC_UNDS, KC_PLUS, _______, _______,  _______, KC_F11,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______,  KC_INSERT,KC_DEL, _______,
      _______, _______, _______, _______, KC_LPRN, _______, KC_ENT,   UPSPC,  _______, KC_RPRN, _______, _______,  _______, _______
      ),

  /* Adjust
   */
  [_ADJUST] =  LAYOUT(
      KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, KC_NUM,  _______, _______, KC_DEL,
      _______, QK_BOOT, _______, _______, _______, _______,                   RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,
      KC_CAPS, KC_MAKE, _______, _______, _______, _______,                   RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,
      _______, DB_TOGG, _______, _______, _______, _______, _______, _______, RGBRST,  _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )
};

// clang-format on

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM pbsls_combo[] = {KC_P, KC_BSLS, COMBO_END};
const uint16_t PROGMEM io_minus_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_equal_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[] = {
    [QW_ESC] = COMBO(qw_combo, KC_ESC),
    [DF_TAB] = COMBO(df_combo, KC_TAB),
    [PBSLS_BSPC] = COMBO(pbsls_combo, KC_BSPC),
    [IO_MINUS] = COMBO(io_minus_combo, KC_MINUS),
    [OP_EQUAL] = COMBO(op_equal_combo, KC_EQUAL),
    [COMMA_DOT] = COMBO_ACTION(comma_dot_combo),
    [XC_LDR] = COMBO_ACTION(x_c_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case COMMA_DOT:
  case XC_LDR:
    if (pressed) {
      leader_start();
    }
    break;
    // case BSPC_LSFT_CLEAR:
    //   if (pressed) {
    //     tap_code16(KC_END);
    //     tap_code16(S(KC_HOME));
    //     tap_code16(KC_BSPC);
    //   }
    //   break;
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_SEMI_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [TD_SLASH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [TD_MINUS_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL)
};

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (debug_enable) {
    dprint("Received USB data from host system:\n");
    // dprintf("%d\n", data);
    for (int i = 0; i < length; i++) {
      printf("%d ", data[i]);
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
    case UPSPC:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_SPC)));
      }
      return false;
      break;
    case NEWTAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_T)));
      }
      return false;
      break;
  }
  return true;
}
