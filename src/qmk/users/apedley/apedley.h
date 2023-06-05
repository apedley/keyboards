#pragma once

#include "features/leader.h"
#include "rgb_matrix_user.h"

#if defined(OLED_ENABLE)
  #include "oled.h"
#endif
#include "qmk_rc.h"
#include "secrets.h"
#include "action.h"
#include "version.h"
#include "quantum.h"

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
  NEWER_SAFE_RANGE // use "NEW_SAFE_RANGE" for keymap specific codes
};

typedef struct {
  bool recording;
} dynamic_macro_t;

