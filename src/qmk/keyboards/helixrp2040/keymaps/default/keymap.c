#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  TEST_MACRO_KB = SAFE_RANGE,
};

// clang-format off
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define ADJ_SPC LT(_ADJUST, KC_SPC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
    */

  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      // QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      // RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                      RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
      // RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,                      RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_PGUP, KC_PGDN,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      ADJUST,  KC_LCTL, KC_LGUI, KC_LALT, KC_LBRC, LOWER,  KC_SPC,  ADJ_SPC,  RAISE,   KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),
  [_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_F12,  KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______,                   KC_MINUS,KC_EQUAL,_______, _______, _______, KC_F11,
      _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_PGUP,                   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN2,
      _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_HOME, KC_END,  KC_HOME,  KC_END, KC_HOME, KC_END,  _______, _______, KC_DEL,  _______,
      _______, _______, _______, _______, KC_LPRN, _______, KC_ENT,   _______,_______, KC_RPRN, _______, _______, _______, _______
      ),

  /* Raise
   */
  [_RAISE] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_DEL,
      KC_F12,  _______, KC_UP,   _______, KC_PGUP, _______,                   KC_UNDS, KC_PLUS, _______, _______,  _______, KC_F11,
      _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_HOME,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, KC_PGUP, KC_PGDN, _______, _______,  _______, _______,
      _______, _______, _______, _______, KC_LPRN, _______, KC_ENT,   _______,_______, KC_RPRN, _______, _______,  _______, _______
      ),


  /* Adjust
   */
  [_ADJUST] =  LAYOUT(
      QK_BOOT,  _______, _______, _______, _______, _______,                  _______, _______, KC_NUM,  KC_CAPS, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                   RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
      KC_CAPS, _______, _______, _______, _______, _______,                   RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
      DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
      )
};

// clang-format on



