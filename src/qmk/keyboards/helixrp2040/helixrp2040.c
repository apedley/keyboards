#include "helixrp2040.h"
#include "quantum.h"



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// // entirely and just use numbers.
// enum layer_number {
//     _QWERTY = 0,
//     _LOWER,
//     _RAISE,
//     _ADJUST
// };

// //assign the right code to your layers for OLED display
// #define L_BASE 0
// #define L_LOWER (1<<_LOWER)
// #define L_RAISE (1<<_RAISE)
// #define L_ADJUST (1<<_ADJUST)
// #define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return is_keyboard_left() ? rotation : OLED_ROTATION_90 ^ OLED_ROTATION_270;
}


void render_layer_kb(void) {

    char buf[10];

  // // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  //   switch (get_highest_layer(layer_state)) {
  //   case L_BASE:
  //       oled_write_P(PSTR("Base"), false);
  //       break;
  //   case L_LOWER:
  //       oled_write_P(PSTR("Lower"), false);
  //       break;
  //   case L_RAISE:
  //       oled_write_P(PSTR("Raise"), false);
  //       break;
  //   case L_ADJUST:
  //       oled_write_P(PSTR("Adjust"), false);
  //       break;
  //   default:
  //       oled_write_P(PSTR("Undef-"), false);
  //       snprintf(buf,sizeof(buf), "%u", layer_state);
  //       oled_write(buf, false);
  //   }
  //   oled_advance_page(true);

    oled_write_P(PSTR("Layer: "), false);
    snprintf(buf,sizeof(buf), "%u", layer_state);
    oled_write(buf, false);
    oled_advance_page(true);

}
void render_status_kb(void) {

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUML") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("    "), false);
    oled_advance_page(true);
}


void render_rgbmatrix_kb(bool simple) {
#ifdef RGB_MATRIX_ENABLE
  char buf[30];
  if (rgb_matrix_is_enabled()) {

    if (simple) {
      snprintf(buf, sizeof(buf), "[%2d] ", rgb_matrix_get_mode());
    } else {
      snprintf(buf, sizeof(buf), "LED %2d: %d,%d,%d %d",
                      rgb_matrix_get_mode(),
                      rgb_matrix_get_hue()/8,
                      rgb_matrix_get_sat()/16,
                      rgb_matrix_get_val()/16,
                      rgb_matrix_get_speed()/26);
      oled_write(buf, false);
    }
  }

  oled_advance_page(true);
#endif
}

bool oled_task_kb(void) {
    if (oled_task_user()) {
      /* keymap/user level oled_task_user() dose not exist */
      if (is_keyboard_left()) {
        render_layer_kb();
        render_rgbmatrix_kb(false);
      } else {
        render_layer_kb();
        render_status_kb();
      }
      return false;
    }
    return false;
}
#endif // OLED_ENABLE

void keyboard_post_init_kb() {

#ifdef CONSOLE_ENABLE
  debug_config.enable = true;
  // debug_config.keyboard = true;
  // debug_config.matrix = true;
#endif // CONSOLE_ENABLE

  keyboard_post_init_user();
}

#ifdef RGB_MATRIX_ENABLE

// clang-format off

led_config_t g_led_config = { {
  //Key Matrix to LED Index
  { 5,  4,  3,  2,  1,  0, NO_LED },
  { 6,  7,  8,  9, 10, 11, NO_LED },
  {17, 16, 15, 14, 13, 12, NO_LED },
  {18, 19, 20, 21, 22, 23, 24},
  {31, 30, 29, 28, 27, 26, 25},
  {37, 36, 35, 34, 33, 32, NO_LED },
  {38, 39, 40, 41, 42, 43, NO_LED },
  {49, 48, 47, 46, 45, 44, NO_LED },
  {50, 51, 52, 53, 54, 55, 56},
  {63, 62, 61, 60, 59, 58, 57}
}, {
  //LED Index to Physical Positon
                  { 86,  0}, { 69,  0}, { 52,  0}, { 34, 0}, { 17,  0}, {  0, 0},
                  { 0,   16}, { 17,  16}, { 34,  16}, { 52, 16}, { 69,  16}, { 86, 16},
                  { 86,  32}, { 69,  32}, { 52,  32}, { 34, 32}, { 17,  32}, {  0, 32},
      {   0, 48}, { 17,  48}, { 34,  48}, { 52,  48}, { 69, 48}, { 86,  48}, { 103,48},
      { 103, 64}, { 86,  64}, { 69,  64}, { 52,  64}, { 34, 64}, { 17,  64}, {  0, 64},

                  { 138,  0}, { 155,  0}, { 172,  0}, { 190, 0}, { 207, 0 }, { 224, 0},
                  { 224, 16}, { 207, 16}, { 190, 16}, { 172,16}, { 155, 16}, { 138,16},
                  { 138, 32}, { 155, 32}, { 172, 32}, { 190,32}, { 207, 32}, { 224,32},
      { 224, 48}, { 207, 48}, { 190, 48}, { 172, 48}, { 155,48}, { 138, 48}, { 121,48},
      { 121, 64}, { 138, 64}, { 155, 64}, { 172, 64}, { 190,64}, { 207, 64}, { 224,64}

}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 1, 4, 1, 1, 1, 1,


     4, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4,
  4, 1, 4, 4, 4, 4, 4
} };

// clang-format on

#endif //RGB_MATRIX_ENABLE
