#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  DVORAK,
  PDVORAK,
  ADJUST,
  INIT,
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |DVORAK|                    |  Del |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  Esc |                    |   B  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |  GUI |  Alt ||||||||  GUI | Lower| Space|      ||||||||      | Enter| Raise| Bksp ||||||||      |  ALt | Ctrl |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  DVORAK,                           KC_DEL,  KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_ESC,                           KC_B,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,                          XXXXXXX, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_ESC , KC_LGUI, KC_LALT,          KC_LGUI, LOWER, KC_SPC,  XXXXXXX,        XXXXXXX, KC_ENT,  RAISE, KC_BSPC,          XXXXXXX, KC_RALT, KC_RCTL \
  ),

  /* Dvorak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   '  |   ,  |   .  |   P  |   Y  |DVORAK|                    |  Del |   F  |   G  |   C  |   R  |   L  |  /   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |  Esc |                    |   X  |   D  |   H  |   T  |   N  |   S  |  -   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |      |                    |      |   B  |   M  |   W  |   V  |   Z  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |  GUI |  Alt ||||||||  GUI | Lower| Space|      ||||||||      | Enter| Raise| Bksp ||||||||      |  ALt | Ctrl |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_DVORAK] = LAYOUT( \
    KC_TAB , KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,  DVORAK,                           KC_DEL,  KC_F,  KC_G,    KC_C, KC_R,    KC_L,    KC_SLSH, \
    KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,  KC_ESC,                           KC_X,    KC_D,  KC_H,    KC_T, KC_N,    KC_S,    KC_MINUS, \
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,  XXXXXXX,                          XXXXXXX, KC_B,  KC_M,    KC_W, KC_V,    KC_Z,    KC_RSFT, \
    KC_ESC , KC_LGUI, KC_LALT,          KC_LGUI, LOWER, KC_SPC,  XXXXXXX,        XXXXXXX, KC_ENT,  RAISE, KC_BSPC,       XXXXXXX, KC_RALT, KC_RCTL \
),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   F1 |   F2 |   F3 |   F4 |   F5 |      |                    |      |  F11 |   =  |   `  |   [  |   ]  |   |  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   F6 |   F7 |   F8 |   F9 |  F10 |      |                    |      |  F12 |   +  |  ~   |   {  |   }  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,                          _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                          _______, KC_F11,  KC_EQL,  KC_GRV,  KC_LBRC, KC_RBRC, KC_PIPE, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,                          _______, KC_F12,  KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, _______, \
    _______, _______, _______,          _______, _______, _______, _______,        _______, _______, _______, _______,          _______, _______, _______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Left | Down |  Up  | Right|PageUp| Home |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |PageDn|  End |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,                          _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGUP, KC_HOME, \
    _______, _______, _______, _______, _______, _______, _______,                          _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PGDN, KC_END,  \
    _______, _______, _______,          _______, _______, _______, _______,        _______, _______, _______, _______,          _______, _______, _______ \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|PDVRAK|                   |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | INIT |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,PDVORAK,                    _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,INIT,                          _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};


uint8_t get_default_layer(void) {
  return biton32(default_layer_state);
}

uint8_t get_layer(void) {
  return biton32(layer_state);
}

bool is_dvorak_mode(void) {
  return get_default_layer() == _DVORAK;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case INIT:
      if (record->event.pressed) {
        eeconfig_init(); // reset EEPROM
      }
      return false;
      break;
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
    case DVORAK:
      if (record->event.pressed) {
        if (is_dvorak_mode()) {
          default_layer_set(1UL<<_QWERTY);
        }
        else {
          default_layer_set(1UL<<_DVORAK);
        }
      }
      return false;
      break;
    case PDVORAK: // persistent switching
      if (record->event.pressed) {
        if (is_dvorak_mode()) {
          set_single_persistent_default_layer(_QWERTY);
        }
        else {
          set_single_persistent_default_layer(_DVORAK);
        }
      }
      return false;
      break;
  }
  return true;
}
