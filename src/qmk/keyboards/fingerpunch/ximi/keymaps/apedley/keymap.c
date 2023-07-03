#include "apedley.h"
#include "qmk_rc.h"
#include "print.h"

#ifdef RAW_ENABLE
  #include "raw_hid.h"
#endif

#include QMK_KEYBOARD_H

// float sonic_ring_song[][2] = SONG(SONIC_RING);

enum custom_keycodes { DRAG_SCROLL = NEW_SAFE_RANGE };
// clang-format off

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD
};

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_BSLS)
#define NUMPAD MO(_NUMPAD)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC  |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |LOWER |HOME_A|HOME_S|HOME_D|HOME_F|  G   |                |  H   |HOME_J|HOME_K|HOME_L|HOME_S| QUOT |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | COMM | DOT  | SLSH | RGUI |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------|
 *          | MUTE |           | TAB  | LCTL | SPC  |  | ENT  | RALT |RAISE |           | MUTE |
 *          `------'           `--------------------'  `--------------------'           `------'
 *
 *                             ,--------------------.  ,--------------------.
 *                             | BTN1 |EE_CLR| BTN2 |  | WH_D |EE_CLR| WH_U |
 *                             `--------------------'  `--------------------'
 */

    [_BASE] = LAYOUT_ximi(
    KC_ESC,   KC_Q,     KC_W,   KC_E,     KC_R,   KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,      KC_BSPC,
    LOWER,    HOME_A,   HOME_S, HOME_D,   HOME_F, KC_G,            KC_H,    HOME_J,  HOME_K,   HOME_L, HOME_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,   KC_C,     KC_V,   KC_B,            KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,
                KC_MUTE,        KC_TAB,   KC_LCTL,KC_SPC,          KC_ENT,  KC_RALT, RAISE,          KC_MUTE,
                                RGB_RMOD, RGB_TOG,RGB_MOD,        RGB_RMOD, RGB_TOG,RGB_MOD
    ),

    [_LOWER] = LAYOUT_ximi(
    KC_GRV,   UPDIR,    KC_UP,   SELWORD,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,  KC_LEFT, KC_DOWN, KC_RGHT, DRAG_SCROLL, KC_TAB,    _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, M_XXX1,
    QK_BOOT,  RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, DB_TOGG,       _______, _______, _______, KC_BSLS, KC_QUOT, _______,
                 QK_BOOT,       QK_RBT,  QK_BOOT, KC_MAKE,       _______, _______, _______,        QK_BOOT,
                                KC_P1,   KC_P2,   KC_P3,         RGB_HUD, RGB_VAD, RGB_HUI
    ),

    [_RAISE] = LAYOUT_ximi(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_7,    KC_8,    KC_9,   KC_9,    KC_0,    _______,
    _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_4,    KC_5,    KC_6,   KC_LPRN, KC_RPRN, M_XXX1,
    QK_BOOT,  KC_CAPS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,        KC_1,    KC_2,    KC_3,   KC_PIPE,  KC_DQT, _______,
                 QK_BOOT,       _______, _______, _______,        QK_BOOT, KC_MAKE, _______,          QK_BOOT,
                                _______, _______, _______,        RGB_SPD, RGB_VAI, RGB_SPI
    ),

    [_ADJUST] =  LAYOUT_ximi(
    _______,  RGB_TOG, RGB_RMOD, RGB_MOD, _______, EE_CLR,       KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   _______,
    _______,  RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_BASE),    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  _______,
    _______,  RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,      KC_F11,  KC_F12,  _______, QK_RBT, QK_BOOT, _______,
                  QK_BOOT,       _______, _______, _______,      _______, _______, _______,        _______,
                                 _______, _______, _______,      _______, _______, _______
    ),

    [_NUMPAD] =  LAYOUT_ximi(
    _______,  _______, _______, _______, _______, _______,       KC_P7,   KC_P8,   KC_P9,  KC_PMNS,  _______,  KC_PSLS,
    _______,  _______, _______, _______, _______, _______,       KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  _______,  KC_PAST,
    _______,  _______, _______, _______, _______, _______,       KC_P1,   KC_P2,   KC_P3,  KC_PENT,  _______,  _______,
                _______,        _______, _______, _______,       KC_P0,   KC_P0,   KC_PDOT,       _______,
                                _______, _______, _______,       _______, _______, _______
    )
};
// clang-format on

#ifdef QUANTUM_PAINTER_ENABLE

painter_device_t lcd;

void lv_example_arc_2(void);

#endif

void keyboard_post_init_keymap(void) {
  // Customise these values to desired behaviour
  debug_enable = true;
  // debug_matrix=true;
  // debug_keyboard=true;
  debug_mouse = true;

#ifdef QUANTUM_PAINTER_ENABLE

  // pimoroni_trackball_set_rgbw(0, 0, 254, 0);
  lcd = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN,
                                  4, 0);
  qp_init(lcd, QP_ROTATION_0);
  qp_rect(lcd, 0, 0, 239, 319, 0, 255, 255, true);

  if (qp_lvgl_attach(lcd)) {
    lv_example_arc_2();
  }
#endif
}

#ifdef QUANTUM_PAINTER_ENABLE

static void set_angle(void *obj, int32_t v) { lv_arc_set_value(obj, v); }

/**
 * Create an arc which acts as a loader.
 */
void lv_example_arc_2(void) {
  /*Create an Arc*/
  lv_obj_t *arc = lv_arc_create(lv_scr_act());
  lv_arc_set_rotation(arc, 270);
  lv_arc_set_bg_angles(arc, 0, 360);
  lv_obj_remove_style(arc, NULL,
                      LV_PART_KNOB); /*Be sure the knob is not displayed*/
  lv_obj_clear_flag(arc,
                    LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
  lv_obj_center(arc);

  static lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_var(&a, arc);
  lv_anim_set_exec_cb(&a, set_angle);
  lv_anim_set_time(&a, 1000);
  lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
  lv_anim_set_repeat_delay(&a, 500);
  lv_anim_set_values(&a, 0, 100);
  lv_anim_start(&a);
}
#endif


#ifdef RAW_ENABLE

#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}
#endif


layer_state_t layer_state_set_keymap(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

//   #ifdef RAW_ENABLE
//   uint8_t highest_layer = get_highest_layer(state);
//   // uint8_t qmk_rc_layer_buffer[QMK_RC_BUFFER_MAX] = {0, 1, 0, 0, 0, 0, highest_layer, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0};

//   // if (debug_enable) {
//   //   dprintf("raw_hid_send layer %d\n", highest_layer);
//   // }
//   // raw_hid_send(qmk_rc_layer_buffer, QMK_RC_BUFFER_MAX);

//   uint8_t data[32];
//   data[2] = highest_layer;
//   raw_hid_send(data, 32);
// #endif

    // switch (get_highest_layer(state)) {
    // case _RAISE:
    //   tap_code16(KC_F14); break;
    // case _LOWER:
    //   tap_code16(KC_F15); break;
    // case _ADJUST:
    //   tap_code16(KC_F16); break;
    // case _NUMPAD:
    //   tap_code16(KC_F17); break;
    // default:
    //   tap_code16(KC_F13); break;
    // }
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

#ifdef OLED_ENABLE

// void render_layer(void) {

//     char buf[10];

//   // Define layers here, Have not worked out how to have text displayed for
//   each layer. Copy down the number you see and add a case for it below
//     switch (get_highest_layer(layer_state)) {
//     case _BASE:
//         oled_write_P(PSTR("Base"), false);
//         break;
//     case _RAISE:
//         oled_write_P(PSTR("Raise"), false);
//         break;
//     case _LOWER:
//         oled_write_P(PSTR("Lower"), false);
//         break;
//     case _ADJUST:
//         oled_write_P(PSTR("Adjust"), false);
//         break;
//     default:
//         oled_write_P(PSTR("Undef-"), false);
//         snprintf(buf,sizeof(buf), "%u", layer_state);
//         oled_write(buf, false);
//     }
//     oled_advance_page(true);
// }
// static void render_logo(void) {
//     static const char PROGMEM raw_logo[] = {
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04,
//         0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08,
//         0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e,
//         0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//         0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20,
//         0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f,
//         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//     };
//     oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }

// bool oled_task_keymap(void) {
//   // render_layer();
//   // render_rgbmatrix(false);
//   // render_status();
//   render_logo();
//   return false;
// }

#endif // OLED_ENABLE

#ifdef POINTING_DEVICE_ENABLE

#endif // POINTING_DEVICE_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

#ifdef AUDIO_ENABLE
#endif // AUDIO_ENABLE
  }
  return true;
}
