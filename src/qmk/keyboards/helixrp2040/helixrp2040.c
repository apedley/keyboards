#include "helixrp2040.h"
#include "quantum.h"


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



void keyboard_post_init_kb() {

#ifdef CONSOLE_ENABLE
  debug_config.enable = true;
  // debug_config.keyboard = true;
  // debug_config.matrix = true;
#endif

  keyboard_post_init_user();
}
