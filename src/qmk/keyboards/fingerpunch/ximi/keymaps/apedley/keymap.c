#include "apedley.h"
#include "qmk_rc.h"
#include "print.h"

#ifdef RAW_ENABLE
  #include "raw_hid.h"
#endif

#include QMK_KEYBOARD_H

// float sonic_ring_song[][2] = SONG(SONIC_RING);


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _MOUSE,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MOUSE,
};

// #define LOWER LT(_LOWER, KC_TAB)
// #define RAISE LT(_RAISE, KC_BSLS)
#define RAISEZ LT(_RAISE, KC_Z)
#define LOWRQT LT(_LOWER, KC_QUOT)
#define NUMPAD MO(_NUMPAD)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define CTL_D LCTL_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define SFT_J RSFT_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define ALT_K RALT_T(KC_K)
#define CTL_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | `ESC |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  | GUI  | ALT  | CTRL |SHIFT |  G   |                |  H   |SHIFT | CTRL | ALT  | GUI  |LOWRQT|
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LSFT |RAISEZ|  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  | RSFT |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | Mute |           |LOWER |Space | RCTL |  | LALT | ENT  |RAISE |           | Mute |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             | Prev | Play | Next |  |Mouse5|Mouse3|Mouse4|
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */

    [_BASE] = LAYOUT_ximi(
    QK_GESC,   KC_Q,     KC_W,   KC_E,     KC_R,   KC_T,            KC_Y,    KC_U,    KC_I,   KC_O,   KC_P,      KC_BSPC,
    KC_TAB,    HOME_A,    HOME_S,   CTL_D,   SFT_F, KC_G,            KC_H,    SFT_J,  CTL_K,    HOME_L,   HOME_SCLN, LOWRQT,
    KC_LSFT,  RAISEZ,     KC_X,   KC_C,     KC_V,   KC_B,            KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,
                KC_MUTE,        LOWER,   KC_SPC, KC_RCTL,          KC_LALT,  KC_ENT, RAISE,          KC_MUTE,
                                KC_MPRV, KC_MPLY, KC_MNXT,        KC_BTN5, KC_BTN3, KC_BTN4
    ),


/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ` ~  |  1   |  2   |  3   |  4   |  5   |                |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |UPDIR | - _  | = +  |  [   |  (   |  {   |                |  }   |  )   |  ]   | - _  | = +  | \ |  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | BOOT |           |      |      |      |  |      |      |      |           |      |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             |Mode- | RGB  |Mode+ |  | DPI- |Reset | DPI+ |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_LOWER] = LAYOUT_ximi(
    KC_GRV,   KC_1,    KC_2,   KC_3,     KC_4,    KC_5,       KC_6,    KC_7,    KC_8,     KC_9,    KC_0,   KC_DEL,
    UPDIR,    KC_MINS, KC_EQL, KC_LBRC,  KC_LPRN, KC_LCBR,    KC_RCBR, KC_RPRN, KC_RBRC,  KC_MINS, KC_EQL, KC_BSLS,
    KC_F11,   KC_F1,   KC_F2,  KC_F3,    KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10, KC_F12,

                 QK_BOOT,       _______,  _______, _______,   _______, _______, _______,        _______,
                                RGB_RMOD, RGB_TOG,RGB_MOD,    FP_POINT_DPI_DN, FP_POINT_DPI_RESET,FP_POINT_DPI_UP
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | F11  | HOME |  UP  | END  | PGUP |      |                |Mouse1|Mouse2|WhlDn |WhlUp |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |Select| LEFT | DOWN |RIGHT | PGDN |Select|                |MouseL|MouseD|MouseU|MouseR|  UP  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |  _   |  +   |  {   |  }   |                |Mouse4|Mouse5|      | LEFT | DOWN |RIGHT |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          |      |           |      |      |      |  |      |      |      |           | BOOT |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             | Snp- | SnpR | Snp+ |  |Mode- | RGB  |Mode+ |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_RAISE] = LAYOUT_ximi(
    KC_F11,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP, _______,    KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_U, _______, _______,
    SELWORD,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, SELWORD,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_UP,    _______,
    _______,  _______, KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR,    KC_BTN4, KC_BTN5, _______, KC_LEFT, KC_DOWN, KC_RIGHT,
                 _______,       _______, _______, _______,     _______, _______, _______,          QK_BOOT,
                                FP_SNIPE_DPI_DN, FP_SNIPE_DPI_RESET, FP_SNIPE_DPI_UP,       RGB_RMOD, RGB_TOG,RGB_MOD
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |Mode+ | Spd+ | Hue+ | Sat+ | Val+ |                |Accel |MemClr|      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | RGB  |Mode- | Spd- | Hue- | Sat- | Val- |                | CAPS |      |      |      | DPI- | DPI+ |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          |      |           |      |      |      |  |      |      |      |           |      |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_ADJUST] =  LAYOUT_ximi(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,       KC_F8,   KC_F9,   KC_F10,   KC_F12,
    _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,    FP_ACCEL_TOG, EE_CLR, _______, _______, _______, _______,
    RGB_TOG, RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,    KC_CAPS,  _______,    _______, _______, FP_POINT_DPI_DN, FP_POINT_DPI_UP,
                  _______,     _______, _______, _______,    _______, _______, _______,        _______,
                               _______, _______, _______,    _______, _______, _______
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                | Num7 | Num8 | Num9 | Num- | Num/ |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                | Num4 | Num5 | Num6 | Num+ | Num* |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                | Num1 | Num2 | Num3 |NumEnt|      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          |      |           |      |      |      |  |      | Num0 | Num. |           |      |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_NUMPAD] =  LAYOUT_ximi(
    _______,  _______, _______, _______, _______, _______,       KC_P7,   KC_P8,   KC_P9,  KC_PMNS,  KC_PSLS,  _______,
    _______,  _______, _______, _______, _______, _______,       KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  KC_PAST,  _______,
    _______,  _______, _______, _______, _______, _______,       KC_P1,   KC_P2,   KC_P3,  KC_PENT,  _______,  _______,
                _______,        _______, _______, _______,       _______, KC_P0,   KC_PDOT,       _______,
                                _______, _______, _______,       _______, _______, _______
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |Mouse1|Mouse2|WhlDn |WhlUp |Scrl+ | Snp+ |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      | Zoom |                |MouseL|MouseD|MouseU|MouseR|Scrl- | Snp- |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |ClsTab|PrvTab|NxTab |                |Mouse4|Mouse5|      |      | DPI- | DPI+ |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          |      |           |      |      |      |  |      |SnpTog|      |           |      |         
 *          `------'           `--------------------'  `--------------------'           `------'           
 *
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_MOUSE] =  LAYOUT_ximi(
    _______,  _______, _______, _______, _______, _______,        KC_BTN1, KC_BTN2,      KC_WH_D, KC_WH_U, FP_SCROLL_DPI_UP, FP_SNIPE_DPI_UP,
    _______,  _______, _______, _______, _______, FP_ZOOM_TOG,    KC_MS_L, KC_MS_D,      KC_MS_U, KC_MS_R, FP_SCROLL_DPI_DN, FP_SNIPE_DPI_DN,
    // _______,  _______, _______, _______, _______, FP_ZOOM_TOG,    FP_SNIPE_TOG, _______, _______, FP_SCROLL_DPI_DN, FP_SNIPE_DPI_DN, FP_POINT_DPI_DN,
    _______,  _______, _______, AP_TCLS, AP_TPRV, AP_TNXT,        KC_BTN4, KC_BTN5,      _______, _______,  FP_POINT_DPI_DN, FP_POINT_DPI_UP,
                _______,        _______, _______, _______,        _______, FP_SNIPE_TOG, _______,      _______,
                                _______, _______, _______,        _______, _______, _______
    )
};
// clang-format on

void keyboard_post_init_keymap(void) {
  // Customise these values to desired behaviour
  debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse = true;

}

#ifdef RAW_ENABLE

#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}
#endif


layer_state_t layer_state_set_keymap(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

  #ifdef RAW_ENABLE
  uint8_t layer_data[32];
  layer_data[0] = 1;
  layer_data[1] = get_highest_layer(state|default_layer_state);
  raw_hid_send(layer_data, 32);

  #endif // RAW_ENABLE

  #ifdef POINTING_DEVICE_ENABLE

  #endif
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LOWER:
    if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case RAISE:
    if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
    break;
  case ADJUST:
    if (record->event.pressed) {
        layer_on(_ADJUST);
    } else {
        layer_off(_ADJUST);
    }
    return false;
    break;
#ifdef AUDIO_ENABLE
#endif // AUDIO_ENABLE

  }
  return true;
}

#if defined(RGB_MATRIX_ENABLE) && defined(RGB_MATRIX_UNDERGLOW_SOLID_COLOR)

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
  HSV hsv = {
    #ifdef RGB_MATRIX_UNDERGLOW_HUE
      .h = RGB_MATRIX_UNDERGLOW_HUE,
    #else
      .h = 191,
    #endif
      .s = 255,
    #ifdef RGB_MATRIX_UNDERGLOW_VAL
      .v = RGB_MATRIX_UNDERGLOW_VAL,
    #else
      .v = 255,
    #endif
  };

//   #ifdef RGB_MATRIX_UNDERGLOW_MAXIMUM_BRIGHTNESS
//     hsv.v = RGB_MATRIX_UNDERGLOW_MAXIMUM_BRIGHTNESS;
//   #else

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
//   #endif

  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
  return false;
}
#endif // RGB_MATRIX_ENABLE && RGB_MATRIX_UNDERGLOW_SOLID_COLOR
