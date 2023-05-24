#include "oled.h"
#include "apedley.h"
#include "print.h"
__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
    return rotation;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return oled_init_keymap(rotation);
}

__attribute__((weak)) bool oled_task_keymap(void) {
    return true;
}

bool oled_task_user(void) {
  return oled_task_keymap();
}

// __attribute__((weak)) void housekeeping_task_oled(void) {
//     is_oled_enabled = is_oled_locked ? true : !(timer_elapsed32(oled_timer) > 60000);
// }


