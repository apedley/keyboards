/* Copyright (C) 2022 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
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


// KeymapCEditor: kbd4x

#include QMK_KEYBOARD_H
#include "apedley.h"
#include "print.h"
#include "qmk_rc.h"
#include "raw_hid.h"

enum customs {
    SEND_RAW = NEWER_SAFE_RANGE,
    NUMPAD_OFF,
    NUMPAD_ON,
    // Others...
};

enum mk47_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD
};
// enum mk47_keycodes {
//   QWERTY = SAFE_RANGE,
//   COLEMAK,
//   DVORAK,
//   PLOVER,
//   BACKLIT,
//   EXT_PLV
// };
// #define LOWER LT(_LOWER, KC_TAB)
// #define RAISE LT(_RAISE, KC_ENT)
#define LOWER TT(_LOWER)
#define RAISE TT(_RAISE)

	// 	KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
	// 	KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT,
	// 	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
	// 	KC_LCTL, KC_LGUI, KC_LALT, MO(1), QK_LEAD, KC_SPC, MO(2), MO(3), KC_LEFT, KC_DOWN, KC_RGHT),

	// 	KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, RGB_MOD,
	// 	KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RGB_VAI, KC_EQUAL,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, KC_TRNS),

	// 	QK_BOOT, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
	// 	KC_CAPS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
	// 	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP, KC_SLSH,
	// 	KC_LCTL, KC_NO, KC_LALT, KC_DEL, KC_PGDN, KC_SPC, KC_PGUP, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT),

	// 	QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_MAKE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | GUI  | Alt  | Ldr  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT( /* Base */
        QK_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        LT(_NUMPAD, KC_TAB),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, QK_LEAD, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   {  |   }  |  |   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   +  | Home |  End |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Play |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT( /* LOWER */
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,     KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP,    KC_PGDN,    KC_HOME, KC_END,  _______,
        _______, _______, _______, TG(_NUMPAD), _______,      _______,     _______,    _______,    KC_VOLD, KC_VOLU, _______
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      | MoClk|Pg Up |Pg Dn |MoRCk |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | MLeft| MDown| MUp  | MRgt |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT( /* RAISE */
        KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINUS,    KC_EQUAL,    KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGUP, KC_PGDN, KC_HOME, KC_END, _______,
        _______, _______, _______, TG(_NUMPAD), _______,      _______,     _______,    _______,    _______, _______, _______
    ),


    /* Adjust (Lower + Raise)
    *                      v------------------------RGB CONTROL--------------------v
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|      | RGB  |RGBMOD| RGBSp| Hue  | Mac1R| Mac1P| Mac2R| Mac2P| SEC1 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Make |      | SAT  | HUE  | SpdD | ValD |      |      |      |      | SEC2 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      | SEC3 |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT(
		KC_ESC,  QK_BOOT, _______, RGB_TOG, RGB_MOD, RGB_SPI, RGB_VAI,    _______, _______, _______, _______, M_XXX1,
        _______, KC_MAKE, _______, RGB_SAI, RGB_HUI, RGB_SPD, RGB_VAD,    _______, _______, _______, _______, M_XXX2,
        _______, DB_TOGG, _______, _______, _______, _______, TG(_NUMPAD), _______, _______, _______, _______, M_XXX3,
        _______, _______, _______, TG(_NUMPAD), _______,      _______    ,    _______, _______, _______, _______, _______
    ),


    /* Numpad
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMPAD] = LAYOUT(
        _______, UPDIR,   KC_UP,   SELWORD,     _______, _______, _______, KC_KP_7, KC_KP_8,  KC_KP_9,     DM_REC1, DM_PLY1,
        _______, KC_LEFT, KC_DOWN, KC_RGHT,     _______, _______, _______, KC_KP_4, KC_KP_5,  KC_KP_6,     DM_REC2, DM_PLY2,
        _______, KC_VOLD, KC_VOLU, KC_MUTE,     _______, _______, _______, KC_KP_1, KC_KP_2,  KC_KP_3,     _______, _______,
        _______, _______, _______, TG(_NUMPAD),     _______,      _______, KC_KP_0,KC_KP_DOT, KC_KP_ENTER, _______, _______
    )
};
// clang-format on

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}


// void raw_hid_send(uint8_t *data, size_t length) {
//     uint8_t buffer[RAW_EPSIZE] = {0};
//     uint8_t packets = length / RAW_EPSIZE;
//     uint8_t remaining_packets = length % RAW_EPSIZE;
//     for (int i = 0; i < packets; i++) {
//         memcpy(buffer, data + (i * RAW_EPSIZE), RAW_EPSIZE);
//         chnWrite(&drivers.raw_driver.driver, buffer, RAW_EPSIZE);
//     }
//     if (remaining_packets > 0) {
//         // Clear the buffer
//         memset(buffer, '\0', RAW_EPSIZE);
//         memcpy(buffer, data + (packets * RAW_EPSIZE), remaining_packets);
//         chnWrite(&drivers.raw_driver.driver, buffer, RAW_EPSIZE);
//     }
// }
#endif

layer_state_t currentLayerState;

layer_state_t layer_state_set_keymap(layer_state_t state) {
  currentLayerState = state;


#ifdef RAW_ENABLE
//   uint8_t highest_layer = get_highest_layer(currentLayerState);
  uint8_t qmk_rc_layer_buffer[QMK_RC_BUFFER_MAX] = {};
  qmk_rc_layer_buffer[0] = get_highest_layer(currentLayerState);

  raw_hid_send(qmk_rc_layer_buffer, QMK_RC_BUFFER_MAX);
#endif

  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void rgb_matrix_layer_highlight_changed(uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(currentLayerState);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                rgb_matrix_set_color(index, r, g, b);
            }
        }
    }
}
void rgb_matrix_highlight_border(uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    for (uint8_t first_row_col = 0; first_row_col < MATRIX_COLS; ++first_row_col) {
        uint8_t index = g_led_config.matrix_co[0][first_row_col];
        rgb_matrix_set_color(index, r, g, b);
    }
    for (uint8_t row = 1; row < MATRIX_ROWS; ++row) {
        uint8_t zero_index = g_led_config.matrix_co[row][0];
        uint8_t last_index = g_led_config.matrix_co[row][MATRIX_COLS-1];


        rgb_matrix_set_color(zero_index, r, g, b);
        rgb_matrix_set_color(last_index, r, g, b);
    }
}

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            // rgb_matrix_layer_helper(RGB_ORANGE, LED_FLAG_MODIFIER, led_min, led_max);

            // for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            //     uint8_t index = g_led_config.matrix_co[row][0];
            //     uint8_t index_last = g_led_config.matrix_co[row][MATRIX_COLS-1];
            //     rgb_matrix_set_color(index, RGB_WHITE);
            //     rgb_matrix_set_color(index_last, RGB_WHITE);
            // }
            rgb_matrix_highlight_border(RGB_CYAN, led_min, led_max);
            break;
        case _RAISE:
            // rgb_matrix_layer_helper(RGB_PURPLE, LED_FLAG_MODIFIER, led_min, led_max);
            // uint8_t index = g_led_config.matrix_co[0][1];
            // uint8_t index_second = g_led_config.matrix_co[0][2];

            // uint8_t index_last = g_led_config.matrix_co[0][MATRIX_COLS-2];
            // uint8_t index_second_last = g_led_config.matrix_co[0][MATRIX_COLS-3];
            // rgb_matrix_set_color(index, RGB_WHITE);
            // rgb_matrix_set_color(index_last, RGB_WHITE);
            // rgb_matrix_set_color(index_second, RGB_WHITE);
            // rgb_matrix_set_color(index_second_last, RGB_WHITE);


            // for (uint8_t col = 1; col < MATRIX_COLS-1; ++col) {
            //     uint8_t index = g_led_config.matrix_co[0][col];
            //     rgb_matrix_set_color(index, RGB_WHITE);
            // }
            rgb_matrix_highlight_border(RGB_MAGENTA, led_min, led_max);
            break;
        case _ADJUST:
            rgb_matrix_highlight_border(RGB_WHITE, led_min, led_max);
            break;
        case _NUMPAD:
            rgb_matrix_layer_highlight_changed(RGB_YELLOW, led_min, led_max);
            break;
    }
    return true;
}
