
#pragma once

#ifdef RGB_MATRIX_ENABLE

  /*
   * RGB Matrix Modes
   */

  #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
  #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL

  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
  #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
  #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
  #define ENABLE_RGB_MATRIX_DUAL_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
  #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS

  #define ENABLE_RGB_MATRIX_RAINDROPS
  #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

  #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
  #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE

  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
  // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

  #define ENABLE_RGB_MATRIX_SPLASH
  // #define ENABLE_RGB_MATRIX_MULTISPLASH

  /*
   * RGB Matrix Settings
   */

  #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
  #undef RGB_MATRIX_DEFAULT_MODE

  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
  #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#endif // RGB_MATRIX_ENABLE


#ifdef MOUSEKEY_ENABLE
   #undef MOUSEKEY_INTERVAL
   #define MOUSEKEY_INTERVAL 20

   #undef MOUSEKEY_TIME_TO_MAX
   #define MOUSEKEY_TIME_TO_MAX 40

   #undef MOUSEKEY_MAX_SPEED
   #define MOUSEKEY_MAX_SPEED 6

   #undef MOUSEKEY_MOVE_DELTA
   #define MOUSEKEY_MOVE_DELTA 5

   #undef MOUSEKEY_DELAY
   #define MOUSEKEY_DELAY 0
#endif

#define MOUSE_EXTENDED_REPORT

#if defined(COMMAND_ENABLE)
    #define IS_COMMAND() ( \
    get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI)) \
    )
#endif


#undef QUICK_TAP_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 175

#define PERMISSIVE_HOLD

// #define TAPPING_TOGGLE 2

#if defined(COMBO_ENABLE)
    #define COMBO_ONLY_FROM_LAYER 0
    #define COMBO_STRICT_TIMER
    // #define COMBO_NO_TIMER
#endif


#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
