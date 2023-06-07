#include QMK_KEYBOARD_H

enum layer_number {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
  ADJUST = SAFE_RANGE,
  RGB_MODB
};

// clang-format off
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJ_SPC LT(_ADJUST, KC_SPC)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
    */

  [_BASE] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
      RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
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
      QK_BOOT,  _______, _______, _______, _______, _______,                  RGB_MODB, _______, KC_NUM,  _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                   RGB_MOD, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
      KC_CAPS, _______, _______, _______, _______, _______,                   RGB_RMOD,RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
      DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT
      )
};

// clang-format on

int RGB_current_mode;
layer_state_t currentLayerState;

layer_state_t layer_state_set_keymap(layer_state_t state) {
  currentLayerState = state;
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case RGB_MODB:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
  }
  return true;
}

#ifdef OLED_ENABLE
void render_layer(void) {

    char buf[10];

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    switch (get_highest_layer(layer_state)) {
    case _BASE:
        oled_write_P(PSTR("Base"), false);
        break;
    case _LOWER:
        oled_write_P(PSTR("Lower"), false);
        break;
    case _RAISE:
        oled_write_P(PSTR("Raise"), false);
        break;
    case _ADJUST:
        oled_write_P(PSTR("Adjust"), false);
        break;
    default:
        oled_write_P(PSTR("Undef-"), false);
        snprintf(buf,sizeof(buf), "%u", layer_state);
        oled_write(buf, false);
    }
    oled_advance_page(true);
}

bool oled_task_user(void) {
  render_layer();
  return false;
}

#endif

