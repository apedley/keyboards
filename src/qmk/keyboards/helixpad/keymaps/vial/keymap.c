#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _FN1,
  _FN2
};

#define FN1 TT(_FN1)
#define FN2 TT(_FN2)
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
    KC_ESC,   KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,  KC_VOLU,
    KC_SPACE, KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_MUTE,
    KC_SPACE, KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_VOLD,
    TT(_FN2), KC_P1,    KC_P2,    KC_P3,    KC_PENT,  KC_RSFT, TT(_FN2),
    TT(_FN1), KC_P0,    KC_P0,    KC_PDOT,  KC_RALT,  KC_RCTL, TT(_FN1)
  ),
  [_FN1] = LAYOUT(
    KC_ESC,   KC_CAPS, _______, _______, _______, KC_MNXT,
    _______,  _______, _______, _______, _______, KC_MPLY,
    _______,  _______, _______, _______, _______, KC_MPRV,
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT(
    KC_ESC,   KC_CAPS, _______, _______, _______, _______,
    RGB_MOD,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
    RGB_RMOD, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
    _______,  _______, _______, _______, _______, _______, _______,
    _______,  _______, _______, _______, _______, _______, _______
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
    case _FN1:
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
  // render_rgblight(false);
  // render_rgbmatrix(false);
  // render_status();
  return false;
}

#endif

