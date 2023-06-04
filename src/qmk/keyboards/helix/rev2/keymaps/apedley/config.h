/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// place overrides here
// If you need more program area, try select and reduce rgblight modes to use.

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define SPLIT_WPM_ENABLE

// Selection of RGBLIGHT MODE to use.
#if defined(LED_ANIMATIONS)
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   #define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   #define RGBLIGHT_EFFECT_RGB_TEST
   #define RGBLIGHT_EFFECT_ALTERNATING
   #define RGBLIGHT_EFFECT_TWINKLE
#endif


#undef RGBLED_NUM

#define RGBLIGHT_SPLIT

// #ifdef RGBLED_BACK
  #define RGBLED_NUM 64
  #define RGBLED_SPLIT { 32, 32 }
// #else
  // #define RGBLED_NUM 6
  // #define RGBLED_SPLIT { 3, 3 }
// #endif

#undef RGBLIGHT_LIMIT_VAL

#if RGBLED_NUM <= 12
  #define RGBLIGHT_LIMIT_VAL 225
#else
  #define RGBLIGHT_LIMIT_VAL 204
#endif

#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 17


#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 4
#ifdef MOUSEKEY_ENABLE
   #undef MOUSEKEY_INTERVAL
   #define MOUSEKEY_INTERVAL 20

   #undef MOUSEKEY_TIME_TO_MAX
   #define MOUSEKEY_TIME_TO_MAX 40

   #undef MOUSEKEY_MAX_SPEED
   #define MOUSEKEY_MAX_SPEED 6

   #undef MOUSEKEY_MOVE_DELTA
   #define MOUSEKEY_MOVE_DELTA 5

   #undef MOUSEKEY_DELAY
   #define MOUSEKEY_DELAY 0
#endif

#define MOUSE_EXTENDED_REPORT

#if defined(COMMAND_ENABLE)
    #define IS_COMMAND() ( \
    get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI)) \
    )
#endif


#undef QUICK_TAP_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 175

#define PERMISSIVE_HOLD

// #define TAPPING_TOGGLE 2

#if defined(COMBO_ENABLE)
    #define COMBO_ONLY_FROM_LAYER 0
    #define COMBO_STRICT_TIMER
    // #define COMBO_NO_TIMER
#endif


#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
