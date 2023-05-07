/* Copyright (C) 2022 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "apedley.h"
#include "qmk_rc.h"
#include "print.h"
#include "raw_hid.h"

enum layers{
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};
enum mk47_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT( /* Base */
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT( /* LOWER */
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
        _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT( /* RAISE */
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),


    /* Adjust (Lower + Raise)
    *                      v------------------------RGB CONTROL--------------------v
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT(
		_______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
        _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  PLOVER,  _______,
        _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
// clang-format on

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
//     if (get_highest_layer(layer_state) > 0) {
//     uint8_t layer = get_highest_layer(layer_state);
//     uint8_t _r = 0;
//     uint8_t _g = 0;
//     uint8_t _b = 0;

//     switch(layer) {
//         case _LOWER:
//             _r = 255;
//             break;
//         case _RAISE:
//             _g = 255;
//             break;
//         case _ADJUST:
//             _b = 255;
//             break;
//         default:
//             break;
//     }

//     for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
//         for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
//             uint8_t index = g_led_config.matrix_co[row][col];

//             if (index >= led_min && index < led_max && index != NO_LED &&
//             keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
//                 rgb_matrix_set_color(index, _r, _g, _b);
//             }
//         }
//     }
//     return false;
// }
