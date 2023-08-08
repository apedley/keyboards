#define SELECT_WORD_TIMEOUT 2000

#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT
#define LEADER_TIMEOUT 325

#define DYNAMIC_MACRO_NO_NESTING

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define PERMISSIVE_HOLD


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


  #define WINXP_SOUND W__NOTE(_DS6), Q__NOTE(_DS5), H__NOTE(_AS5), H__NOTE(_GS5), H__NOTE(_DS5), H__NOTE(_DS6), H__NOTE(_AS5)

  #ifdef STARTUP_SONG
    #undef STARTUP_SONG
  #endif

  #define STARTUP_SONG SONG(MARIO_GAMEOVER)


#endif /// AUDIO_ENABLE
