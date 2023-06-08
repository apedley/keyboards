#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

// BLANK FULL LINE
#define ___________________BLANK___________________			_______, _______, _______, _______, _______

// NAVIGATION

#define __NAV_1_K1__ KC_ESC
#define __NAV_1_K2__ KC_PGUP
#define __NAV_1_K3__ KC_UP
#define __NAV_1_K4__ KC_PGDN
#define __NAV_1_K5__ _______

#define __NAV_2_K1__ KC_HOME
#define __NAV_2_K2__ KC_LEFT
#define __NAV_2_K3__ KC_DOWN
#define __NAV_2_K4__ KC_RGHT
#define __NAV_2_K5__ KC_END

#define __NAV_3_K1__ KC_ESC
#define __NAV_3_K2__ KC_PGUP
#define __NAV_3_K3__ KC_PGDN
#define __NAV_3_K4__ LCTL(LGUI(KC_LEFT))
#define __NAV_3_K5__ LCTL(LGUI(KC_RIGHT))

#define ________________NAVIGATION_1_______________			__NAV_1_K1__, __NAV_1_K2__, __NAV_1_K3__, __NAV_1_K4__, __NAV_1_K5__
#define ________________NAVIGATION_2_______________			__NAV_2_K1__, __NAV_2_K2__, __NAV_2_K3__, __NAV_2_K4__, __NAV_2_K5__
#define ________________NAVIGATION_3_______________			__NAV_3_K1__, __NAV_3_K2__, __NAV_3_K3__, __NAV_3_K4__, __NAV_3_K5__

// // ALPHA
// #define __________________ALPHA_L1____________________			KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
// #define __________________ALPHA_L2____________________			KC_A,    KC_R,    KC_S,    KC_T,    KC_G
// #define __________________ALPHA_L3____________________			KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

// #define __________________ALPHA_R1____________________			KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
// #define __________________ALPHA_R2____________________			KC_M,    KC_N,    KC_E,    KC_I,    KC_O
// #define __________________ALPHA_R3____________________			KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define __NUMPAD_0_K1__ KC_NUM
#define __NUMPAD_0_K2__ KC_PSLS
#define __NUMPAD_0_K3__ KC_PAST
#define __NUMPAD_0_K4__ KC_PMNS

#define __NUMPAD_1_K1__ KC_P7
#define __NUMPAD_1_K2__ KC_P8
#define __NUMPAD_1_K3__ KC_P9
#define __NUMPAD_1_K4__ KC_PPLS

#define __NUMPAD_2_K1__ KC_P4
#define __NUMPAD_2_K2__ KC_P5
#define __NUMPAD_2_K3__ KC_P6
#define __NUMPAD_2_K4__ KC_PPLS

#define __NUMPAD_3_K1__ KC_P1
#define __NUMPAD_3_K2__ KC_P2
#define __NUMPAD_3_K3__ KC_P3
#define __NUMPAD_3_K4__ KC_PENT

#define __NUMPAD_4_K1__ KC_P0
#define __NUMPAD_4_K2__ KC_P0
#define __NUMPAD_4_K3__ KC_PDOT
#define __NUMPAD_4_K4__ KC_PENT

#define _________________NUMPAD_0__________________			__NUMPAD_0_K1__, __NUMPAD_0_K2__, __NUMPAD_0_K3__, __NUMPAD_0_K4__
#define _________________NUMPAD_1__________________			__NUMPAD_1_K1__, __NUMPAD_1_K2__, __NUMPAD_1_K3__, __NUMPAD_1_K4__
#define _________________NUMPAD_2__________________			__NUMPAD_2_K1__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__
#define _________________NUMPAD_3__________________			__NUMPAD_3_K1__, __NUMPAD_3_K2__, __NUMPAD_3_K3__, __NUMPAD_3_K4__
#define _________________NUMPAD_4__________________			__NUMPAD_4_K1__, __NUMPAD_4_K2__, __NUMPAD_4_K3__, __NUMPAD_4_K4__

// #define __NUMPAD_1_K1__ KC_ASTR
// #define __NUMPAD_1_K2__ KC_7
// #define __NUMPAD_1_K3__ KC_8
// #define __NUMPAD_1_K4__ KC_9
// #define __NUMPAD_1_K5__ KC_MINS

// #define __NUMPAD_2_K1__ KC_SLSH
// #define __NUMPAD_2_K2__ KC_4
// #define __NUMPAD_2_K3__ KC_5
// #define __NUMPAD_2_K4__ KC_6
// #define __NUMPAD_2_K5__ KC_PLUS

// #define __NUMPAD_3_K1__ KC_EQL
// #define __NUMPAD_3_K2__ KC_1
// #define __NUMPAD_3_K3__ KC_2
// #define __NUMPAD_3_K4__ KC_3
// #define __NUMPAD_3_K5__ KC_0

// #define _________________NUMPAD_1__________________			__NUMPAD_1_K1__, __NUMPAD_1_K2__, __NUMPAD_1_K3__, __NUMPAD_1_K4__, __NUMPAD_1_K5__
// #define _________________NUMPAD_2__________________			__NUMPAD_2_K1__, __NUMPAD_2_K2__, __NUMPAD_2_K3__, __NUMPAD_2_K4__, __NUMPAD_2_K5__
// #define _________________NUMPAD_3__________________			__NUMPAD_3_K1__, __NUMPAD_3_K2__, __NUMPAD_3_K3__, __NUMPAD_3_K4__, __NUMPAD_3_K5__

#define __SYMBOLS_L1_K1__ KC_EXLM
#define __SYMBOLS_L1_K2__ KC_AT
#define __SYMBOLS_L1_K3__ KC_HASH
#define __SYMBOLS_L1_K4__ KC_DLR
#define __SYMBOLS_L1_K5__ KC_PERC

#define __SYMBOLS_L2_K1__ KC_MINS
#define __SYMBOLS_L2_K2__ KC_LBRC
#define __SYMBOLS_L2_K3__ KC_LCBR
#define __SYMBOLS_L2_K4__ KC_LPRN
#define __SYMBOLS_L2_K5__ KC_LT

#define __META_NAV_L1_K1__ KC_CAPS
#define __META_NAV_L1_K2__ KC_GRV
#define __META_NAV_L1_K3__ LCTL(LSFT(KC_TAB))
#define __META_NAV_L1_K4__ LCTL(LSFT(LGUI(KC_TAB)))
#define __META_NAV_L1_K5__ KC_NUM

#define __SYMBOLS_R1_K1__ KC_CIRC
#define __SYMBOLS_R1_K2__ KC_AMPR
#define __SYMBOLS_R1_K3__ KC_ASTR
#define __SYMBOLS_R1_K4__ KC_UNDS
#define __SYMBOLS_R1_K5__ KC_EQL

#define __SYMBOLS_R2_K1__ KC_GT
#define __SYMBOLS_R2_K2__ KC_RPRN
#define __SYMBOLS_R2_K3__ KC_RCBR
#define __SYMBOLS_R2_K4__ KC_RBRC
#define __SYMBOLS_R2_K5__ KC_PLUS

#define __META_NAV_L2_K1__ C_UNDERSCORECASE
#define __META_NAV_L2_K2__ LCTL(LGUI(KC_TAB))
#define __META_NAV_L2_K3__ LCTL(KC_TAB)
#define __META_NAV_L2_K4__ KC_SCRL
#define __META_NAV_L2_K5__ KC_BSLS

#define _________________META_NAV_L1_______________     __META_NAV_L1_K1__, __META_NAV_L1_K2__, __META_NAV_L1_K3__, __META_NAV_L1_K4__, __META_NAV_L1_K5__
#define _________________META_NAV_R1_______________     __META_NAV_L2_K1__, __META_NAV_L2_K2__, __META_NAV_L2_K3__, __META_NAV_L2_K4__, __META_NAV_L2_K5__

#define ________________SYMBOLS_L1_________________			__SYMBOLS_L1_K1__, __SYMBOLS_L1_K2__, __SYMBOLS_L1_K3__, __SYMBOLS_L1_K4__, __SYMBOLS_L1_K5__
#define ________________SYMBOLS_L2_________________			__SYMBOLS_L2_K1__, __SYMBOLS_L2_K2__, __SYMBOLS_L2_K3__, __SYMBOLS_L2_K4__, __SYMBOLS_L2_K5__
#define ________________SYMBOLS_L3_________________			_________________META_NAV_L1_______________

#define ________________SYMBOLS_R1_________________			__SYMBOLS_R1_K1__, __SYMBOLS_R1_K2__, __SYMBOLS_R1_K3__, __SYMBOLS_R1_K4__, __SYMBOLS_R1_K5__
#define ________________SYMBOLS_R2_________________			__SYMBOLS_R2_K1__, __SYMBOLS_R2_K2__, __SYMBOLS_R2_K3__, __SYMBOLS_R2_K4__, __SYMBOLS_R2_K5__
#define ________________SYMBOLS_R3_________________			_________________META_NAV_R1_______________

#define __FUNCION_1_K1__ KC_MPLY
#define __FUNCION_1_K2__ KC_F7
#define __FUNCION_1_K3__ KC_F8
#define __FUNCION_1_K4__ KC_F9
#define __FUNCION_1_K5__ KC_F10

#define __FUNCION_2_K1__ KC_VOLU
#define __FUNCION_2_K2__ KC_F4
#define __FUNCION_2_K3__ KC_F5
#define __FUNCION_2_K4__ KC_F6
#define __FUNCION_2_K5__ KC_F11

#define __FUNCION_3_K1__ KC_VOLD
#define __FUNCION_3_K2__ KC_F1
#define __FUNCION_3_K3__ KC_F2
#define __FUNCION_3_K4__ KC_F3
#define __FUNCION_3_K5__ KC_F12

#define ________________FUNCTION_1_________________			__FUNCION_1_K1__, __FUNCION_1_K2__, __FUNCION_1_K3__, __FUNCION_1_K4__, __FUNCION_1_K5__
#define ________________FUNCTION_2_________________			__FUNCION_2_K1__, __FUNCION_2_K2__, __FUNCION_2_K3__, __FUNCION_2_K4__, __FUNCION_2_K5__
#define ________________FUNCTION_3_________________			__FUNCION_3_K1__, __FUNCION_3_K2__, __FUNCION_3_K3__, __FUNCION_3_K4__, __FUNCION_3_K5__


#define __RGB_1_K1__ RGB_MOD
#define __RGB_1_K2__ RGB_TOG
#define __RGB_1_K3__ RGB_HUI
#define __RGB_1_K4__ RGB_SAI
#define __RGB_1_K5__ RGB_VAI
#define __RGB_1_K6__ RGB_SPI

#define __RGB_2_K1__ RGB_RMOD
#define __RGB_2_K2__ RGB_TOG
#define __RGB_2_K3__ RGB_HUD
#define __RGB_2_K4__ RGB_SAD
#define __RGB_2_K5__ RGB_VAD
#define __RGB_2_K6__ RGB_SPD


#define _______________________RGB_1________________________			__RGB_1_K1__, __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__, __RGB_1_K5__, __RGB_1_K6__
#define _______________________RGB_2________________________			__RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__, __RGB_2_K6__


// #define __RGB_1_K1__ RGB_TOG
// #define __RGB_1_K2__ RGB_MODE_REVERSE
// #define __RGB_1_K3__ RGB_MODE_FORWARD
// #define __RGB_1_K4__ _______
// #define __RGB_1_K5__ _______

// #define __RGB_2_K1__ KC_RGB_BLT
// #define __RGB_2_K2__ RGB_HUI
// #define __RGB_2_K3__ RGB_SAI
// #define __RGB_2_K4__ RGB_VAI
// #define __RGB_2_K5__ _______

// #define __RGB_3_K1__ KC_RGB_T
// #define __RGB_3_K2__ RGB_HUD
// #define __RGB_3_K3__ RGB_SAD
// #define __RGB_3_K4__ RGB_VAD
// #define __RGB_3_K5__ _______

// #define ___________________RGB_1___________________			__RGB_1_K1__, __RGB_1_K2__, __RGB_1_K3__, __RGB_1_K4__, __RGB_1_K5__
// #define ___________________RGB_2___________________			__RGB_2_K1__, __RGB_2_K2__, __RGB_2_K3__, __RGB_2_K4__, __RGB_2_K5__
// #define ___________________RGB_3___________________			__RGB_3_K1__, __RGB_3_K2__, __RGB_3_K3__, __RGB_3_K4__, __RGB_3_K5__

// MOUSE LAYER

#define __MOUSE_1_K1__ _______
#define __MOUSE_1_K2__ KC_MS_WH_UP
#define __MOUSE_1_K3__ KC_MS_UP
#define __MOUSE_1_K4__ KC_MS_WH_DOWN
#define __MOUSE_1_K5__ _______

#define __MOUSE_2_K1__ KC_MS_WH_LEFT
#define __MOUSE_2_K2__ KC_MS_LEFT
#define __MOUSE_2_K3__ KC_MS_DOWN
#define __MOUSE_2_K4__ KC_MS_RIGHT
#define __MOUSE_2_K5__ KC_MS_WH_RIGHT

#define __MOUSE_3_K1__ _______
#define __MOUSE_3_K2__ KC_MS_WH_UP
#define __MOUSE_3_K3__ KC_MS_WH_DOWN
#define __MOUSE_3_K4__ KC_MS_ACCEL1
#define __MOUSE_3_K5__ KC_MS_ACCEL2

#define __________________MOUSE_1__________________     __MOUSE_1_K1__, __MOUSE_1_K2__, __MOUSE_1_K3__, __MOUSE_1_K4__, __MOUSE_1_K5__
#define __________________MOUSE_2__________________     __MOUSE_2_K1__, __MOUSE_2_K2__, __MOUSE_2_K3__, __MOUSE_2_K4__, __MOUSE_2_K5__
#define __________________MOUSE_3__________________     __MOUSE_3_K1__, __MOUSE_3_K2__, __MOUSE_3_K3__, __MOUSE_3_K4__, __MOUSE_3_K5__

#define __AMOUSE_1_K1_ _______
#define __AMOUSE_1_K2_ KC_MS_WH_UP
#define __AMOUSE_1_K3_ KC_MS_UP
#define __AMOUSE_1_K4_ KC_MS_WH_DOWN
#define __AMOUSE_1_K5_ _______

#define __AMOUSE_2_K1_ KC_MS_WH_LEFT
#define __AMOUSE_2_K2_ KC_BTN3
#define __AMOUSE_2_K3_ KC_BTN2
#define __AMOUSE_2_K4_ KC_BTN1
#define __AMOUSE_2_K5_ KC_MS_WH_RIGHT

#define __AMOUSE_3_K1_ EE_CLR
#define __AMOUSE_3_K2_ KC_MS_WH_UP
#define __AMOUSE_3_K3_ KC_MS_WH_DOWN
#define __AMOUSE_3_K4_ KC_MS_ACCEL1
#define __AMOUSE_3_K5_ KC_MS_ACCEL2

#define _______________AUTO_MOUSE_1________________     __AMOUSE_1_K1_, __AMOUSE_1_K2_, __AMOUSE_1_K3_, __AMOUSE_1_K4_, __AMOUSE_1_K5_
#define _______________AUTO_MOUSE_2________________     __AMOUSE_2_K1_, __AMOUSE_2_K2_, __AMOUSE_2_K3_, __AMOUSE_2_K4_, __AMOUSE_2_K5_
#define _______________AUTO_MOUSE_3________________     __AMOUSE_3_K1_, __AMOUSE_3_K2_, __AMOUSE_3_K3_, __AMOUSE_3_K4_, __AMOUSE_3_K5_

//                                                      Zoom Home           Add Line            Add Arc            Add Polygon         Add Circle
#define ___________________KICAD_0_________________     KC_HOME,            LCTL(LSFT(KC_L)),   LCTL(LSFT(KC_A)),  LCTL(LSFT(KC_P)),   LCTL(LSFT(KC_C))
//                                                      Drag 45 degree      Move Dialog         Flip               Pos Relative        Select Net
#define ___________________KICAD_1_________________     KC_D,               LSFT(KC_M),         KC_F,              LSFT(KC_P),         KC_GRV
//                                                      Create Track        End Track           Edit Property      Move                Fill Zones
#define ___________________KICAD_2_________________     LCTL_T(KC_X),       LGUI_T(KC_END),     LALT_T(KC_E),      LSFT_T(KC_M),       KC_B
//                                                      Undo                Redo                Rotate             Add Via             Front<->Back
#define ___________________KICAD_3_________________     LCTL(KC_X),         LCTL(KC_Y),         KC_R,              LCTL(LSFT(KC_V)),   KC_V

// Shortcuts for general kicad aliases
#define M_KI_SEL_TR KC_U
#define M_KI_MV     KC_M
#define M_KI_MVREL  LSFT(KC_P)

#define __KICAD_R0_L__ KC_ESC
#define __KICAD_R1_L__ KC_TAB            // Drag free angl
#define __KICAD_R2_L__ LCTL(KC_C)        // Copy
#define __KICAD_R3_L__ LCTL(KC_V)        // Paste
#define __KICAD_R0_R__ LCTL(LSFT(KC_T))  // Add Text
#define __KICAD_R1_R__ LSFT(KC_GRV)      // Stop SelctNet
#define __KICAD_R2_R__ LCTL(KC_B)        // Unfill Zones
#define __KICAD_R3_R__ LCTL(LSFT(KC_M))  // Measure
#define __KICAD_TH_L__ KC_DEL            // Delete
#define __KICAD_TH_C__ KC_ENT            // Enter
#define __KICAD_TH_R__ LSFT(KC_DEL)      // Delete track, note that this only deletes the current copper line up to pads or vias
#define __KICAD_R4_1__ __KICAD_R3_R__
#define __KICAD_R4_2__ LALT(KC_3)        // 3D Viewer
#define __KICAD_R4_3__ M_KI_SEL_TR       // Select track, double press for all connected... // used to be this --> LCTL(KC_E)        // Edit Footprint


#define ___________________GAMES_0_________________     KC_F1,   KC_F2,   KC_C,    KC_V,    KC_G
#define ___________________GAMES_1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_D
#define ___________________GAMES_2_________________     KC_A,    KC_F,    KC_TAB,  KC_L,    KC_H
#define ___________________GAMES_3_________________     KC_T,    KC_COMM, KC_K,    KC_SCLN, KC_DOT
#define __GAMES_R0_L__ KC_F4
#define __GAMES_R1_L__ KC_Z
#define __GAMES_R2_L__ KC_P
#define __GAMES_R3_L__ KC_LSFT
#define __GAMES_R0_R__ KC_N
#define __GAMES_R1_R__ KC_Y
#define __GAMES_R2_R__ KC_F7
#define __GAMES_R3_R__ KC_ESC
#define __GAMES_TH_L__ KC_LALT
#define __GAMES_TH_C__ KC_X
#define __GAMES_TH_R__ KC_B
#define __GAMES_R4_1__ KC_J
#define __GAMES_R4_2__ __GAMES_R3_R__
#define __GAMES_R4_3__ KC_LCTL

// clang-format on
