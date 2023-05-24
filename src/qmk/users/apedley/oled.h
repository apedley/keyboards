#pragma once

#include QMK_KEYBOARD_H

oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
bool oled_task_keymap(void);
// void housekeeping_task_oled(void);
