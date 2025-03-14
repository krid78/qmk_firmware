/*
 * Code taken from https://github.com/jichuntao/tmk_keyboard
 * but adapted to match qmk_firmware needs by
 * Daniel Kriesten <daniel@die-kriestens.de>
 * <Mo 28 Mär 2016 18:08:31 krid>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    NPKC
#define PRODUCT         KC60
#define DESCRIPTION     QMK keyboard firmware for NPKC KC60

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/* COLS: Left to right, ROWS: Top to bottom
 * Taken from: https://github.com/yangliu/qmk_firmware
 */
#define COLS (int []){ F0, F1, E6, C7, C6, B7, D4, B1, B0, B5, B4, D7, D6, B3 }
#define ROWS (int []){ D0, D1, F6, F7, D5 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
