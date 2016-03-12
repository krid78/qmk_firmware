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
  {KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UE},
  {KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_OE,   DE_AE},
  {KC_LSFT, DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, ALT_T(KC_ENT)},
  {MO(_CM), KC_LCTL, KC_LALT, KC_LGUI, MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
  /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
}, /* }}} */
[_LW] = { /* LOWER (Left Modifier, blue) {{{
    * ,-----------------------------------------------------------------------.
    * | ^   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 0   | Bspc|
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     | [   | ]   | #   | +   |
    * |-----------------------------------------------------------------------|
    * |     | <   |     |     |     |     |     |     |     |     | |   | Bspc|
    * |-----------------------------------------------------------------------|
    * |     | RCtl| RAlt| RGui|Lower|   Space   |Raise| Mute| Vol-| Vol+| Play|
    * `-----------------------------------------------------------------------'
    */
  {DE_CIRC, DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_LBRC, DE_RBRC, DE_HASH, DE_PLUS},
  {KC_TRNS, DE_LESS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_PIPE, KC_BSPC},
  {KC_TRNS, KC_RCTL,  KC_RALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY}
  /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
}, /* }}} */
[_RS] = { /* RAISE (Right Modifier, orange) {{{
    * ,-----------------------------------------------------------------------.
    * | ~   |     |     |     |     |     |     |     |     |     | ß   | ´   |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     | {   | }   | '   | *   |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     | \   |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |           |     |     |     |     |     |
    * `-----------------------------------------------------------------------'
    */
  {DE_TILD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_SS,   DE_ACUT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_LCBR, DE_RCBR, DE_QUOT, DE_ASTR},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_BSLS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
}, /* }}} */
[_CM] = { /* Control Layer {{{
    * ,-----------------------------------------------------------------------.
    * |     |     |     |     |     |     |     |     |     |     |     | `   |
    * |-----------------------------------------------------------------------|
    * | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |     |     |     |     |     |     |     |
    * |-----------------------------------------------------------------------|
    * |     |     |     |     |     |           |     |     | Blt-| Blt+|     |
    * `-----------------------------------------------------------------------'
    */
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_ACUT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(0),    M(1),    KC_TRNS}
  /*------|--------|--------|--------|-Lower--|------Space------|-Raise--|--------|--------|--------|--------*/
} /* }}} */
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_decrease();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
        case 1:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_increase();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
