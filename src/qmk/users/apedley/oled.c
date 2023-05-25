#include "apedley.h"

extern leader_t leader;
extern dynamic_macro_t dynamic_macro;


#define LEADER_ALERT_TIMER_MAX 500

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


void render_leader(void) {
  // oled_write_P(leader.isLeading ? PSTR("LDR ") : PSTR("    "), false);

  if (leader.isLeading) {
    oled_write_P(PSTR("LDR"), false);
  } else if (leader.timedOut) {
    if (timer_elapsed(leader.timedOutTimer) < LEADER_ALERT_TIMER_MAX) {
      oled_write_P(PSTR("BAD!"), false);
    } else {
      leader.timedOut = false;
    }
  } else if (leader.success) {
    if (timer_elapsed(leader.successTimer) < LEADER_ALERT_TIMER_MAX) {
      oled_write_P(PSTR("GOOD"), false);
    } else {
      leader.success = false;
    }
  } else {
    return;
  }
  oled_advance_page(true);
}

void render_status(void) {
  // Host Keyboard LED Status
  led_t led_state = host_keyboard_led_state();
  oled_write_P(led_state.num_lock ? PSTR("NUM") : PSTR("   "), false);
  oled_write_P(led_state.caps_lock ? PSTR("CAP") : PSTR("   "), false);
  oled_write_P(led_state.scroll_lock ? PSTR("SCR") : PSTR("  "), false);
  // oled_write_P(leader.isLeading ? PSTR("LDR") : PSTR("  "), false);
  oled_advance_page(true);
}
