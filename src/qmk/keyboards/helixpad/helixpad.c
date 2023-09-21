#include "helixpad.h"
#include "quantum.h"

#ifdef OLED_ENABLE

// oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
//     return OLED_ROTATION_90;
// }


void render_layer_kb(void) {

    char buf[10];

    oled_write_P(PSTR("Layer: "), false);
    snprintf(buf,sizeof(buf), "%u", layer_state);
    oled_write(buf, false);
    oled_advance_page(true);

}
void render_status_kb(void) {

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR(" SCR") : PSTR("    "), false);
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
    render_layer_kb();
    render_rgbmatrix_kb(false);
    render_status_kb();
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
  {31, 30, 29, 28, 27, 26, 25}
}, {


  //LED Index to Physical Positon
                  { 86,  0}, { 69,  0}, { 52,  0}, { 34, 0}, { 17,  0}, {  0, 0},
                  { 0,   16}, { 17,  16}, { 34,  16}, { 52, 16}, { 69,  16}, { 86, 16},
                  { 86,  32}, { 69,  32}, { 52,  32}, { 34, 32}, { 17,  32}, {  0, 32},
      {   0, 48}, { 17,  48}, { 34,  48}, { 52,  48}, { 69, 48}, { 86,  48}, { 103,48},
      { 103, 64}, { 86,  64}, { 69,  64}, { 52,  64}, { 34, 64}, { 17,  64}, {  0, 64},

}, {
  // LED Index to Flag
     1, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 4, 4,
     4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 1,
  1, 4, 4, 4, 4, 1, 1,


} };

// clang-format on

#endif //RGB_MATRIX_ENABLE
