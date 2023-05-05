#pragma once

#include QMK_KEYBOARD_H

typedef struct {
    bool isLeading;
    bool timedOut;
    int timedOutTimer;
    int successTimer;
    bool success;
} leader_t;

void process_leader_dictionary(void);
