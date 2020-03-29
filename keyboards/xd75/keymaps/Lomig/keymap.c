/* Copyright 2017 Wunder
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
#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

// Layer shorthand
#define _BP 0
#define _FN 1

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BEPO
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | FN     | $      | "      | «      | »      | (      | )      | ESC    | @      | +      | -      | /      | *      | =      | %      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | TAB    | B      | E_ACUT | P      | O      | E_GRAV | DEL    | ^      | V      | D      | L      | J      | Z      | W      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CAP LK | CAP LK | A      | U      | I      | E      | ,      | BK SP  | C      | T      | S      | R      | N      | M      | CEDIL  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | E_CIRC | A_GRAV | Y      | X      | .      | K      | ENTER  | ,      | Q      | G      | H      | F      | UP     | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LALT   | LGUI   | FN UP  | FN DWN | SPACE  | SPACE  | ENTER  | SPACE  | SPACE  | RGUI   | RALT   | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_BP] = LAYOUT_ortho_5x15( /* Bepo */
    MO(_FN), BP_DLR,  BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN, KC_ESC,  BP_AT,   BP_PLUS, BP_MINS, BP_MINS, BP_ASTR, BP_EQL,  BP_PERC,
    KC_TAB,  KC_TAB,  BP_B,    BP_ECUT, BP_P,    BP_O,    BP_EGRV, KC_DEL,  BP_DCRC, BP_V,    BP_D,    BP_L,    BP_J,    BP_Z,    BP_W,
    KC_CAPS, KC_CAPS, BP_A,    BP_U,    BP_I,    BP_E,    BP_COMM, KC_BSPC, BP_C,    BP_T,    BP_S,    BP_R,    BP_N,    BP_M,    BP_CCED,
    KC_LSFT, BP_ECRC, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,    KC_ENT,  BP_APOS, BP_Q,    BP_G,    BP_H,    BP_F,    KC_UP,   KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, TG(_FN), TG(_FN), KC_SPC,  KC_SPC,  KC_ENT,  KC_SPC,  KC_SPC,  KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        | F1     | F2     | F3     | F4     | F5     | ESC    | F6     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | DEL    | 7      | 8      | 9      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        | BK SP  | 4      | 5      | 6      |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT |        |        |        |        |        |        | ENTER  | 1      | 2      | 3      |        |        | UP     | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LALT   | LGUI   | FN UP  | FN DWN | SPACE  | SPACE  | ENTER  | 0      | 0      | .      | ,      | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
    _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_ESC,  KC_F6,      KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______, _______, KC_DEL,  S(BP_PLUS), S(BP_MINS), S(BP_MINS), _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_BSPC, S(BP_LPRN), S(BP_RPRN), S(BP_AT),   _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, KC_ENT,  S(BP_DQOT), S(BP_LGIL), S(BP_RGIL), _______, _______, KC_UP,   KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, TG(_FN), TG(_FN), KC_SPC,  KC_SPC,  KC_ENT,  S(BP_ASTR), S(BP_ASTR), BP_DOT,     BP_COMM, KC_LEFT, KC_DOWN, KC_RIGHT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
