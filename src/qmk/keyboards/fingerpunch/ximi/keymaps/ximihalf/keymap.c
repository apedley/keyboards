// #include "apedley.h"
// #include "qmk_rc.h"
// #include "rgb.h"
#include <qp.h>
#include "print.h"

#ifdef RAW_ENABLE
#    include "raw_hid.h"
#endif

#include QMK_KEYBOARD_H

// float sonic_ring_song[][2] = SONG(SONIC_RING);

// clang-format off

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// #define LOWER LT(_LOWER, KC_TAB)
// #define RAISE LT(_RAISE, KC_BSLS)
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
 * | `ESC |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB  | GUI  | ALT  |SHIFT | CTRL |  G   |                |  H   | CTRL |SHIFT | ALT  | GUI  | ' "  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | LSFT |  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  | RCTL |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | MUTE |           |LOWER | LCTL | SPC  |  | ENT  | RALT |RAISE |           | MUTE |
 *          `------'           `--------------------'  `--------------------'           `------'
 *
 *                             | DPI- |Scroll| DPI+ |  | DPI- |Reset | DPI+ |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */

    [_BASE] = LAYOUT_ximi(
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  RAISE, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  QK_BOOT,  RGB_MOD, QK_RBT,    _______, _______, _______, _______, _______, _______,
                 _______,       _______,  _______, _______,       _______, _______, _______,        _______,
                                _______, _______, _______,         _______, _______, _______
    ),


/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ` ~  |  !   |  @   |  #   |  $   |  %   |                |  ^   |  &   |  *   |  (   |  )   | - _  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |UPDIR | LEFT | DOWN |  UP  |RIGHT |UPDIR |                |      | - _  | = +  |  [   |  ]   | = +  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      | \ |  |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | BOOT |           |LOWER |      |      |  |      |      |      |           | BOOT |
 *          `------'           `--------------------'  `--------------------'           `------'
 *
 *                             |Mode- | RGB  |Mode+ |  |Mode- | RGB  |Mode+ |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_LOWER] = LAYOUT_ximi(
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
                 _______,       _______,  _______, _______,       _______, _______, _______,        _______,
                                _______, _______, _______,         _______, _______, _______
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ` ~  |  1   |  2   |  3   |  4   |  5   |                |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |  (   |  )   |M_XXX1|
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      | CAPS |  _   |  +   |  {   |  }   |                |      |      |      |  |   | DQT  |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | BOOT |           |      |      |      |  |      |      |      |           | BOOT |
 *          `------'           `--------------------'  `--------------------'           `------'
 *
 *                             | DPI- |Snipe | DPI+ |  |Mode- | RGB  |Mode+ |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_RAISE] = LAYOUT_ximi(
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  RGB_VAD,  KC_1, RGB_VAI,    _______, _______, _______, _______, _______, _______,
                 _______,       _______,  _______, _______,       _______, _______, _______,        _______,
                                _______, _______, _______,         _______, _______, _______
    ),
/* ,-----------------------------------------.                ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |Mode+ |RGB_SP|RGB_HU|RGB_SA|RGB_VA|                |FP_ACC|EE_CLR|      |      |TO(_BA|      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | RGB  |Mode- |RGB_SP|RGB_HU|RGB_SA|RGB_VA|                |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+----+--------+------'
 *          | BOOT |           |      |      |      |  |      |      |      |           |      |
 *          `------'           `--------------------'  `--------------------'           `------'
 *
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 *
 *                                                                               generated by [keymapviz] */
    [_ADJUST] =  LAYOUT_ximi(
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
    _______,  _______, _______,  _______,  _______, _______,    _______, _______, _______, _______, _______, _______,
                 _______,       _______,  _______, _______,       _______, _______, _______,        _______,
                                _______, _______, _______,         _______, _______, _______
    )
};
// clang-format on

#ifdef QUANTUM_PAINTER_ENABLE

painter_device_t lcd;

void lv_example_arc_2(void);
void lv_example_label(void);
#endif


// void rgb_matrix_underglow_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {
//   dprintf("setting under glow\n");
//     HSV hsv = {hue, sat, val};
//   if (hsv.v > rgb_matrix_get_val()) {
//     hsv.v = rgb_matrix_get_val();
//   }

//   RGB rgb = hsv_to_rgb(hsv);

//   for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//       if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW) &&
//                       i >= led_min &&
//                       i < led_max &&
//                       i != NO_LED) {
//           RGB_MATRIX_INDICATOR_SET_COLOR(i, rgb.r, rgb.g, rgb.b);
//       }
//   }
// }

// void rgb_matrix_underglow_all(uint8_t hue, uint8_t sat, uint8_t val) {
//     rgb_matrix_underglow_helper(hue, sat, val, 0, RGB_MATRIX_LED_COUNT);
// }

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse = true;

#ifdef QUANTUM_PAINTER_ENABLE

    lcd = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_0);
    qp_rect(lcd, 0, 0, 239, 319, 0, 255, 255, true);

    if (qp_lvgl_attach(lcd)) {
        // lv_example_arc_2();
        lv_example_label();
    }
#endif

// rgb_matrix_underglow_all(80, 200, 100);
}

#ifdef QUANTUM_PAINTER_ENABLE

static void set_angle(void* obj, int32_t v) {
    lv_arc_set_value(obj, v);
}

/**
 * Create an arc which acts as a loader.
 */
void lv_example_arc_2(void) {
    /*Create an Arc*/
    lv_obj_t* arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);  /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
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

void lv_example_label(void) {
    lv_obj_t* label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello world!");
    // lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_obj_center(label);
}
#endif
// #ifdef RAW_ENABLE

// #define QMK_RC_BUFFER_MAX 64
// uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

// void raw_hid_receive(uint8_t *data, uint8_t length) {
//   qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
// }
// #endif

// layer_state_t layer_state_set_keymap(layer_state_t state) {
//   state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

// #ifdef RAW_ENABLE
//   uint8_t highest_layer = get_highest_layer(state);
//   // uint8_t qmk_rc_layer_buffer[QMK_RC_BUFFER_MAX] = {0, 1, 0, 0, 0, 0, highest_layer, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0, 0, 0,   0, 0,   0, 0,  0, 0,0,   0, 0, 0};

//   // if (debug_enable) {
//   //   dprintf("raw_hid_send layer %d\n", highest_layer);
//   // }
//   // raw_hid_send(qmk_rc_layer_buffer, QMK_RC_BUFFER_MAX);

// uint8_t data[32];
// data[0] = get_highest_layer(layer_state|default_layer_state);

// switch (get_highest_layer(state)) {
//   case _RAISE:
//     data[0] = 1;
//     break;
//   case _LOWER:
//     data[0] = 2;
//     break;
//   case _ADJUST:
//     data[0] = 3;
//     break;
//   case _NUMPAD:
//     data[0] = 4;
//     break;
//   default:
//     data[0] = 0;
//     break;
//   }
// raw_hid_send(data, 32);
// #endif
// #ifdef RAW_ENABLE
// uint8_t layer_data[32];
// layer_data[0] = 1;
// layer_data[1] = get_highest_layer(state|default_layer_state);
// raw_hid_send(layer_data, 32);

// #endif // RAW_ENABLE

// #ifdef POINTING_DEVICE_ENABLE
// switch (get_highest_layer(state)) {
//   case _LOWER:
//   case _RAISE:
//     FP_SNIPE_ON

//   case _ADJUST:

//   case _NUMPAD:

//   default:

//   }

//   #endif
// //   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//   return state;
// }

// #ifdef OLED_ENABLE

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

// #endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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

// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(state)) {
//   case _BASE:
//     rgb_matrix_underglow_all(80, 200, 100);
//     break;
//   case _RAISE:
//     rgb_matrix_underglow_all(140, 200, 100);
//     break;
//   }

//   return state;

// }
