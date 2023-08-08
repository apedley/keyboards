#include QMK_KEYBOARD_H

#include "rgb_matrix_user.h"
#include "apedley.h"
#include "print.h"

#define LEADER_ALERT_TIMER_MAX 500

extern leader_t leader;
extern dynamic_macro_t dynamic_macro;
extern my_rgb_range_t my_rgb_range;


__attribute__((weak)) bool
rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
  return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {


#ifdef RGB_MATRIX_LAYER_INDICATORS
  if (get_highest_layer(layer_state) > 0) {
    uint8_t layer = get_highest_layer(layer_state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
      for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        uint8_t index = g_led_config.matrix_co[row][col];

        if (index >= led_min && index < led_max && index != NO_LED &&
            keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
          rgb_matrix_set_color(index, 192, 0, 255);
        }
      }
    }
    return false;
  }
#endif

  // if (leader.isLeading) {
  //   rgb_matrix_underglow_indicator(led_min, led_max, 80, 255, 255);

  //   return false;
  // }




  if (my_rgb_range.is_set) {
    if (my_rgb_range.led_min > my_rgb_range.led_max) {
      rgb_matrix_set_color_all(my_rgb_range.red, my_rgb_range.green,
                               my_rgb_range.blue);
      return false;
    }
    for (int i = my_rgb_range.led_min; i <= my_rgb_range.led_max; i++) {
      rgb_matrix_set_color(i, my_rgb_range.red, my_rgb_range.green,
                           my_rgb_range.blue);
    }
    return false;
  }

  return rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}

__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) { return true; }

bool rgb_matrix_indicators_user(void) { return rgb_matrix_indicators_keymap(); }

// void rgb_matrix_underglow_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max) {
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


void rgb_matrix_underglow_indicator(uint8_t led_min, uint8_t led_max, uint8_t hue, uint8_t sat, uint8_t val) {
  HSV hsv = {hue, sat, val};
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }

  RGB rgb = hsv_to_rgb(hsv);

  for (uint8_t i = led_min; i <= led_max; i++) {
      if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
      }
  }
}
