#pragma once
#include "quantum.h"

#define ___ KC_NO

#define LAYOUT( \
           K00,   K01,   K02,   K03,   K04,   K05,   \
           K10,   K11,   K12,   K13,   K14,   K15,   \
           K20,   K21,   K22,   K23,   K24,   K25,   \
    K36,   K30,   K31,   K32,   K33,   K34,   K35,   \
    K46,   K40,   K41,   K42,   K43,   K44,   K45   \
) { \
  { K05, K04, K03, K02, K01, K00, KC_NO }, \
  { K15, K14, K13, K12, K11, K10, KC_NO }, \
  { K25, K24, K23, K22, K21, K20, KC_NO }, \
  { K35, K34, K33, K32, K31, K30,   K36 }, \
  { K45, K44, K43, K42, K41, K40,   K46 }  \
}

// #define LAYOUT( \
// 	k0B, k0C, k0D, k0E, k0F, k0G, k1B, k1C, k1D, k1E, k1F, k1G, k2B, k2C, k2D, k2E, k2F, k2G, k3A, k3B, k3C, k3D, k3E, k3F, k3G, k4A, k4B, k4C, k4D, k4E, k4F, k4G \
// ) { \
// 	{XXX, k0B, k0C, k0D, k0E, k0F, k0G}, \
// 	{XXX, k1B, k1C, k1D, k1E, k1F, k1G}, \
// 	{XXX, k2B, k2C, k2D, k2E, k2F, k2G}, \
// 	{k3A, k3B, k3C, k3D, k3E, k3F, k3G}, \
// 	{k4A, k4B, k4C, k4D, k4E, k4F, k4G} \
// }
