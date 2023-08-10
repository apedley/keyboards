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
  _ADJUST,
  _NUMPAD
};

enum custom_keycodes {
  SEND_RAW = NEW_SAFE_RANGE,
  ADJUST,
  UPSPC,
  NEWTAB,
  DRAG_SCROLL
};



enum tap_dance_codes {
  TD_SEMI_COLON,
  TD_SLASH_BSLS,
  TD_MINUS_EQUAL
};

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 10.0
#define SCROLL_DIVISOR_V 10.0

// clang-format off


// #define LOWER MO(_LOWER)
// #define RAISE MO(_RAISE)


#define TOGNP TG(_NUMPAD)

#define KC_COPY LCTL(KC_C)
#define KC_CUT LCTL(KC_X)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   */
  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      TL_UPPR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_PGUP,       KC_PGDN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      QK_REP,  KC_LCTL, KC_LGUI, KC_LALT, KC_LBRC, TL_LOWR,  KC_SPC,        KC_SPC,   TL_UPPR, KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  /* Lower
   */
  [_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_F12,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, NEWTAB,                    KC_MINUS,KC_EQUAL,_______, DM_REC1, DM_PLY1, KC_F11,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_HOME, KC_END, KC_HOME,  KC_END, KC_HOME, KC_END,  _______, _______, KC_DEL,  _______,
      QK_BOOT, _______, _______, _______, KC_LPRN, _______, KC_ENT,   UPSPC,  _______, KC_RPRN, _______, _______, _______, QK_BOOT
      ),

  /* Raise
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
      KC_F12,  UPDIR,   KC_UP,   SELWORD, KC_VOLU, NEWTAB,                    KC_UNDS, KC_PLUS, _______, _______,  _______, KC_F11,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______,  KC_INSERT,KC_DEL, _______,
      QK_BOOT, DRAG_SCROLL, _______, _______, KC_LPRN, _______, KC_ENT,   UPSPC,  _______, KC_RPRN, _______, _______,  QK_BOOT, DRAG_SCROLL
      ),
   /* Adjust
   */
  [_ADJUST] =  LAYOUT(
      KC_GRV,  RGB_MOD, RGB_TOG, RGB_HUI, RGB_VAI, RGB_SPI,                   KC_NUM,  _______,  KC_CAPS, _______, _______, KC_DEL,
      _______, QK_BOOT, _______, _______, _______, _______,                   RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
      KC_CAPS, KC_MAKE, _______, _______, _______, _______,                   RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
      _______, DB_TOGG, _______, _______, _______, _______, _______, TOGNP,   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MAKE, QK_BOOT
      ),
  [_NUMPAD] =  LAYOUT(
      KC_GRV,  _______, _______, _______, _______, _______,                   KC_NUM,   KC_PSLS,KC_PAST,KC_PMNS, _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_P7,    KC_P8,  KC_P9, KC_PPLS, _______, _______,
      _______, _______, _______, _______, _______, _______,                   KC_P4,    KC_P5,  KC_P6, KC_PPLS, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, TOGNP,   KC_P1,    KC_P2,  KC_P3, KC_PENT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, KC_P0,    KC_P0,  KC_DOT, KC_PENT, KC_MAKE, QK_BOOT
      ),
};

// clang-format on



tap_dance_action_t tap_dance_actions[] = {
  [TD_SEMI_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
  [TD_SLASH_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [TD_MINUS_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL)
};


bool set_scrolling = false;


#ifdef POINTING_DEVICE_ENABLE

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  // if (set_scrolling) {
  //     mouse_report.h = mouse_report.x;
  //     mouse_report.v = mouse_report.y;
  //     mouse_report.x = 0;
  //     mouse_report.y = 0;
  // }

  // return mouse_report;


  // Check if drag scrolling is active
  if (set_scrolling) {
    // Calculate and accumulate scroll values based on mouse movement and divisors
    scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
    scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

    // Assign integer parts of accumulated scroll values to the mouse report
    mouse_report.h = (int8_t)scroll_accumulated_h;
    mouse_report.v = -(int8_t)scroll_accumulated_v;

    // Update accumulated scroll values by subtracting the integer parts
    scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
    scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

    // Clear the X and Y values of the mouse report
    mouse_report.x = 0;
    mouse_report.y = 0;
  }
  return mouse_report;
}

#endif // POINTING_DEVICE_ENABLE


void keyboard_post_init_keymap(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  debug_mouse=true;

  if (!is_keyboard_left()) {
    pimoroni_trackball_set_rgbw(0, 0, 0, 80);
  }
}
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
    // raw_hid_send(data, length);
  }
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}

#endif

int RGB_current_mode;

// layer_state_t layer_state_set_keymap(layer_state_t state) {
  // layer_state_t new_state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  // #ifdef RAW_ENABLE
//   uint8_t highest_layer = get_highest_layer(state);
//   // uint8_t qmk_rc_layer_buffer[QMK_RC_BUFFER_MAX] = {0, 1, 0, 0, 0, 0, highest_layer, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0};

//   // if (debug_enable) {
//   //   dprintf("raw_hid_send layer %d\n", highest_layer);
//   // }
//   // raw_hid_send(qmk_rc_layer_buffer, QMK_RC_BUFFER_MAX);

  // uint8_t layer_data[RAW_EPSIZE];
  // memset(layer_data, 0, RAW_EPSIZE);


  // layer_data[0] = get_highest_layer(new_state|default_layer_state);

  // switch (get_highest_layer(state)) {
  //   case _RAISE:
  //     layer_data[0] = 1;
  //     break;
  //   case _LOWER:
  //     layer_data[0] = 2;
  //     break;
  //   case _ADJUST:
  //     layer_data[0] = 3;
  //     break;
  //   case _NUMPAD:
  //     layer_data[0] = 4;
  //     break;
  //   default:
  //     layer_data[0] = 0;
  //     break;
  // }

  // dprintf("layer_data:");
  // for (int i = 0; i < RAW_EPSIZE; i++) {
  //   dprintf("%d ", layer_data[i]);
  // }
  // dprintf("\n");

  // raw_hid_send(layer_data, RAW_EPSIZE);


  // #endif

// #ifdef RAW_ENABLE

// #define QMK_RC_BUFFER_MAX 64
// uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

// void raw_hid_receive(uint8_t *data, uint8_t length) {
//   qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
// }
// #endif


// layer_state_t layer_state_set_keymap(layer_state_t state) {
//   state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

//   #ifdef RAW_ENABLE
//   uint8_t layer_data[32];
//   layer_data[0] = 1;
//   layer_data[1] = get_highest_layer(state|default_layer_state);
//   raw_hid_send(layer_data, 32);

//   #endif // RAW_ENABLE

//   #ifdef POINTING_DEVICE_ENABLE

//   #endif
// //   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//   return state;
// }

layer_state_t layer_state_set_keymap(layer_state_t state) {
  #ifdef POINTING_DEVICE_ENABLE

  switch (get_highest_layer(state)) {
    case _LOWER:
    case _RAISE:
    case _ADJUST:
      set_scrolling = true;
      break;
    default:
      set_scrolling = false;
      break;
  }
  #endif


  #ifdef RAW_ENABLE
  uint8_t layer_data[32];
  layer_data[0] = 1;
  layer_data[1] = get_highest_layer(state|default_layer_state);
  raw_hid_send(layer_data, 32);

  #endif // RAW_ENABLE

  return state;

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
    case DRAG_SCROLL:
      if (record->event.pressed) {
        set_scrolling = !set_scrolling;
        // set_scrolling = record->event.pressed;
      }
      return false;
      break;
  }
  return true;
}
