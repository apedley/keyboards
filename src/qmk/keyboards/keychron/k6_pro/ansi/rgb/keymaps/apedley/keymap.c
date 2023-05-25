/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// KeymapCEditor: YD68 USKeyboard ANSI 104

#include QMK_KEYBOARD_H
#include "apedley.h"
#include "qmk_rc.h"
#include "print.h"
#include "raw_hid.h"


// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2,
  NUMPAD,
};

enum customs {
    SEND_RAW = NEWER_SAFE_RANGE,
    NUMPAD_OFF,
    NUMPAD_ON,
    // Others...
};

/*

 __  __  __  __  __  __  __  __  __  __  __  __  __  ______  __
|  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||      ||  |
|__||__||__||__||__||__||__||__||__||__||__||__||__||______||__|
 ____  __  __  __  __  __  __  __  __  __  __  __  __  ____  __
|    ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||    ||  |
|____||__||__||__||__||__||__||__||__||__||__||__||__||____||__|
 _____  __  __  __  __  __  __  __  __  __  __  __  _______  __
|     ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||       ||  |
|_____||__||__||__||__||__||__||__||__||__||__||__||_______||__|
 _______  __  __  __  __  __  __  __  __  __  __  _____  __  __
|       ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||     ||  ||  |
|_______||__||__||__||__||__||__||__||__||__||__||_____||__||__|
 ___  ___  ___  _______________________  __  __  __  __  __  __
|   ||   ||   ||                       ||  ||  ||  ||  ||  ||  |
|___||___||___||_______________________||__||__||__||__||__||__|

*/


#define TOGNP TG(NUMPAD)
// enum td_keycodes {
//   TD_ESC_CAPS
// };



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[MAC_BASE] = LAYOUT_ansi_68(
     QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, QK_LEAD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     MO(2),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_RCTL,
     KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                       KC_RCMMD,MO(MAC_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[WIN_BASE] = LAYOUT_ansi_68(
     QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, QK_LEAD,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, KC_HOME,
     MO(3),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,  KC_PGUP,
     KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_RCTL,
     KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                       KC_RALT, MO(WIN_FN1),MO(FN2), KC_LEFT,  KC_DOWN, KC_RGHT),

[MAC_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,  _______,
     _______,  UPDIR, KC_UP,   SELWORD,   SELLINE,  _______,  _______,  _______,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  M_XXX2,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,            _______,  KC_PGDN,
     _______,  KC_VOLD, KC_VOLU,  KC_MUTE,  _______,  _______,  _______,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,  _______,
     KC_MAKE,  UPDIR, KC_UP,   SELWORD,   SELLINE,  _______,  _______,  _______,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  M_XXX2,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,  _______,            KC_PGDN,
     _______,  KC_VOLD, KC_VOLU,  KC_MUTE,  _______,  _______,  _______,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  _______,  _______,  _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  _______,  _______,  _______),



[FN2] = LAYOUT_ansi_68(
     QK_BOOT,  BT_HST1,    BT_HST2,    BT_HST3,    BAT_LVL,    _______,    _______,    _______,    TOGNP,    RGB_SAI,    RGB_HUI ,   RGB_VAI, RGB_SPI,  RGB_TOG,  RGB_MOD,
     KC_MAKE,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
     QK_RBT,  _______,     _______,     _______,     _______,    _______,     _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,
     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  SEND_RAW,  _______,            KC_VOLU,  _______,
     _______,  _______,  _______,                                _______,                      _______,  _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT),

[NUMPAD] = LAYOUT_ansi_68(
     _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    TOGNP,    KC_KP_SLASH,    KC_KP_ASTERISK ,   KC_KP_MINUS, _______,  _______,  _______,
     _______,  _______,  _______,       _______,      _______,   _______,  _______,     _______,    KC_KP_7,     KC_KP_8,  KC_KP_9,  KC_KP_PLUS,  _______,  _______,  _______,
     _______,  _______,     _______,     _______,     _______,    _______,  _______,    _______,     KC_KP_4,   KC_KP_5,    KC_KP_6,  KC_KP_PLUS,    _______,          _______,
     _______,  _______,  _______,       _______,        _______,  _______,  _______,    _______,    KC_P1,      KC_P2,   KC_P3,  KC_KP_ENTER,       _______,    _______,
     _______,  _______,  _______,                                _______,                           KC_KP_0,        KC_KP_0,  KC_KP_DOT,  _______,  _______,  _______),

};

// // Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
// };

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


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case SEND_RAW:
            if (record->event.pressed) {

                dprintf("RGB Matrix mode: %d\n", rgb_matrix_get_mode());
                // rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
            }
            return false;

    }
    return true;
}
bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) == NUMPAD) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_WHITE);
                }
            }
        }
    }
    return false;
}
// bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
//     switch (get_highest_layer(layer_state)) {
//         case NUMPAD:

//             rgb_matrix_set_color(0, 0xFF, 0xFF, 0xFF);
//             break;
//     }
//     return true;
// }
// // void raw_hid_receive(uint8_t *data, uint8_t length) {
//     dprintf("Recieved RAWHID DATA\n");
//     for (int i = 0; i < length; i++) {
//         dprintf("%.2x", data[i]);
//     }
//     uprintf("\n");
//     raw_hid_send(data, length);
// }

#ifdef RAW_ENABLE
#define QMK_RC_BUFFER_MAX 64
uint8_t qmk_rc_buffer[QMK_RC_BUFFER_MAX] = {};

void raw_hid_receive(uint8_t *data, uint8_t length) {
  qmk_rc_receive(qmk_rc_buffer, QMK_RC_BUFFER_MAX, data, length);
}
#endif
bool dip_switch_update_keymap(uint8_t index, bool active) {

    printf("DIP switch %d: %s\n", index, active ? "ON" : "OFF");
    return true;
}
