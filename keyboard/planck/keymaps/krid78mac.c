/***********************************************************************
 * File          :  krid78mac.c
 * Author(s)     :  Daniel Kriesten
 * Email         :  daniel@die-kriestens.de
 * Creation Date :  Fr 11 Mär 22:40:59 2016
 ***********************************************************************
 * this is my PLANCK layout.
 * I want a qwertz-layout, usable on a mac with no obvious specialities.
 */

#include "planck.h"
#include "keymap_extras/keymap_german_osx.h"
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#include "krid78pwd.h"

/* Each layer gets a name for readability, which is then used in the keymap matrix below.
 * The underscores don't mean anything - you can have a layer called STUFF or any other name.
 * Layer names don't all need to be of the same length, obviously, and you can also skip them
 * entirely and just use numbers.
 */
#define _QW 0   /* normal QWERTZ */
#define _LW 1   /* lower key pressed */
#define _RS 2   /* raise key pressed */
#define _CM 3   /* bottom left key pressed */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = { /* Qwerty {{{
    * ,-----------------------------------------------------------------------.
    * | Esc | q   | w   | e   | r   | t   | z   | u   | i   | o   | p   |  ü  |
    * |-----------------------------------------------------------------------|
    * | Tab | a   | s   | d   | f   | g   | h   | j   | k   | l   | ö   |  ä  |
    * |-----------------------------------------------------------------------|
    * | Sft | y   | x   | c   | v   | b   | n   | m   |  ,  |  .  |  -  | Ent |
    * |-----------------------------------------------------------------------|
    * | MO3 | Ctl | Alt | Gui |Lower|   Space   |Raise|Left |Down | Up  |Right|
    * `-----------------------------------------------------------------------'
    * Ent is tap-combined with L-Shift (R-Shift is not available)
    */
    {KC_ESC,  DE_OSX_Q,    DE_OSX_W,    DE_OSX_E,    DE_OSX_R,    DE_OSX_T,    DE_OSX_Z,    DE_OSX_U,    DE_OSX_I,    DE_OSX_O,    DE_OSX_P,    DE_OSX_UE},
    {KC_TAB,  DE_OSX_A,    DE_OSX_S,    DE_OSX_D,    DE_OSX_F,    DE_OSX_G,    DE_OSX_H,    DE_OSX_J,    DE_OSX_K,    DE_OSX_L,    DE_OSX_OE,   DE_OSX_AE},
    {KC_LSFT, DE_OSX_Y,    DE_OSX_X,    DE_OSX_C,    DE_OSX_V,    DE_OSX_B,    DE_OSX_N,    DE_OSX_M,    DE_OSX_COMM, DE_OSX_DOT,  DE_OSX_MINS, SFT_T(KC_ENT)},
    {MO(_CM), KC_LCTL, KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
    /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
  }, /* }}} */
  [_LW] = { /* LOWER (Left Modifier, blue) {{{
    * ,-----------------------------------------------------------------------.
    * | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | ß   | Bspc|
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     | [   | ]   | #   | +   |
    * |-----------------------------------------------------------------------|
    * |     | <   |     |     |     |     |     |     |     |     | |   | Bspc|
    * |-----------------------------------------------------------------------|
    * |     | RCtl| RAlt| RGui|Lower|   Space   |Raise| Mute| Vol-| Vol+| Play|
    * `-----------------------------------------------------------------------'
    */
    {DE_OSX_1,    DE_OSX_2,    DE_OSX_3,    DE_OSX_4,    DE_OSX_5,    DE_OSX_6,    DE_OSX_7,    DE_OSX_8,    DE_OSX_9,    DE_OSX_0,    DE_OSX_SS,   KC_BSPC},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_OSX_LBRC, DE_OSX_RBRC, DE_OSX_HASH, DE_OSX_PLUS},
    {KC_TRNS, DE_OSX_LESS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_OSX_PIPE, KC_TRNS},
    {KC_TRNS, KC_RCTL,  KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY}
    /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
  }, /* }}} */
  [_RS] = { /* RAISE (Right Modifier, orange) {{{
    * ,-----------------------------------------------------------------------.
    * | !   | "   | §   | $   | %   | &   | /   | (   | )   | =   | ?   | ´   |
    * |-----------------------------------------------------------------------|
    * | ^   |     |     |     |     |     |     |     | {   | }   | '   | *   |
    * |-----------------------------------------------------------------------|
    * |     | >   |     |     |     |     |     |     |     |     | \   |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |           |     |     |     |     |     |
    * `-----------------------------------------------------------------------'
    * " - just a closing ""
    */
    {DE_OSX_EXLM, DE_OSX_DQOT, DE_OSX_PARA, DE_OSX_DLR,  DE_OSX_PERC, DE_OSX_AMPR, DE_OSX_SLSH, DE_OSX_LPRN, DE_OSX_RPRN, DE_OSX_EQL,  DE_OSX_QST,  DE_OSX_ACUT},
    {DE_OSX_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_OSX_LCBR, DE_OSX_RCBR, DE_OSX_QUOT, DE_OSX_ASTR},
    {KC_TRNS, DE_OSX_MORE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_OSX_BSLS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
    /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/


  }, /* }}} */
  [_CM] = { /* Control Layer {{{
    * ,-----------------------------------------------------------------------.
    * |RESET| M(0)| M(1)| M(2)|     |     |     |     |     |     |     | `   |
    * |-----------------------------------------------------------------------|
    * | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |           |     |     | Blt-| Blt+|     |
    * `-----------------------------------------------------------------------'
    */
    {RESET,   M(0),    M(1),    M(2),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_OSX_ACUT},
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_DEC,  BL_INC,  KC_TRNS}
    /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
  } /* }}} */
};

const uint16_t PROGMEM fn_actions[] = {

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
 * vim: ts=2:sw=2:sts=2:tw=80:fileformat=unix
 * vim: comments& comments+=b\:* formatoptions& formatoptions+=or
 */

