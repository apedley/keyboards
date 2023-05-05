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

#include QMK_KEYBOARD_H
#include "apedley.h"
#include "print.h"

// clang-format off
enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN1,
  WIN_FN1,
  FN2
};

enum customs {
    BRACES_TWO = NEWER_SAFE_RANGE
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
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,  KC_TRNS,
     KC_TRNS,  UPDIR, KC_UP,   SELWORD,   SELLINE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  M_XXX2,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,            KC_TRNS,  KC_PGDN,
     KC_TRNS,  KC_VOLD, KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_FN1] = LAYOUT_ansi_68(
     KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_DEL,  KC_TRNS,
     KC_MAKE,  UPDIR, KC_UP,   SELWORD,   SELLINE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  DM_RSTP,  DM_REC1,  DM_PLY1,  DM_REC2,  DM_PLY2,  M_XXX2,  KC_END,
     RGB_TOG,  KC_LEFT, KC_DOWN, KC_RGHT, BRACES,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_BTN1,  KC_BTN2,  KC_TRNS,            KC_PGDN,
     KC_TRNS,  KC_VOLD, KC_VOLU,  KC_MUTE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_WH_D,  KC_WH_U,  KC_INSERT,  KC_DELETE,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

#ifdef MIDI_ADVANCED

[FN2] = LAYOUT_ansi_68(
     QK_BOOT,  BT_HST1,    BT_HST2,    BT_HST3,    BAT_LVL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_HUD,    RGB_HUI ,   RGB_VAD,   RGB_VAI,  RGB_TOG,  RGB_MOD,
     KC_TRNS,  KC_TRNS,  MI_Cs1,  MI_Ds1,  KC_TRNS,      MI_Fs1,     MI_Gs1,     MI_As1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_RMOD,
     KC_TRNS,  MI_C1,     MI_D1,     MI_E1,     MI_F1,    MI_G1,     MI_A1,  MI_B1,  MI_C2,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  RGB_SPI,
     KC_TRNS,  MI_OCTD,  MI_OCTU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_VOLU,  RGB_SPD,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,  KC_MNXT),


#else


[FN2] = LAYOUT_ansi_68(
     QK_BOOT,  BT_HST1,    BT_HST2,    BT_HST3,    BAT_LVL,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    RGB_SAI,    RGB_HUI ,   RGB_VAI, RGB_SPI,  RGB_TOG,  RGB_MOD,
     KC_MAKE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
     QK_RBT,  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
     KC_CAPS,  M_XXX1,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_VOLU,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,  KC_MNXT),

#endif

};
