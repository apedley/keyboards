#include QMK_KEYBOARD_H

#include "rgb.h"
#include "apedley.h"
#include "print.h"

#define LEADER_ALERT_TIMER_MAX 500

extern leader_t leader;


extern dynamic_macro_t dynamic_macro;

__attribute__((weak)) bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max) {
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (leader.isLeading) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_BLUE);
        }
        return false;
    } else if (leader.timedOut) {
        if (timer_elapsed(leader.timedOutTimer) < LEADER_ALERT_TIMER_MAX) {
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_RED);
            }
            return false;
        } else {
            leader.timedOut = false;
        }
        return false;
    } else if (leader.success) {
        if (timer_elapsed(leader.successTimer) < LEADER_ALERT_TIMER_MAX) {
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_GREEN);
            }
            return false;
        } else {
            leader.success = false;
        }
    }

    if (dynamic_macro.recording) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
        return false;
    }

    if (is_caps_word_on()) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_YELLOW);
        }
        return false;
    }
    return rgb_matrix_indicators_advanced_keymap(led_min, led_max);
}


__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
    return true;
}

bool rgb_matrix_indicators_user(void) {
    return rgb_matrix_indicators_keymap();
}
