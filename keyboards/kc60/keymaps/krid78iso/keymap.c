/***********************************************************************
 * File          :  krid78iso
 * Author(s)     :  Daniel Kriesten
 * Email         :  daniel@die-kriestens.de
 * Creation Date :  Mo 18 Apr 07:45:37 2016 @USER@
 ***********************************************************************
 * TODO: What is this file for?
 */

#include "kc60.h"
#include "keymap_extras/keymap_german_osx.h"
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#include "krid78pwd.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  ß|  ´|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Z|  U|  I|  O|  P|  Ü|  +|    ||
     * |-----------------------------------------------------------|
     * |FN0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  Ö|  Ä|  #|Retn|
     * |-----------------------------------------------------------|
     * |LSft|  <|  Y|  X|  C|  V|  B|  N|  M|  ,|  .|  -|RShift|   |
     * |-----------------------------------------------------------|
     * |Ctrl|LAlt|LGui|      Space             |Left|Down|  Up|Righ|
     * `-----------------------------------------------------------'
     * FN0 - is Tab or switches to Layer2
     * the last two keys in the 4th row are pysically exchanged ->
     * thus what ever is given in at pos 4,13 is key 4,14
     */
    KEYMAP( //0
        KC_ESC,  DE_OSX_1,    DE_OSX_2, DE_OSX_3, DE_OSX_4, DE_OSX_5, DE_OSX_6, DE_OSX_7, DE_OSX_8, DE_OSX_9,    DE_OSX_0,   DE_OSX_SS,   DE_OSX_ACUT, KC_BSPC,     \
        F(0),    DE_OSX_Q,    DE_OSX_W, DE_OSX_E, DE_OSX_R, DE_OSX_T, DE_OSX_Z, DE_OSX_U, DE_OSX_I, DE_OSX_O,    DE_OSX_P,   DE_OSX_UE,   DE_OSX_PLUS, DE_OSX_PIPE, \
        MO(1),   DE_OSX_A,    DE_OSX_S, DE_OSX_D, DE_OSX_F, DE_OSX_G, DE_OSX_H, DE_OSX_J, DE_OSX_K, DE_OSX_L,    DE_OSX_OE,  DE_OSX_AE,   DE_OSX_HASH, KC_ENT,      \
        KC_LSFT, DE_OSX_LESS, DE_OSX_Y, DE_OSX_X, DE_OSX_C, DE_OSX_V, DE_OSX_B, DE_OSX_N, DE_OSX_M, DE_OSX_COMM, DE_OSX_DOT, DE_OSX_MINS, KC_ENT,      KC_RSFT,     \
        KC_LCTL, KC_LALT,     KC_LGUI,                      KC_SPC,                                              KC_LEFT,     KC_DOWN,    KC_UP,       KC_RGHT),
    /* Keymap 1: Fn Layer
     * ,-----------------------------------------------------------.
     * |  ^| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |  {|  }|    ||
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |Lef|Dow| Up|Rgh|  [|  ]|   |Retn|
     * |-----------------------------------------------------------|
     * |LShift  |   |   |   |   |   |   |   |   |   |   |Rshift|   |
     * |-----------------------------------------------------------|
     * |RCtl|RAlt|RGui|      Space             |Mute|Vol-|Vol+|Play|
     * `-----------------------------------------------------------'
     */
    KEYMAP( //1
        DE_OSX_CIRC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      KC_F11,      KC_F12,      KC_DEL,      \
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     DE_OSX_LCBR, DE_OSX_RCBR, DE_OSX_PIPE, \
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, DE_OSX_LBRC, DE_OSX_RBRC, DE_OSX_PIPE, KC_TRNS,     \
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, \
        KC_RCTL,     KC_RALT, KC_RGUI,                   KC_SPC,                                      KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY),
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
    KEYMAP( //2
        RESET,   M(0),    M(1),    M(2),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR,  \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                      BL_TOGG, BL_DEC,  BL_INC,  KC_TRNS),
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
 * Fn action definition
 */
const uint16_t fn_actions[] PROGMEM = {
    [0] = ACTION_LAYER_TAP_KEY(2, KC_TAB), // Tab or FN2
    /* [1] = ACTION_BACKLIGHT_TOGGLE(),       // Backlight */
    /* [2] = ACTION_BACKLIGHT_DE_OSXCREASE(),     // Backlight- */
    /* [3] = ACTION_BACKLIGHT_INCREASE(),     // Backlight+ */
};


/*
 * vim: ts=4:sw=4:sts=4:tw=160:fileformat=unix
 * vim: comments& comments+=b\:* formatoptions& formatoptions+=or
 */

