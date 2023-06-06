// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *   ,--------------
   *   |   A  |   B  |
   *   |------+------+------+------+------.
   *   |   C  |   C  |   C  |   C  |   C  |
   *   |------+---- -+---- -+------+------|
   *   |   H  |   H  |   H  |   H  |   H  |
   *   |------+---- -+---- -+------+------|
   *   |   M  |   M  |   M  |   M  |   M  |
   *   |------+---- -+---- -+------+------|
   *   |   R  |   R  |   R  |   R  |   R  |
   *   |------+---- -+---- -+------+------|
   *   |   W  |   W  |   W  |   W  |   W  |
   *   |------+---- -+---- -+------+------|
   *   |   2  |   2  |   2  |   2  |   2  |
   *   `----------------------------------'
  //  */


  [0] = LAYOUT(
    KC_A,   KC_B,
    KC_C,   KC_D,   KC_E,   KC_F,   KC_G,
    KC_H,   KC_I,   KC_J,   KC_K,   KC_L,
    KC_M,   KC_N,   KC_O,   KC_P,   KC_Q,
    KC_R,   KC_S,   KC_T,   KC_U,   KC_V,
    KC_W,   KC_X,   KC_Y,   KC_Z,   KC_1,
    KC_2,   KC_3,   KC_4,   KC_5,   KC_6
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {

  static const char helix_logo[][3][8] PROGMEM = {
    {
      {0x80,0x81,0x82,0x83,0x84,0x85,0x86,0},
      {0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0},
      {0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0},
    }
  };

  oled_write_P(PSTR("\n"), false);
  oled_write_P(helix_logo[0][0], false);
  oled_write_P(PSTR("\n"), false);
  oled_write_P(helix_logo[0][1], false);
  oled_write_P(PSTR("\n"), false);
  oled_write_P(helix_logo[0][2], false);
}

bool oled_task_user(void) {
  render_logo();
  return false;
}
#endif
