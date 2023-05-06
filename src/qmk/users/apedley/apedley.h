#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"
#include "features/leader.h"

enum user_custom_keycodes {
#ifdef NEW_SAFE_RANGE
  KC_MAKE = NEW_SAFE_RANGE,
#else
  KC_MAKE = SAFE_RANGE,
#endif
  SELWORD,
  SELLINE,
  UPDIR,
  BRACES,
  M_XXX1,
  M_XXX2,
  M_XXX3,
  NEWER_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

typedef struct {
    bool recording;
} dynamic_macro_t;

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
bool process_leader_dictionary_secret(void);
