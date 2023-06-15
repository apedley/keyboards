
#include "apedley.h"
#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _FN,
  _FN2
};

// clang-format off

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)

#define FN1 TT(_FN)
#define FN2 TT(_FN2)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *        ,-----------------------------------------.
   *        | Num  |   /  |   *  |   -  | Paus | Copy |
   *        |------+------+------+------+------+------|
   *        |   7  |   8  |   9  |   +  | VolU |Paste |
   *        |------+------+------+------+------+------|
   *        |   4  |   5  |   6  | Enter| Mute |AltRpt|
   * ,------+------+------+------+------+------+------|
   * |  Fn2 |   1  |   2  |   3  | Shift| VolD | Rpt  |
   * /------+------+------+------+------+------+------|
   * |  Fn1 | Ctrl |   0  |   .  | Alt  | Fn1  | Fn2  |
   * -------------------------------------------------'
   */

  [_BASE] = LAYOUT(
              KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  QK_REP,  QK_AREP,
              KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_VOLU, KC_MNXT,
              KC_P4,    KC_P5,    KC_P6,    KC_PENT,  KC_MUTE, KC_MPLY,
    FN2,      KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  KC_VOLD, KC_MPRV,
    FN1,      KC_RCTL, KC_P0,     KC_PDOT,  KC_RALT,  FN1,     FN2
  ),
  [_FN] = LAYOUT(
              KC_CAPS, _______, _______, _______, _______, KC_HOME,
              KC_BTN2, KC_MS_U, KC_BTN3, KC_WH_U, KC_WFWD, KC_PGUP,
              KC_MS_L, KC_BTN1, KC_MS_R, KC_WH_D, KC_WREF, KC_PGDN,
    _______,  KC_BTN4, KC_MS_D, KC_BTN5, _______, KC_WBAK, KC_END,
    _______,  _______, _______, _______, _______, _______, _______
  ),
  [_FN2] = LAYOUT(
              RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
              RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
              _______, _______, _______, _______, _______, _______,
    _______,  QK_BOOT, _______, _______, _______, _______, _______,
    _______,  KC_MAKE, _______, _______, _______, _______, _______
  )
};

// clang-format on

#ifdef OLED_ENABLE
void render_layer(void) {

    char buf[10];

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("Default"), false);
        break;
    case _FN:
        oled_write_P(PSTR("Fn1"), false);
        break;
    case _FN2:
        oled_write_P(PSTR("Fn2"), false);
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
  render_rgbmatrix(false);
  render_status();
  return false;
}

#endif

