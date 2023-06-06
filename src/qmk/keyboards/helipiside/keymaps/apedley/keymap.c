// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "apedley.h"
#include QMK_KEYBOARD_H
enum layer_number {
  _BASE,
  _FN,
  _FN2
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *        ,-----------------------------------------.
   *        | Num  |   /  |   *  |   -  | Home | Del  |
   *        |------+------+------+------+------+------|
   *        |   7  |   8  |   9  |   +  | End  |VolUp |
   *        |------+------+------+------+------+------|
   *        |   4  |   5  |   6  | Enter| PgUp | Mute |
   * ,------+------+------+------+------+------+------|
   * |  FN2 |   1  |   2  |   3  | Shift| PgDn |VolDn |
   * /------+------+------+------+------+------+------|
   * |  FN  | Ctrl |   0  |   .  |  Alt |  Gui | FN2  |
   * -------------------------------------------------'
   */

  [_BASE] = LAYOUT(
              KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_HOME, KC_DEL,
              KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_END,  KC_VOLU,
              KC_P4,    KC_P5,    KC_P6,    KC_PENT,  KC_PGUP, KC_MUTE,
    TT(_FN2), KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  KC_PGDN, KC_VOLD,
    TT(_FN),  KC_RCTL,  KC_P0,    KC_PDOT,  KC_RALT,  KC_RGUI, TT(_FN2)
  ),
  [_FN] = LAYOUT(
              KC_CAPS, _______, _______, _______, _______, _______,
              _______, _______, _______, _______, _______, _______,
              _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______
  ),
  [_FN2] = LAYOUT(
              RGB_MOD, RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPD,
              _______, _______, _______, _______, _______, _______,
              _______, _______, _______, _______, _______, _______,
    _______,  QK_BOOT, _______, _______, _______, _______, _______,
    _______,  QK_BOOT, _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE
void render_layer(void) {
77

0.

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("Base"), false);
        break;
    case _FN:
        oled_write_P(PSTR("FN1"), false);
        break;
    case _FN2:
        oled_write_P(PSTR("FN2"), false);
        break;
    default:
        oled_write_P(PSTR("Undef-"), false);
        snprintf(buf,sizeof(buf), "%u", layer_state);
        oled_write(buf, false);
    }
    oled_advance_page(true);
}

bool oled_task_keymap(void) {
  render_layer();
  render_rgblight(false);
  render_status();
  return false;
}

#endif
