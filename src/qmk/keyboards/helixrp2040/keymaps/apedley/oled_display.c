/* Copyright 2020 yushakobo
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


#include "apedley.h"
#include "bongo.h"
#include <stdio.h>
#include <string.h>
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

//OLED update loop
#ifdef OLED_ENABLE
char wpm[42];


oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
    // if (!is_keyboard_master()) {
    return is_keyboard_left() ? rotation : OLED_ROTATION_90 ^ OLED_ROTATION_270;

}
// static void render_rgbled_status(bool full) {
// #    ifdef RGBLIGHT_ENABLE
//     char buf[30];
//     if (RGBLIGHT_MODES > 1 && rgblight_is_enabled()) {
//         if (full) {
//             snprintf(buf, sizeof(buf), "LED %2d: %d,%d,%d ",
//                      rgblight_get_mode(),
//                      rgblight_get_hue()/RGBLIGHT_HUE_STEP,
//                      rgblight_get_sat()/RGBLIGHT_SAT_STEP,
//                      rgblight_get_val()/RGBLIGHT_VAL_STEP);
//         } else {
//             snprintf(buf, sizeof(buf), "[%2d] ", rgblight_get_mode());
//         }
//         oled_write(buf, false);
//     }
//     oled_advance_page(true);
// #    endif
// }
// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };

//     oled_write_P(qmk_logo, false);
// }
static void render_layer_status(bool full_display) {
    if (full_display) {
      oled_write_P(PSTR("Layer: "), false);
    }

    char buf[10];

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    switch (layer_state) {
    case L_BASE:
        oled_write_P(PSTR("Default"), false);
        break;
    case L_RAISE:
        oled_write_P(PSTR("Raise"), false);
        break;
    case L_LOWER:
        oled_write_P(PSTR("Lower"), false);
        break;
    case L_ADJUST:
    case L_ADJUST_TRI:
        oled_write_P(PSTR("Adjust"), false);
        break;
    default:
        oled_write_P(PSTR("Undef-"), false);
        snprintf(buf,sizeof(buf), "%u", layer_state);
        oled_write(buf, false);
    }
    if (full_display) {
      oled_advance_page(true);
    }
}

bool oled_task_keymap(void) {
    if (is_keyboard_left()) {
        render_layer_status(true);
        render_rgbmatrix(false);
        render_leader();
        render_status();
    } else {

      render_bongo(false);

      oled_set_cursor(0, 1);
      sprintf(wpm, "WPM:%03d", get_current_wpm());
      oled_write(wpm, false);

      oled_set_cursor(0, 0);
      render_layer_status(false);
      oled_set_cursor(0, 2);
      render_leader();
      // bongo_render(0, 0);

    }
    return false;
}

#endif // end of OLED_ENABLE

