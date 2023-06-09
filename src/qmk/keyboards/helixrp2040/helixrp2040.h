#pragma once
#include "quantum.h"

#define ___ KC_NO
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, L36, R36, R30, R31, R32, R33, R34, R35, \
    L40, L41, L42, L43, L44, L45, L46, R46, R40, R41, R42, R43, R44, R45 \
) { \
    { L00, L01, L02, L03, L04, L05, KC_NO }, \
    { L10, L11, L12, L13, L14, L15, KC_NO }, \
    { L20, L21, L22, L23, L24, L25, KC_NO }, \
    { L30, L31, L32, L33, L34, L35, L36 }, \
    { L40, L41, L42, L43, L44, L45, L46 }, \
    { R05, R04, R03, R02, R01, R00, KC_NO }, \
    { R15, R14, R13, R12, R11, R10, KC_NO }, \
    { R25, R24, R23, R22, R21, R20, KC_NO }, \
    { R35, R34, R33, R32, R31, R30, R36 }, \
    { R45, R44, R43, R42, R41, R40, R46 } \
}

// #define LAYOUT( \
// 	k0B, k0C, k0D, k0E, k0F, k0G, k0I, k0J, k0K, k0L, k0M, k0N, k1B, k1C, k1D, k1E, k1F, k1G, k1I, k1J, k1K, k1L, k1M, k1N, k2B, k2C, k2D, k2E, k2F, k2G, k2I, k2J, k2K, k2L, k2M, k2N, k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, k3N, k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, k4M, k4N \
// ) { \
// 	{XXX, k0B, k0C, k0D, k0E, k0F, k0G, XXX, k0I, k0J, k0K, k0L, k0M, k0N}, \
// 	{XXX, k1B, k1C, k1D, k1E, k1F, k1G, XXX, k1I, k1J, k1K, k1L, k1M, k1N}, \
// 	{XXX, k2B, k2C, k2D, k2E, k2F, k2G, XXX, k2I, k2J, k2K, k2L, k2M, k2N}, \
// 	{k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, k3L, k3M, k3N}, \
// 	{k4A, k4B, k4C, k4D, k4E, k4F, k4G, k4H, k4I, k4J, k4K, k4L, k4M, k4N} \
// }
