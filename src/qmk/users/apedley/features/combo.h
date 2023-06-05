#pragma once

#include QMK_KEYBOARD_H
enum combos {
  QW_ESC,
  DF_TAB,
  PBSLS_BSPC,
  IO_MINUS,
  OP_EQUAL,
  COMMA_DOT,
  XC_LDR,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
