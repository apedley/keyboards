#include QMK_KEYBOARD_H

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

    [0] = LAYOUT(
                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      RGB_MOD,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      RGB_TOG,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_M_B, RGB_M_R
    )
};

// clang-format on
