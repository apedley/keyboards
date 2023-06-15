#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _FN1
};

#define FN1 TT(_FN1)
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default layer
   *        ,-----------------------------------------.
   *        |   6  |   7  |   8  |   9  |   0  | Bksp |
   *        |------+------+------+------+------+------|
   *        |   Y  |   U  |   I  |   O  |   P  |  \   |
   *        |------+------+------+------+------+------|
   *        |   H  |   J  |   K  |   L  |   ;  |  '   |
   * ,------+------+------+------+------+------+------|
   * |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * /------+------+------+------+------+------+------|
   * |  SPC |  ALT |  CTL | Left | Down |  Up  |Right |
   * -------------------------------------------------'
   */

  [_BASE] = LAYOUT(
              KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_1,    KC_2,
              KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_VOLU, QK_REP,
              KC_P4,    KC_P5,    KC_P6,    KC_PENT,  KC_MUTE, QK_AREP,
    FN1,      KC_P1,    KC_P2,    KC_P3,    KC_RSFT,  KC_VOLD, QK_REP,
    FN1,      KC_RCTL,  KC_P0,     KC_PDOT,  KC_RALT,  FN1,     FN1
  ),
  [_FN1] = LAYOUT(
              KC_CAPS, _______, _______, _______, _______, _______,
              RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
              RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
    _______,  _______, _______, _______, _______, _______, QK_RBT,
    _______,  _______, _______, _______, _______, _______, QK_BOOT
  )
};

// clang-format on
