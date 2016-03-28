/***********************************************************************
 * File          :  keymap_krid78
 * Author(s)     :  Daniel Kriesten
 * Email         :  daniel@die-kriestens.de
 * Creation Date :  Do 24 Mär 17:43:21 2016
 **********************************************************************/

/* #include "keymap_common.h" */
#include "keymap_german_osx.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  ß|  ´|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  Ü|  +|    #|
     * |-----------------------------------------------------------|
     * |FN0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä|  Return|
     * |-----------------------------------------------------------|
     * |LShift  |  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  -|    RShift|
     * |-----------------------------------------------------------|
     * |Ctrl|LAlt|LGui|      Space             |Left|Down|  Up|Righ|
     * `-----------------------------------------------------------'
     * FN7 - is Tab or switches to Layer2
     */
    KEYMAP_ANSI( //0
        ESC,  DE_1, DE_2, DE_3, DE_4, DE_5, DE_6, DE_7, DE_8,    DE_9,   DE_0,    DE_SS, DE_ACUT, BSPC,    \
        FN1,  DE_Q, DE_W, DE_E, DE_R, DE_T, DE_Z, DE_U, DE_I,    DE_O,   DE_P,    DE_UE, DE_PLUS, DE_HASH, \
        FN0,  DE_A, DE_S, DE_D, DE_F, DE_G, DE_H, DE_J, DE_K,    DE_L,   DE_OE,   DE_AE, ENT,     \
        LSFT, DE_Y, DE_X, DE_C, DE_V, DE_B, DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS, RSFT,  \
        LCTL, LALT, LGUI,             SPC,              LEFT,    DOWN,   UP,      RGHT),
    /* Keymap 1: Fn Layer
     * ,-----------------------------------------------------------.
     * |  ^| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |   |   |   |   |   |FN4|FN5|  FN6|
     * |-----------------------------------------------------------|
     * |FN0   |   |   |   |   |   |Lef|Dow| Up|Rgh|FN2|FN3|  Return|
     * |-----------------------------------------------------------|
     * |LShift  |  <|   |   |   |   |   |   |   |   |   |    Rshift|
     * |-----------------------------------------------------------|
     * |RCtl|RAlt|RGui|      Space             |Mute|Vol-|Vol+|Play|
     * `-----------------------------------------------------------'
     */
    KEYMAP_ANSI( //1
        DE_CIRC, F1,      F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  DEL, \
        TRNS,    TRNS,    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN4,  FN5,  FN6, \
        TRNS,    TRNS,    TRNS, TRNS, TRNS, TRNS, LEFT, DOWN, UP,   RGHT, FN2,  FN3,  TRNS, \
        TRNS,    DE_LESS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        RCTL,    RALT,    RGUI,           SPC,          MUTE, VOLD, VOLU, MPLY),
    /* Keymap 2: Fn Layer
     * ,-----------------------------------------------------------.
     * |  ^| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   Pwr |
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |   |   |   |   |   |FN4|FN5|  FN6|
     * |-----------------------------------------------------------|
     * |FN0   |   |   |   |   |   |Lef|Dow| Up|Rgh|FN2|FN3|  Return|
     * |-----------------------------------------------------------|
     * |LShift  |  <|   |   |   |   |   |   |   |   |   |    Rshift|
     * |-----------------------------------------------------------|
     * |Ctrl|LAlt|LGui|      Space             | FN7| FN8| FN9|Righ|
     * `-----------------------------------------------------------'
     */
    KEYMAP_ANSI( //2
        DE_CIRC, F1,      F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  PWR, \
        TRNS,    TRNS,    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, FN4,  FN5,  FN6, \
        TRNS,    TRNS,    TRNS, TRNS, TRNS, TRNS, LEFT, DOWN, UP,   RGHT, FN2,  FN3,  TRNS, \
        TRNS,    DE_LESS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
        LCTL,    LALT,    LGUI,             SPC,              FN7,  FN8,  FN9,   RGHT),
};

/*
 * Fn action definition
 */

const uint16_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_MOMENTARY(1),           // Layer1
    [1] = ACTION_LAYER_TAP_KEY(2, KC_TAB), // Tab or FN2
    [2] = ACTION_MODS_KEY(MOD_LALT, KC_5),     // [
    [3] = ACTION_MODS_KEY(MOD_LALT, KC_6),     // ]
    [4] = ACTION_MODS_KEY(MOD_LALT, KC_8),     // {
    [5] = ACTION_MODS_KEY(MOD_LALT, KC_9),     // }
    [6] = ACTION_MODS_KEY(MOD_LALT, KC_7),     // |
    [7] = ACTION_BACKLIGHT_TOGGLE(),           // Backlight
    [8] = ACTION_BACKLIGHT_DECREASE(),         // Backlight-
    [9] = ACTION_BACKLIGHT_INCREASE(),        // Backlight+
};

/*
 * vim: ts=4:sw=4:sts=4:tw=80:fileformat=unix
 * vim: comments& comments+=b\:* formatoptions& formatoptions+=or
 */

