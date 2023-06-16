
#include "apedley.h"
#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base
    *
    * ,-----------------------------------------.           ,-----------------------------------------.
    * | `Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
    * |------+------+------+------+------+------|           |------+------+------+------+------+------|
    * |LwrTab|   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
    * |------+------+------+------+------+------|           |------+------+------+------+------+------|
    * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
    * `-----------------------------------------'           `-----------------------------------------'
    *        ,------.         ,--------------------.    ,--------------------.          ,------.
    *        | MUTE |         | Ctrl | Enter|  Del |    |BckSpc| Space| RAISE|          | MUTE |
    *        `------'         `--------------------'    `--------------------.          `------'
    *                         ,--------------------.    ,--------------------.
    *                         |Mouse3|Mouse1|Mouse2|    | Vol- | Mute | Vol+ |    // 3 way thumb switch
    *                         `--------------------'    `--------------------.
    */

    // Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
    // [_BASE] = LAYOUT_ximi(
    // KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
    // KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
    // KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
    //                 KC_MUTE,                  LOWER,        KC_ENT,       KC_DEL,       KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
    //                                           KC_PGDN,      KC_END,       KC_PGUP,      KC_VOLD, KC_MUTE,      KC_VOLU
    // ),
    [_BASE] = LAYOUT_ximi(
    QK_GESC,  KC_Q,   KC_W,   KC_E,     KC_R,   KC_T,         KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,   KC_BSPC,
    LOWER,    KC_A,   KC_S,   KC_D,     KC_F,   KC_G,         KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,   KC_C,     KC_V,   KC_B,         KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,KC_RGUI,
                KC_MUTE,      KC_LCTL,  KC_ENT, KC_SPC,       KC_RALT, KC_SPC,  RAISE,          KC_MUTE,
                              KC_WH_D,  KC_BTN3,KC_WH_U,      KC_WH_D,  KC_BTN3,KC_WH_U
    ),
    [_RAISE] = LAYOUT_ximi(
    KC_ESC,      KC_1,    KC_UP,   KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    QK_RBT,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    QK_BOOT,     KC_CAPS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,      _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                    QK_BOOT,       _______, _______, _______,      QK_BOOT, KC_MAKE, QK_RBT,          _______,
                                   _______, _______, _______,      KC_VOLD, KC_MUTE, KC_VOLU
    ),
    [_LOWER] = LAYOUT_ximi(
    _______,      KC_1,    KC_UP,   KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,      KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______,      _______, _______, _______, _______, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, _______,
                    _______,        QK_RBT,  QK_BOOT, KC_MAKE,      _______, _______, _______,        _______,
                                    KC_BTN1, KC_BTN3, KC_BTN2,      KC_VOLD, KC_MUTE, KC_VOLU
    ),

    [_ADJUST] =  LAYOUT_ximi(
    _______,      RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_BASE),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______,
    _______,      RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, _______,         KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
    _______,      RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,         KC_F11,  KC_F12,  _______, QK_RBT,   QK_BOOT, _______,
                    _______,         _______, _______, _______,         _______, _______, _______,          _______,
                                     _______, _______, _______,         _______, _______, _______
    ),

    [_NUMPAD] =  LAYOUT_ximi(
    _______,      _______, _______, _______, _______, _______,      KC_NUM,  KC_P7,   KC_P8,   KC_P9,  KC_PMNS,  KC_PSLS,
    _______,      _______, _______, _______, _______, _______,      _______, KC_P4,   KC_P5,   KC_P6,  KC_PPLS,  KC_PAST,
    _______,      _______, _______, _______, _______, _______,      _______, KC_P1,   KC_P2,   KC_P3,  KC_PENT,  _______,
                    _______,        _______, _______, _______,      _______, KC_P0,   KC_PDOT,       _______,
                                    _______, _______, _______,      _______, _______, _______
    )
};
