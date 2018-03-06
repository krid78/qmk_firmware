/***********************************************************************
 * File          :  krid78ansi_pc
 * Author(s)     :  Daniel Kriesten
 * Email         :  daniel@die-kriestens.de
 * Creation Date :  Do 24 Mär 17:43:21 2016
 ***********************************************************************
 * TODO: What is this file for?
 */

#include "kc60.h"
#include "keymap_extras/keymap_german.h"
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#include "krid78pwd.h"

/* Layer names */
#define _BASE 0
#define _LYR1 1
#define _LYR2 2

/* shortcuts to improve readability */
#define DUALTAB LT(_LYR2, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
    [_BASE] = LAYOUT_60_ansi( /* Basic Mac QWERTZ on ANSI keyboard */
        KC_ESC,  DE_1,    DE_2,    DE_3,   DE_4,  DE_5,    DE_6,    DE_7,  DE_8,     DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC, \
        F(0),    DE_Q,    DE_W,    DE_E,   DE_R,  DE_T,    DE_Z,    DE_U,  DE_I,     DE_O,    DE_P,    DE_UE,   DE_PLUS, DE_HASH, \
        MO(1),   DE_A,    DE_S,    DE_D,   DE_F,  DE_G,    DE_H,    DE_J,  DE_K,     DE_L,    DE_OE,   DE_AE,   KC_ENT,  \
        KC_LSFT, DE_Y,    DE_X,    DE_C,   DE_V,  DE_B,    DE_N,    DE_M,  DE_COMM,  DE_DOT,  DE_MINS, KC_RSFT, \
        KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                  KC_NO,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
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
    [_LYR1] = LAYOUT_60_ansi( /* Fn-Layer */
        DE_CIRC, KC_F1,   KC_F2,       KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,      KC_F11,      KC_F12,      KC_DEL,      \
        KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     DE_LCBR, DE_RCBR, DE_PIPE, \
        KC_TRNS,     KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, DE_LBRC, DE_RBRC, KC_NO,       KC_TRNS,     \
        KC_TRNS,     KC_NO,   DE_LESS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_NO,       \
        KC_RCTL,     KC_RALT, KC_RGUI,     KC_SPC,  KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY),
    /* Keymap 2: Fn Layer
     * ,-----------------------------------------------------------.
     * |RESET| M0| M1| M2|   |   |   |   |   |   |   |   |   | Pwr |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * |        |  <|   |   |   |   |   |   |   |   |   |          |
     * |-----------------------------------------------------------|
     * |Ctrl|LAlt|LGui|      Space             |Blt0|Blt-|Blt+|    |
     * `-----------------------------------------------------------'
     */
    [_LYR2] = LAYOUT_60_ansi( /* control layer */
        RESET,   M(0),    M(1),    M(2),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR,  \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS, \
        KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   \
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_NO,   BL_TOGG, BL_DEC,  BL_INC,  KC_TRNS),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(2, KC_TAB), // Tab or FN2
    /* [1] = ACTION_BACKLIGHT_TOGGLE(),       // Backlight */
    /* [2] = ACTION_BACKLIGHT_DECREASE(),     // Backlight- */
    /* [3] = ACTION_BACKLIGHT_INCREASE(),     // Backlight+ */
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
#ifdef MAC_PWD
        return MAC_PWD;
#else
        return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
#endif
      }
      break;
    case 1: // this would trigger when you hit a key mapped as M(1)
      if (record->event.pressed) {
#ifdef TUC_PWD
        return TUC_PWD;
#else
        return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
#endif
      }
      break;
    case 2: // this would trigger when you hit a key mapped as M(2)
      if (record->event.pressed) {
#ifdef ONE_PWD
        return ONE_PWD;
#else
        return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
#endif
      }
      break;
  }
  return MACRO_NONE;
};

/*
 * vim: ts=4:sw=4:sts=4:tw=200:fileformat=unix
 * vim: comments& comments+=b\:* formatoptions& formatoptions+=or
 */

