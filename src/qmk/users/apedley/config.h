#define SELECT_WORD_TIMEOUT 2000

#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 325

#define DYNAMIC_MACRO_NO_NESTING

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define PERMISSIVE_HOLD

// Remove defaults
// #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
// #undef ENABLE_RGB_MATRIX_BREATHING
// #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
// #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
// #undef ENABLE_RGB_MATRIX_DUAL_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #undef ENABLE_RGB_MATRIX_RAINDROPS
// #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #undef ENABLE_RGB_MATRIX_PIXEL_RAIN

// #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #undef ENABLE_RGB_MATRIX_SPLASH
// #undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// Enable premade RGB effects

// #define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// #define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE

// #define ENABLE_RGB_MATRIX_ALPHAS_MODS

// #define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define ENABLE_RGB_MATRIX_CYCLE_ALL
// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS

// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255 /* The maximum brightness level */


#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_DELAY        0 // Delay between pressing a key and cursor movement
#   define MOUSEKEY_INTERVAL    15 // Time between cursor movements in milliseconds
#   define MOUSEKEY_MOVE_DELTA  10 // Step size for acceleration
#   define MOUSEKEY_MAX_SPEED    9
#   define MOUSEKEY_TIME_TO_MAX 80
#   define MOUSEKEY_WHEEL_DELAY       16
#   define MOUSEKEY_WHEEL_INTERVAL    30
#   define MOUSEKEY_WHEEL_MAX_SPEED   10
#   define MOUSEKEY_WHEEL_TIME_TO_MAX 95
#endif



#ifdef AUDIO_ENABLE

  // #define AP_STARTUP_FLOW_DOWN H__NOTE(_E6), Q__NOTE(_REST), Q__NOTE(_C6), H__NOTE(_G5), Q__NOTE(_A5), H__NOTE(_D5), H__NOTE(_E5), H__NOTE(_C5),

  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)

  #ifdef STARTUP_SONG
    #undef STARTUP_SONG
  #endif

  // #define STARTUP_SONG SONG(MARIO_MUSHROOM)

  // #define STARTUP_SONG SONG(WINXP_SOUND)
  // #define STARTUP_SONG SONG(COIN_SOUND)
  #define STARTUP_SONG SONG(SONIC_RING)
  // #define STARTUP_SONG SONG(ZELDA_TREASURE)
  // #define STARTUP_SONG SONG(MARIO_GAMEOVER)
  // #define STARTUP_SONG SONG(AP_STARTUP_FLOW_DOWN)
  // #define STARTUP_SONG SONG(MARIO_THEME)
  // #define STARTUP_SONG SONG(FF_PRELUDE)
  // #define STARTUP_SONG SONG(E1M1_DOOM)
  // #define STARTUP_SONG SONG(DISNEY_SONG)
  // #define STARTUP_SONG SONG(KATAWARE_DOKI)
  // #define STARTUP_SONG SONG(NUMBER_ONE)
  // #define STARTUP_SONG SONG(ALL_STAR)
  // #define STARTUP_SONG SONG(CAMPANELLA)
  // #define STARTUP_SONG SONG(SONG_OF_THE_ANCIENTS)
  // #define STARTUP_SONG SONG(LP_NUMB)



  // #define STARTUP_SONG SONG(VICTORY_FANFARE_SHORT)
  // #define GOODBYE_SONG SONG(VICTORY_FANFARE_SHORT)
#endif /// AUDIO_ENABLE
