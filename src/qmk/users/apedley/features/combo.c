
#include "combo.h"
#include "apedley.h"
#include "print.h"

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM pbsls_combo[] = {KC_P, KC_BSLS, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [QW_ESC] = COMBO(qw_combo, KC_ESC),
  [DF_TAB] = COMBO(df_combo, KC_TAB),
  [PBSLS_BSPC] = COMBO(pbsls_combo, KC_BSPC),
  [COMMA_DOT] = COMBO_ACTION(comma_dot_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMMA_DOT:
      if (pressed) {
        leader_start();
      }
      break;
    // case BSPC_LSFT_CLEAR:
    //   if (pressed) {
    //     tap_code16(KC_END);
    //     tap_code16(S(KC_HOME));
    //     tap_code16(KC_BSPC);
    //   }
    //   break;
  }
}
