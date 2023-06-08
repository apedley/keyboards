
#pragma once


#define EE_HANDS

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#define SPLIT_ACTIVITY_ENABLE

#ifdef OLED_ENABLE
  #define SPLIT_WPM_ENABLE
  #define SPLIT_OLED_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE

  #define WS2812_PIO_USE_PIO1
  #define WS2812_DI_PIN GP0

  #define LED_ANIMATIONS

  // Selection of RGBLIGHT MODE to use.
  #if defined(LED_ANIMATIONS)
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    // #define RGBLIGHT_EFFECT_CHRISTMAS
    //  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    //  #define RGBLIGHT_EFFECT_RGB_TEST
    // #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_RAINBOW_SWIRL_RANGE 128
  #endif


  #define RGBLED_NUM 64

  #define RGBLIGHT_SPLIT
  #define RGBLED_SPLIT { 32, 32 }
  #define RGBLIGHT_LIMIT_VAL 204

  #undef RGBLIGHT_VAL_STEP
  #define RGBLIGHT_VAL_STEP 17


  #undef RGBLIGHT_HUE_STEP
  #define RGBLIGHT_HUE_STEP 4

#endif // RGBLIGHT_ENABLE

#ifdef RGB_MATRIX_ENABLE

  #define WS2812_PIO_USE_PIO1
  #define WS2812_DI_PIN GP0
  #define RGBLED_NUM 64
  #define RGB_MATRIX_LED_COUNT RGBLED_NUM

  #define RGB_MATRIX_SPLIT { 32, 32 }
  #define RGB_MATRIX_KEYPRESSES
  #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
  #define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE

  #define ENABLE_RGB_MATRIX_ALPHAS_MODS

  #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN

  #define ENABLE_RGB_MATRIX_BREATHING

  #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON

  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
  #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
  // #define RGB_MATRIX_HUE_STEP 8
  // #define RGB_MATRIX_SAT_STEP 8
  // #define RGB_MATRIX_VAL_STEP 8
  // #define RGB_MATRIX_SPD_STEP 10

  #define RGB_DISABLE_WHEN_USB_SUSPENDED

  #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 /* The maximum brightness level */
  #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_ALPHAS_MODS
#endif // RGB_MATRIX_ENABLE


#ifdef OLED_ENABLE
  #define I2C_DRIVER I2CD1
  #define I2C1_SDA_PIN GP2
  #define I2C1_SCL_PIN GP3
  #define OLED_DISPLAY_128X32
#endif

#undef QUICK_TAP_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 175

#define PERMISSIVE_HOLD
#define TAPPING_TOGGLE 2
