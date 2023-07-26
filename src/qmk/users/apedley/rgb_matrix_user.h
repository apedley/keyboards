#pragma once

#include QMK_KEYBOARD_H

bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
bool rgb_matrix_indicators_keymap(void);

void rgb_matrix_underglow_helper(uint8_t hue, uint8_t sat, uint8_t val, uint8_t led_min, uint8_t led_max);
void rgb_matrix_underglow_all(uint8_t hue, uint8_t sat, uint8_t val);
