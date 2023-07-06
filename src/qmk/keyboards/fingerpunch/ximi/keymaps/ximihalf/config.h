

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
  #define FP_STARTUP_ANIMATION_DISABLE
  // #define FP_LAYER_LIGHTING_HUE_0 155, 255, 155
  #define FP_LAYER_LIGHTING_HUE_1 FP_HSV_LAVENDER
  #define FP_LAYER_LIGHTING_HUE_2 FP_HSV_LIME
  #define FP_LAYER_LIGHTING_HUE_3 HSV_CYAN
#endif /// RGB_MATRIX_ENABLE

#ifdef ENCODER_ENABLE
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
#endif

#ifdef OLED_ENABLE
  #define I2C_DRIVER I2CD1
  #define SPLIT_OLED_ENABLE
// #define SPLIT_WPM_ENABLE
// #define SPLIT_LED_STATE_ENABLE
// #define SPLIT_ACTIVITY_ENABLE

  // #define I2C1_SDA_PIN GP2
  // #define I2C1_SCL_PIN GP3
  #define OLED_DISPLAY_128X64
  #define OLED_DISPLAY_ADDRESS 0x3C
#endif


#ifdef POINTING_DEVICE_ENABLE

  #define FP_POINTING_COMBINED_SCROLLING_RIGHT false
  #define FP_POINTING_COMBINED_SCROLLING_LEFT false

  #define FP_POINTING_SNIPING_LAYER 2
  #define FP_POINTING_SNIPING_LAYER_ENABLE



  #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
  // #define FP_POINTING_ZOOMING_LAYER 1
  // #define FP_POINTING_ZOOMING_LAYER_ENABLE

  #define POINTING_DEVICE_DEBUG

//   // #ifdef SPLIT_POINTING_ENABLE
//   //   #undef SPLIT_POINTING_ENABLE
//   // #endif

//   // #define POINTING_DEVICE_RIGHT

//   // #define POINTING_DEVICE_LEFT
//   #ifndef POINTING_DEVICE_INVERT_X
//     #define POINTING_DEVICE_INVERT_X
//     #define POINTING_DEVICE_INVERT_Y
//   #endif // POINTING_DEVICE_INVERT_X

//   // #define PIMORONI_TRACKBALL_ADDRESS 0x0A
//   // #define CIRQUE_PINNACLE_DIAMETER_MM 35

//   // #define CIRQUE_PINNACLE_ADDR 0x2A
//   // #define CIRQUE_PINNACLE_TAP_ENABLE


//   // #define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_RELATIVE_MODE
//   // #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE
//   // #define POINTING_DEVICE_TASK_THROTTLE_MS 5

//   // #define MOUSE_EXTENDED_REPORT

//   // #define PIMORONI_TRACKBALL_SCALE 25

//   // #define POINTING_DEVICE_TASK_THROTTLE_MS 8
#endif // POINTING_DEVICE_ENABLE

#ifdef QUANTUM_PAINTER_ENABLE


  /* SPI pins */
  #define SPI_DRIVER SPID0

  /* LCD Configuration */
  #define LCD_DC_PIN GP5
  #define LCD_RST_PIN GP4
  #define LCD_CS_PIN GP6


  #ifndef LCD_ACTIVITY_TIMEOUT
  #    define LCD_ACTIVITY_TIMEOUT 30000
  #endif // LCD_ACTIVITY_TIMEOUT


  // #define QUANTUM_PAINTER_SUPPORTS_256_PALETTE TRUE
  // #define QUANTUM_PAINTER_LOAD_FONTS_TO_RAM TRUE
  // #define QUANTUM_PAINTER_PIXDATA_BUFFER_SIZE 128
  // #define QUANTUM_PAINTER_DEBUG

#endif // QUANTUM_PAINTER_ENABLE


#undef SPLIT_MODS_ENABLE
#undef SPLIT_LAYER_STATE_ENABLE
#undef SPLIT_TRANSPORT_MIRROR
