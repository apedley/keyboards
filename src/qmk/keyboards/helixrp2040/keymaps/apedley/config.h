
#pragma once

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
