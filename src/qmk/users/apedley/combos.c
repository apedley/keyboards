
#include "apedley.h"
#include "print.h"

#include QMK_KEYBOARD_H
enum combos {
    COMMA_DOT,
    TGB_BOOT,
    COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
                                   //
const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tgb_combo[] = {KC_T, KC_G, KC_B, COMBO_END};

combo_t key_combos[] = {
    [COMMA_DOT] = COMBO_ACTION(comma_dot_combo),
    [TGB_BOOT] = COMBO_ACTION(tgb_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
  case COMMA_DOT:
  // case XC_LDR:
    if (pressed) {
      leader_start();
    }
    break;
  case TGB_BOOT:
    if (pressed) {
      // tap_code16(LCTL(KC_B));
      reset_keyboard();
    }
    break;
  }
}
