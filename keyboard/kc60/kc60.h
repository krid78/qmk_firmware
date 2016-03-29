#ifndef KC60_H
#define KC60_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array

/* ISO-Keymap */
#define KEYMAP( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
        K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
        K40, K41, K42,           K45,                K49, K4A, K4B, K4C, K4D  \
        ) { \
    {K00, K01, K02, K03,   K04,   K05, K06,   K07,   K08,   K09, K0A, K0B, K0C, K0D }, \
    {K10, K11, K12, K13,   K14,   K15, K16,   K17,   K18,   K19, K1A, K1B, K1C, K1D }, \
    {K20, K21, K22, K23,   K24,   K25, K26,   K27,   K28,   K29, K2A, K2B, K2C, K2D }, \
    {K30, K31, K32, K33,   K34,   K35, K36,   K37,   K38,   K39, K3A, K3B, K3C, K3D }, \
    {K40, K41, K42, KC_NO, KC_NO, K45, KC_NO, KC_NO, KC_NO, K49, K4A, K4B, K4C, K4D }  \
}

/* ANSI valiant. No extra keys for ISO */
#define KEYMAP_ANSI( \
        K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
        K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
        K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,      K2D, \
        K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, \
        K40, K41, K42,           K45,                     K4A, K4B, K4C, K4D  \
        ) { \
    {K00, K01,   K02, K03,   K04,   K05, K06,   K07,   K08,   K09,   K0A, K0B, K0C,   K0D}, \
    {K10, K11,   K12, K13,   K14,   K15, K16,   K17,   K18,   K19,   K1A, K1B, K1C,   K1D}, \
    {K20, K21,   K22, K23,   K24,   K25, K26,   K27,   K28,   K29,   K2A, K2B, KC_NO, K2D}, \
    {K30, KC_NO, K32, K33,   K34,   K35, K36,   K37,   K38,   K39,   K3A, K3B, KC_NO, K3D}, \
    {K40, K41,   K42, KC_NO, KC_NO, K45, KC_NO, KC_NO, KC_NO, KC_NO, K4A, K4B, K4C,   K4D}  \
}

void matrix_init_user(void);
void matrix_scan_user(void);
void led_set_user(uint8_t usb_led);

#endif