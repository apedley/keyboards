#pragma once
#include QMK_KEYBOARD_H

bool process_leader_dictionary_secret(void);
bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
