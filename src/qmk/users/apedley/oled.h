#pragma once


#include QMK_KEYBOARD_H

oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
bool oled_task_keymap(void);
// void housekeeping_task_oled(void);

void render_leader(void);
void render_status(void);
void render_rgblight(bool simple);
void render_rgbmatrix(bool simple);
