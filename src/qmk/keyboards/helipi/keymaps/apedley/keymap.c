// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "apedley.h"
#include QMK_KEYBOARD_H
enum layer_number {
  _BASE,
  _FN
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *   ,------------
   *   |MO FN|TOGFN|
   *   |-----+-----+-----+-----+-----.
   *   | Esc | Del | MUTE| VOLD| VOLU|
   *   |-----+-----+-----+-----+-----|
   *   | Num |  /  |  *  |  -  | HOME|
   *   |-----+-----+-----+-----+-----|
   *   |  7  |  8  |  9  |  +  | END |
   *   |-----+-----+----+------+-----|
   *   |  4  |  5  |  6  | Ent | PGUP|
   *   |-----+-----+-----+-----+-----|
   *   |  1  |  2  |  3  |Shift| PGDN|
   *   |-----+-----+-----+-----+-----|
   *   | Ctrl|  0  |  .  | ALT | GUI |
   *   `-----------------------------'
  //  */


  [_BASE] = LAYOUT(
    MO(_FN),  TG(_FN),
    KC_ESC,   KC_DEL,   KC_MUTE,  KC_VOLD,  KC_VOLU,
    KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_HOME,
    KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_END,
    KC_P4,    KC_P5,    KC_P6,    KC_PENT,  KC_PGUP,
    KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  KC_PGDN,
    KC_RCTL,  KC_P0,    KC_PDOT,  KC_RALT,  KC_RGUI
  ),
  [_FN] = LAYOUT(
    QK_BOOT,  QK_BOOT,
    RGB_MOD,  RGB_TOG,  _______,  KC_MPRV,  KC_MNXT,
    RGB_VAI,  RGB_HUI,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______
  )
};

#ifdef OLED_ENABLE

bool oled_task_keymap(void) {
  render_status();
  render_rgblight(false);
  return false;
}

#endif
