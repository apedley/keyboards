#include "apedley.h"
#include "print.h"
#include "secrets.h"

static const char *const secret[] = {
    "sct1",
    "sct2",
    "sct3",
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case M_XXX1 ... M_XXX3:
    if (record->event.pressed) {
      send_string(secret[keycode - M_XXX1]);
    }
    return false;
    break;
  }
  return true;
}

bool process_leader_dictionary_secret(void) {
  if (leader_sequence_two_keys(KC_E, KC_M)) {
    // Leader, e, m => sends email
    SEND_STRING("sctem");
    return false;
  } else if (leader_sequence_two_keys(KC_O, KC_P)) {
    // Leader, o, p => sends opw
    SEND_STRING("sctio");
    return false;
  } else if (leader_sequence_two_keys(KC_P, KC_O)) {
    // Leader, p, o => sends pw1
    SEND_STRING("sctpo");
    return false;
  } else if (leader_sequence_two_keys(KC_P, KC_T)) {
    // Leader, p, t => sends pw2
    SEND_STRING("sctpt");
    return false;
  }
  return true; // Keep going
}
