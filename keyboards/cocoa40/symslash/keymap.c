/* Copyright 2019 'Naoto Takai'
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

enum layer_names {
	_BASE,
	_EXCITE,
	_CAPS,
	_NUMS,
	_SYMS,
	_FIG,
};

#define KC_CAPSPACE LT(_CAPS, KC_SPACE)
#define KC_FIGCOLON LT(_FIG, KC_SCOLON)
#define KC_SYMSLASH LT(_SYMS, KC_SLASH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_RBRACKET, KC_BSPACE,
    KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_ENTER,
    KC_LSHIFT,KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, TO(_EXCITE),
    KC_LALT,  KC_LGUI, KC_SPACE, KC_SPACE, KC_RGUI, KC_RALT
  ),

  [_EXCITE] = LAYOUT( 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LSFT(KC_TAB), KC_TAB,
    LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_FIGCOLON, KC_ENTER, KC_ENTER,
    LT(_NUMS, KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SYMSLASH, KC_RSFT, TO(_BASE),
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_SPACE), LT(_NUMS, KC_LANG1), KC_RALT
  ),

  [_CAPS] = LAYOUT(
    LSFT(KC_TAB), LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), LSFT(_______), LSFT(_______), LSFT(_______),
    LSFT(KC_LCTL), LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), KC_COLON, LSFT(KC_ENTER), LSFT(KC_ENTER),
    LSFT(KC_ESC), LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), KC_COMM, KC_DOT, KC_UNDS, KC_RSFT, _______,
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), _______, LT(_SYMS, KC_SPACE), LT(_NUMS, KC_LANG1), KC_RALT
  ),

  [_SYMS] = LAYOUT(
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_GRV, KC_LPRN, KC_RPRN, _______, _______, _______, _______,
    KC_GRV, KC_QUES, KC_MINS, KC_EQL, KC_ASTERISK, KC_AMPERSAND, KC_PIPE, KC_DQT, KC_LCBR, KC_RCBR, KC_COLON, _______, _______,
    _______, RSFT(KC_Z), KC_LABK, KC_RABK, KC_PLUS, LSFT(KC_B), KC_BSLS, KC_QUOTE, KC_LBRC, KC_RBRC, KC_UNDS, _______, _______, 
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_SPACE), LT(_NUMS, KC_LANG1), KC_RALT
  ),

  [_NUMS] = LAYOUT(
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_7, KC_8, KC_9, KC_DOT, _______, _______, _______,
    KC_GRV, KC_QUES, KC_MINS, KC_EQL, KC_ASTERISK, KC_AMPERSAND, KC_PIPE, KC_4, KC_5, KC_6, KC_COMM, _______, _______,
    _______, RSFT(KC_Z), KC_LABK, KC_RABK, KC_PLUS, LSFT(KC_B), KC_0, KC_1, KC_2, KC_3, _______, _______, _______, 
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_SPACE), LT(_NUMS, KC_LANG1), KC_RALT
  ),

 [_FIG] = LAYOUT(
    KC_TAB, KC_Q, KC_MS_UP, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN1, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, KC_QUOTE, KC_ENTER,
    RSFT_T(KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_ENT, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, RESET,
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_SPACE), LT(_NUMS, KC_LANG1), KC_RALT
  ),
};
