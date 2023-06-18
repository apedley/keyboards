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
    _ADJUST,
    _NUMPAD
};

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_NUMPAD (1<<_NUMPAD)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

//OLED update loop
#ifdef OLED_ENABLE
char wpm[42];


// oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
//     // if (!is_keyboard_master()) {
//     // return is_keyboard_left() ? rotation : OLED_ROTATION_90 ^ OLED_ROTATION_270;
//     return OLED_ROTATION_180;
// }

static void render_layer_status(bool full_display) {
    if (full_display) {
      oled_write_P(PSTR("Layer: "), false);
    }

    char buf[10];

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
    switch (layer_state) {
    case L_BASE:
        oled_write_P(PSTR("Base"), false);
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
    case L_NUMPAD:
        oled_write_P(PSTR("Numpad"), false);
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
    // if (is_keyboard_left()) {
    //     render_layer_status(true);
    //     render_rgbmatrix(false);
    //     render_leader();
    //     render_status();
    // } else {

      render_bongo(false);

      oled_set_cursor(0, 0);
      render_layer_status(false);

      oled_set_cursor(0, 1);
      sprintf(wpm, "WPM:%03d", get_current_wpm());
      oled_write(wpm, false);

      oled_set_cursor(0, 5);
      render_rgbmatrix(false);


      // render_leader();
      // bongo_render(0, 0);

    // }
    return false;
}

#endif // end of OLED_ENABLE

