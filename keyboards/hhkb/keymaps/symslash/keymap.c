#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 0

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 150

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 3

#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 5

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0k

#include QMK_KEYBOARD_H

enum layer_names {
	_BASE,
	_EXCITE,
	_CAPS,
	_FIG,
	_SYMS,
	_NUMS,
};

#define KC_CAPSPACE LT(_CAPS, KC_SPACE)
#define KC_FIGCOLON LT(_FIG, KC_SCOLON)
#define KC_SYMSLASH LT(_SYMS, KC_SLASH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` | 15
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   | 14
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   | 13
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   | 13
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LAlt | LGUI | ******* Space ******* | RGUI | RAlt | 5
            |------+------+-----------------------+------+------|
    */
  [_BASE] = LAYOUT( 
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
    KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, TO(_EXCITE),
    KC_LALT, KC_LGUI, /*        */ KC_SPC, KC_RGUI, KC_RALT
  ),

  [_EXCITE] = LAYOUT( 
    // MO(_NUMS), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_ESC,
    KC_TILDE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_BSPC, KC_ESC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LSFT(KC_TAB), KC_TAB,
    LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_FIGCOLON, KC_ENTER, KC_ENTER,
    LT(_NUMS, KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SYMSLASH, KC_RSFT, TO(_BASE),
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_LANG1), KC_RALT
  ),

 [_FIG] = LAYOUT(
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_ESC,
    KC_TAB, KC_Q, KC_MS_UP, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LCTL_T(KC_ESC), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_BTN1, KC_G, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, KC_QUOTE, KC_ENTER,
    RSFT_T(KC_ESC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_ENT, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, RESET,
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_LANG1), KC_RALT
  ),

  [_CAPS] = LAYOUT(
    // KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_GRV, KC_LPRN, KC_RPRN, _______, _______, _______,  _______,_______,
    KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  _______,_______,
    LSFT(KC_TAB), LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), LSFT(_______), LSFT(_______), LSFT(_______),
    LSFT(KC_LCTL), LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), KC_COLON, LSFT(KC_ENTER), LSFT(KC_ENTER),
    LSFT(KC_ESC), LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), KC_COMM, KC_DOT, KC_UNDS, KC_RSFT, _______,
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), _______, LT(_SYMS, KC_LANG1), KC_RALT
  ),

  [_SYMS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_GRV, KC_LPRN, KC_RPRN, _______, _______, _______, _______,
    KC_GRV, KC_QUES, KC_MINS, KC_EQL, KC_ASTERISK, KC_AMPERSAND, KC_PIPE, KC_DQT, KC_LCBR, KC_RCBR, _______, _______, _______,
    _______, RSFT(KC_Z), KC_LABK, KC_RABK, KC_PLUS, LSFT(KC_B), KC_BSLS, KC_QUOTE, KC_LBRC, KC_RBRC, _______, _______, _______, 
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_LANG1), KC_RALT
  ),

  [_NUMS] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    KC_TILDE, KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRCUMFLEX, KC_7, KC_8, KC_9, KC_DOT, _______, _______, _______,
    KC_GRV, KC_QUES, KC_MINS, KC_EQL, KC_ASTERISK, KC_AMPERSAND, KC_PIPE, KC_4, KC_5, KC_6, KC_COMM, _______, _______,
    _______, RSFT(KC_Z), KC_LABK, KC_RABK, KC_PLUS, LSFT(KC_B), KC_0, KC_1, KC_2, KC_3, _______, _______, _______, 
    LALT_T(KC_LANG1), LGUI_T(KC_LANG2), KC_CAPSPACE, LT(_SYMS, KC_LANG1), KC_RALT
  ),
};



