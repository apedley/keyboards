#pragma once

#include "features/leader.h"
#include "rgb_matrix_user.h"

#if defined(OLED_ENABLE)
  #include "oled.h"
#endif
#include "qmk_rc.h"
#include "secrets.h"
// #include "action.h"
#include "version.h"
#include "quantum.h"


// Check to see which keyboard you're using, and define the PLACEHOLDER_SAFE_RANGE based on that.
#if defined(KEYBOARD_fingerpunch_arachnophobe) \
    || defined(KEYBOARD_fingerpunch_barobord) \
    || defined(KEYBOARD_fingerpunch_barobord_byomcu) \
    || defined(KEYBOARD_fingerpunch_bgkeeb) \
    || defined(KEYBOARD_fingerpunch_bigbarobord) \
    || defined(KEYBOARD_fingerpunch_euclid36) \
    || defined(KEYBOARD_fingerpunch_euclid36_proto) \
    || defined(KEYBOARD_fingerpunch_ffkb_atmega_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v2) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v3) \
    || defined(KEYBOARD_fingerpunch_ffkb_rp_v3) \
    || defined(KEYBOARD_fingerpunch_fflx) \
    || defined(KEYBOARD_fingerpunch_fpm101) \
    || defined(KEYBOARD_fingerpunch_luakeeb) \
    || defined(KEYBOARD_fingerpunch_pinkiesout_v1) \
    || defined(KEYBOARD_fingerpunch_pinkiesout_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_v1) \
    || defined(KEYBOARD_fingerpunch_rockon_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_v3) \
    || defined(KEYBOARD_fingerpunch_rockon_bp) \
    || defined(KEYBOARD_fingerpunch_sweeeeep) \
    || defined(KEYBOARD_fingerpunch_ximi)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif


enum user_custom_keycodes {
  KC_MAKE = PLACEHOLDER_SAFE_RANGE,
  SELWORD,
  SELLINE,
  UPDIR,
  BRACES,
  M_XXX1,
  M_XXX2,
  M_XXX3,
  SEND_RAW_TEST,
  AP_TNXT,
  AP_TPRV,
  AP_TCLS,
  NEW_SAFE_RANGE,
};

typedef struct {
  bool recording;
} dynamic_macro_t;

