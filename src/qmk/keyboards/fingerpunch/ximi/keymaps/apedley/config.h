

#pragma once

#ifdef AUDIO_ENABLE
#endif /// AUDIO_ENABLE

#ifdef HAPTIC_ENABLE
#endif /// HAPTIC_ENABLE


#ifdef RGB_MATRIX_ENABLE
  // #define FP_LAYER_LIGHTING_DYNAMIC_BASE_LAYER_DISABLE
  // #define FP_STARTUP_ANIMATION_DISABLE
  // #define FP_LAYER_LIGHTING_MODE RGB_MATRIX_BAND_VAL
  // #define FP_LAYER_LIGHTING_MODE RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#endif /// RGB_MATRIX_ENABLE


#undef ENCODERS_PAD_A
#undef ENCODERS_PAD_B

#define ENCODERS_PAD_A { GP8 }
#define ENCODERS_PAD_B { GP7 }


#undef FP_ENC_1_LAYER_SUPER_TAB
#undef FP_ENC_1_LAYER_SCROLL_WHEEL

#define FP_ENC_1_LAYER_SUPER_TAB 5
#define FP_ENC_1_LAYER_SCROLL_WHEEL 0

// #define FP_ENC_1_LAYER_SCROLL_WHEEL 0
// #define FP_ENC_1_LAYER_SUPER_TAB 4
#ifdef OLED_ENABLE
  #define I2C_DRIVER I2CD1
  // #define I2C1_SDA_PIN GP2
  // #define I2C1_SCL_PIN GP3
  #define OLED_DISPLAY_128X64
  #define OLED_DISPLAY_ADDRESS 0x3C
#endif

// #define MOUSE_EXTENDED_REPORT



// #ifdef POINTING_DEVICE_ENABLE
  // #ifdef SPLIT_POINTING_ENABLE
  //   #undef SPLIT_POINTING_ENABLE
  // #endif

  // #define POINTING_DEVICE_RIGHT

  // #define POINTING_DEVICE_LEFT
  // #define POINTING_DEVICE_DEBUG

  // #define PIMORONI_TRACKBALL_ADDRESS 0x0A
  // #define CIRQUE_PINNACLE_DIAMETER_MM 35

  // #define CIRQUE_PINNACLE_ADDR 0x2A
  // #define CIRQUE_PINNACLE_TAP_ENABLE


  // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
  // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
  // #define POINTING_DEVICE_TASK_THROTTLE_MS 5

  // #define MOUSE_EXTENDED_REPORT

  // #define PIMORONI_TRACKBALL_SCALE 25

  // #define POINTING_DEVICE_TASK_THROTTLE_MS 8
// #endif // POINTING_DEVICE_ENABLE
