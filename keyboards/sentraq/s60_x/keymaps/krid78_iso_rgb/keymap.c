/***********************************************************************
 * File          :  keymap.c
 * Author(s)     :  Daniel Kriesten
 * Creation Date :  Mo 18 Apr 07:45:37 2016 @USER@
 ***********************************************************************
 * TODO: What is this file for?
 */

#include "dz60.h"
#include "keymap_extras/keymap_german.h"
#ifdef BACKLIGHT_ENABLE
#include "backlight.h"
#endif
#include "krid78xtra.h"

/* Layer names */
#define _BASE 0
#define _LYR1 1
#define _LYR2 2
#define _LYR3 2
#define _LYR4 2

/* shortcuts to improve readability */
#define DUALTAB LT(_LYR2, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-------------------------------------------------------------------------.
     * | Esc|   1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   ß|   ´| Backsp |
     * |-------------------------------------------------------------------------|
     * | DTab |   Q|   W|   E|   R|   T|   Z|   U|   I|   O|   P|   Ü|   +|      |
     * |-------------------------------------------------------------------. Retn|
     * | MO(1) |   A|   S|   D|   F|   G|   H|   J|   K|   L|   Ö|   Ä|   #|     |
     * |-------------------------------------------------------------------------|
     * | LSft|   <|   Y|   X|   C|   V|   B|   N|   M|   ,|   .|   -| RShift|Lead| <- remember: those two keys are exchanged
     * |-------------------------------------------------------------------------|
     * | Ctrl| LGui| LAlt|        Space                 | Left| Down|   Up| Righ |
     * `-------------------------------------------------------------------------'
     * DTab is Tab or switches to Layer2
     * the last two keys in the 4th row are pysically exchanged ->
     * thus what ever is given in at pos 4,13 is key 4,14
     */
    [_BASE] = LAYOUT_60_iso_split_rshift( /* Basic QWERTZ */
        KC_ESC,  DE_1,    DE_2,    DE_3,   DE_4,  DE_5,    DE_6,    DE_7,  DE_8,     DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC, \
        DUALTAB, DE_Q,    DE_W,    DE_E,   DE_R,  DE_T,    DE_Z,    DE_U,  DE_I,     DE_O,    DE_P,    DE_UE,   DE_PLUS,          \
        MO(1),   DE_A,    DE_S,    DE_D,   DE_F,  DE_G,    DE_H,    DE_J,  DE_K,     DE_L,    DE_OE,   DE_AE,   DE_HASH, KC_ENT,  \
        KC_LSFT, DE_LESS, DE_Y,    DE_X,   DE_C,  DE_V,    DE_B,    DE_N,  DE_M,     DE_COMM, DE_DOT,  DE_MINS, KC_RSFT, KC_LEAD, \
        KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
    /* Keymap 1: Fn Layer
     * ,-----------  ------------------------------------------------------------.
     * |   ^|  F1|  F2|  F3|  F4|  F5|  F6|  F7|  F8|  F9| F10| F11| F12| Delete |
     * |-------------------------------------------------------------------------|
     * |      |   @|    |   €|    |    |    |    |    |    |    |   {|   }|     ||
     * |-------------------------------------------------------------------------|
     * |       |    |    |    |    |    | Lef| Dow|  Up| Rgh|   [|   ]|   ~| Retn|
     * |-------------------------------------------------------------------------|
     * | LSft|   ||    |    |    |    |    |   ~|    |    |    |    | RShift| Ins| <- remember: those two keys are exchanged
     * |-------------------------------------------------------------------------|
     * | RCtl|AltGr| LAlt|        Space                  | Home| PGDN| PGUP|  End|
     * `-------------------------------------------------------------------------'
     */
    [_LYR1] = LAYOUT_60_iso_split_rshift( /* Fn-Layer */
        DE_CIRC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
        KC_TRNS, DE_AT,   KC_TRNS, DE_EURO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, DE_LCBR, DE_RCBR,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, DE_LBRC, DE_RBRC, DE_TILD, KC_TRNS, \
        KC_LSFT, DE_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DE_TILD, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_RSFT, KC_INS, \
        KC_RCTL, KC_ALGR, KC_LALT,                   KC_SPC,                                       KC_HOME, KC_PGDN, KC_PGUP, KC_END),
    /* Keymap 2: Fn Layer
     * ,-----------  ------------------------------------------------------------.
     * | Rst|  M0|  M1|  M2|    |    |    |    |    |    |    |    |    |        |
     * |-------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    |      |
     * |-------------------------------------------------------------------------|
     * |       |    |    |    |    |    |    |    |    |    |    |    |    |     |
     * |-------------------------------------------------------------------------|
     * |     |   <|    |    |    |    |    |    |    |    |    |    |       |    | <- remember: those two keys are exchanged
     * |-------------------------------------------------------------------------|
     * | Blt0| Blt-| Blt+|        Space                  | Mute| Vol-| Vol+|     |
     * `-------------------------------------------------------------------------'
     */
    [_LYR2] = LAYOUT_60_iso_split_rshift( /* control layer */
        RESET,   M(0),    M(1),    M(2),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR,  \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT, KC_LEAD, \
        BL_TOGG, BL_DEC,  BL_INC,                    KC_SPC,                                       KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS),
};

/*
 * Fn action definition
 */
const uint16_t fn_actions[] PROGMEM = {
    /* [0] = ACTION_LAYER_TAP_KEY(2, KC_TAB), // Tab or FN2 */
    /* [1] = ACTION_BACKLIGHT_TOGGLE(),       // Backlight */
    /* [2] = ACTION_BACKLIGHT_DECREASE(),     // Backlight- */
    /* [3] = ACTION_BACKLIGHT_INCREASE(),     // Backlight+ */
};

/** keyboard macros
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0: // this would trigger when you hit a key mapped as M(0)
            if (record->event.pressed) {
#ifdef KPASS_PWD
                return KPASS_PWD;
#else
                return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
#endif
            }
            break;
        case 1: // this would trigger when you hit a key mapped as M(1)
            if (record->event.pressed) {
#ifdef IAV_PWD
                return IAV_PWD;
#else
                return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
#endif
            }
            break;
        case 2: // this would trigger when you hit a key mapped as M(2)
            if (record->event.pressed) {
                return MACRO( I(255), T(H), T(E), T(L), T(L), W(255), T(O), END  );
            }
            break;
    }
    return MACRO_NONE;
};

/** leader key definitions
 */
LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        /** quick access to KeepassXC shortcut */
        SEQ_ONE_KEY(DE_K) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(DE_K);
            unregister_code(DE_K);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }

        SEQ_ONE_KEY(DE_V) {
            SEND_STRING("Viele Gr[-e,\n\tDaniel");
        }

        SEQ_ONE_KEY(DE_M) {
            SEND_STRING("Mit freundlichen Gr[-en,\n\tD. Kriesten");
        }

        /* my personal vimwiki: ,w ,w i v w d LCtl-Tab 1 Ret */
        SEQ_ONE_KEY(DE_W) {
            SEND_STRING(",w,wivwd");
            register_code(KC_LCTL);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            unregister_code(KC_LCTL);
            register_code(DE_1);
            unregister_code(DE_1);
            register_code(KC_ENT);
            unregister_code(KC_ENT);
        }

        /** some often used sentences, Insert ... */
        SEQ_TWO_KEYS(DE_I, DE_V) {
            SEND_STRING("Viele Gr[-e,\n\tDaniel");
        }
        SEQ_TWO_KEYS(DE_I, DE_M) {
            SEND_STRING("Mit freundlichen Gr[-en,\n\tD. Kriesten");
        }
    }
}
/*
 * vim: ts=4:sw=4:sts=4:tw=160:fileformat=unix
 * vim: comments& comments+=b\:* formatoptions& formatoptions+=or
 */

