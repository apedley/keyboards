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
      KC_Z,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7
    )
};

// clang-format on