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


void render_layer(void) {

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
void render_status(void) {

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUML") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL") : PSTR("    "), false);
    oled_advance_page(true);
}

bool oled_task_kb(void) {
    if (oled_task_user()) {
      /* keymap/user level oled_task_user() dose not exist */
      if (is_keyboard_left()) {
        render_layer();
      } else {
        render_layer();
        render_status();
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

// led_config_t g_led_config = { {
//   //Key Matrix to LED Index
//   { 5,  4,  3,  2,  1,  0, NO_LED },
//   { 6,  7,  8,  9, 10, 11, NO_LED },
//   {17, 16, 15, 14, 13, 12, NO_LED },
//   {18, 19, 20, 21, 22, 23, 24},
//   {31, 30, 29, 28, 27, 26, 25}
// }, {
//   //LED Index to Physical Positon
//                   { 37,   0}, {  75,   0}, { 111,   0}, { 148,   0}, {185,  0}, { 222,   0},
//                   { 222, 16}, { 185,  16}, { 148,  16}, { 111,  16}, { 75, 16}, {  37,  16},
//                   { 37,  32}, {  75,  32}, { 111,  32}, { 148,  32}, {185, 32}, { 222,  32},
//       { 222, 48}, { 185, 48}, { 148,  48}, { 111,  48}, {  75,  48}, { 37, 48}, {   0,  48},
//       {   0, 64}, { 37,  64}, {  75,  64}, { 111,  64}, { 148,  64}, {185, 64}, { 222,  64}

// }, {
//   // LED Index to Flag
//      4, 4, 4, 4, 4, 4,
//      4, 4, 4, 4, 4, 4,
//      4, 4, 4, 4, 4, 4,
//   4, 4, 4, 4, 4, 4, 1,
//   1, 4, 4, 4, 4, 4, 1

// } };

// clang-format on

#endif //RGB_MATRIX_ENABLE
