#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |  Esc |                    |      |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |  \   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc |  GUI |  ALt |       |||||||| Lower| Space|      ||||||||      | Enter| Raise||||||||   [  |   ]  |   `  | Shift|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R, KC_T,  KC_ESC,                      KC_NO,  KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_MINUS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,  KC_F, KC_G,  KC_NO,                       KC_NO,  KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V, KC_B,  KC_NO,                       KC_NO,  KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, \
    KC_ESC,  KC_LGUI, KC_LALT, KC_NO,       LOWER, KC_SPC, KC_NO,        KC_NO, KC_ENT, RAISE, KC_LBRC, KC_RBRC, KC_GRV, KC_RSFT \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   !  |   @  |   #  |   $  |   %  |  Esc |                    |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   1  |   2  |   3  |   4  |   5  |      |                    |      |   -  |   =  |   \  |   `  |   [  |  ]   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|  6   |  7  |    8  |   9  |   0  |      |                    |      |   _  |   +  |  |   |   ~  |  {   |   }  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |  GUI |  ALt |      |||||||| Lower| Space|      ||||||||      | Bksp | Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC, KC_ESC,                      KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_NO,                       KC_NO,   KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_LBRC, KC_RBRC , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_NO,                       KC_NO,   KC_UNDS, KC_PLUS, KC_PIPE, KC_TILD, KC_LCBR, KC_RCBR, \
    KC_ESC,  KC_LGUI, KC_LALT, KC_NO,           LOWER,   KC_SPC, KC_NO,        KC_NO, KC_BSPC, RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |  Tab |   !  |   @  |   #  |   $  |   %  |  Esc |                    |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |  Ctrl|   F1 |   F2 |   F3 |   F4 |   F5 |      |                    |      | Left | Down |  Up  | Right|   :  |  "   |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 |      |                    |      | Home |PageDn|PageUp| End  |   ?  | Shift|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Esc  |  F11 |  F12 |      |||||||| Lower| Space|      ||||||||      | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_ESC,                      KC_NO,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
    KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,                       KC_NO,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQT, \
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_NO,                       KC_NO,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_QUES, KC_RSFT, \
    KC_ESC,  KC_F11 , KC_F12,  KC_NO,             LOWER,  KC_SPC, KC_NO,        KC_NO, KC_ENT, RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
