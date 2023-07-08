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
uint32_t reset_leader_color_deferred(uint32_t trigger_time, void *cb_arg);
