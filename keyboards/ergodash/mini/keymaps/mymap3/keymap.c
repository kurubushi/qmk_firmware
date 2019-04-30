#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _DVORAK 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  pQWERTY,
  DVORAK,
  pDVORAK,
  COLEMAK,
  pCOLEMAK,
  LOWER,
  RAISE,
  ADJUST,
  INIT,
};

#define EISU LALT(KC_GRV)
#define SANDS SFT_T(KC_SPC)
#define ZENHAN KC_LANG6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   oyayubi: prototype
   * |  Esc |  GUI |  Alt |||||||| Shift| Lower| Space|      ||||||||      | Enter| Raise| Bksp ||||||||  Alt | Ctrl | EISU |
   KC_ESC ,KC_LGUI,KC_LALT,     KC_LSFT,LOWER  ,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,RAISE  ,KC_BSPC,        KC_RALT,KC_RCTL,EISU      \

   oyayubi: outside-lo/ra
   * |  Esc |  GUI |  Alt |||||||| Lower| Shift| Space|      ||||||||      | Enter| Bksp | Raise||||||||  Alt | Ctrl | EISU |
   KC_ESC ,KC_LGUI,KC_LALT,     LOWER  ,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,KC_BSPC,RAISE  ,        KC_RALT,KC_RCTL,EISU      \

   oyayubi: ra/sh~lo
   * |  Esc |  GUI |  Alt |||||||| Raise| Shift| Space|      ||||||||      | Enter| Lower| Bksp ||||||||  Alt | Ctrl | EISU |
   KC_ESC ,KC_LGUI,KC_LALT,     RAISE  ,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,LOWER  ,KC_BSPC,        KC_RALT,KC_RCTL,EISU      \

   oyayubi: sh-lo/ra
   * |  Esc |  GUI |  Alt |||||||| Bksp | Shift| Space|      ||||||||      | Enter| Lower| Raise||||||||  Alt | Ctrl | EISU |
   KC_ESC ,KC_LGUI,KC_LALT,     KC_BSPC,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,LOWER  ,RAISE  ,        KC_RALT,KC_RCTL,EISU      \
   */

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |DVORAK|                    |  Del |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  Esc |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  GUI |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  |  Alt |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  Esc |  GUI |  Alt |||||||| Bksp | Shift| Space|      ||||||||      | Enter| Lower| Raise||||||||  Alt | Ctrl | EISU |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB ,KC_Q   ,KC_W   ,KC_E,KC_R   ,KC_T   ,DVORAK ,                  KC_DEL ,KC_Y   ,KC_U   ,KC_I,   KC_O   ,KC_P   ,KC_MINUS, \
    KC_LCTL,KC_A   ,KC_S   ,KC_D,KC_F   ,KC_G   ,KC_ESC ,                  KC_BSPC,KC_H   ,KC_J   ,KC_K,   KC_L   ,KC_SCLN,KC_QUOT , \
    KC_LSFT,KC_Z   ,KC_X   ,KC_C,KC_V   ,KC_B   ,XXXXXXX,                  XXXXXXX,KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RALT,  \
    KC_ESC ,KC_LGUI,KC_LALT,     KC_BSPC,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,LOWER  ,RAISE  ,        KC_RALT,KC_RCTL,EISU      \
  ), 

  /* Dvorak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   '  |   ,  |   .  |   P  |   Y  |DVORAK|                    |  Del |   F  |   G  |   C  |   R  |   L  |  /   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |  Esc |                    | Bksp |   D  |   H  |   T  |   N  |   S  |  -   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  GUI |   ;  |   Q  |   J  |   K  |   X  |      |                    |      |   B  |   M  |   W  |   V  |   Z  |  Alt |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  Esc |  GUI |  Alt |||||||| Bksp | Shift| Space|      ||||||||      | Enter| Lower| Raise||||||||  Alt | Ctrl | EISU |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_DVORAK] = LAYOUT( \
    KC_TAB ,KC_QUOT,KC_COMM,KC_DOT,KC_P   ,KC_Y ,DVORAK ,                  KC_DEL ,KC_F ,KC_G   ,KC_C,KC_R   ,KC_L   ,KC_SLSH , \
    KC_LCTL,KC_A   ,KC_O   ,KC_E  ,KC_U   ,KC_I ,KC_ESC ,                  KC_BSPC,KC_D ,KC_H   ,KC_T,KC_N   ,KC_S   ,KC_MINUS, \
    KC_LGUI,KC_SCLN,KC_Q   ,KC_J  ,KC_K   ,KC_X ,XXXXXXX,                  XXXXXXX,KC_B ,KC_M   ,KC_W,KC_V   ,KC_Z   ,KC_RALT , \
    KC_ESC ,KC_LGUI,KC_LALT,     KC_BSPC,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,LOWER  ,RAISE  ,        KC_RALT,KC_RCTL,EISU      \
),

  /* Colemak
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Tab |   Q  |   W  |   F  |   P  |   G  |DVORAK|                    |  Del |   J  |   L  |   U  |   Y  |   ;  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |  Esc |                    | Bksp |   H  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |  GUI |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   K  |   M  |   ,  |   .  |   /  |  Alt |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     |  Esc |  GUI |  Alt |||||||| Bksp | Shift| Space|      ||||||||      | Enter| Lower| Raise||||||||  Alt | Ctrl | EISU |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_COLEMAK] = LAYOUT( \
    KC_TAB ,KC_Q   ,KC_W   ,KC_F,KC_P   ,KC_G   ,DVORAK ,                  KC_DEL ,KC_J   ,KC_L   ,KC_U,   KC_Y   ,KC_SCLN,KC_MINUS, \
    KC_LCTL,KC_A   ,KC_R   ,KC_S,KC_T   ,KC_D   ,KC_ESC ,                  KC_BSPC,KC_H   ,KC_N   ,KC_E,   KC_I   ,KC_O   ,KC_QUOT , \
    KC_LGUI,KC_Z   ,KC_X   ,KC_C,KC_V   ,KC_B   ,XXXXXXX,                  XXXXXXX,KC_K   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RALT,  \
    KC_ESC ,KC_LGUI,KC_LALT,     KC_BSPC,KC_LSFT,KC_SPC ,XXXXXXX,  XXXXXXX,KC_ENT ,LOWER  ,RAISE  ,        KC_RALT,KC_RCTL,EISU      \
  ), 

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |   !  |   @  |   #  |   $  |   %  |      |                    |      |   ^  |   &  |   *  |   (  |   )  |   \  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |   |  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   `  |   ~  |   =  |   +  |  Del |      |                    |      |  Ecs |   [  |  ]   |   {  |   }  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |      |      ||||||||      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______,KC_EXLM,KC_AT  ,KC_HASH,KC_DLR ,KC_PERC,_______,                    _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSLS, \
    _______,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,_______,                    _______,KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_PIPE, \
    _______,KC_GRV ,KC_TILD,KC_EQL ,KC_PLUS,KC_DEL ,_______,                    _______,KC_ESC ,KC_LBRC,KC_RBRC,KC_LCBR,KC_RCBR,_______, \
    _______,_______,_______,        _______,_______,_______,_______,    _______,_______,_______,_______,        _______,_______,_______ \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F11 |  F12 |      |ZenHan|      |      |                    |      | Left | Down |  Up  | Right|  Ins |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Home |PageDn|PageUp|  End |  Del |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      ||||||||      |      |      |      ||||||||      |      |      |      ||||||||      |      |     |
   * ,---------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4   ,KC_F5  ,_______,                     _______,KC_F6,  KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,_______, \
    _______,KC_F11 ,KC_F12 ,_______,ZENHAN  ,_______,_______,                     _______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_PGUP,KC_INS , \
    _______,_______,_______,_______,_______ ,_______,_______,                     _______,KC_HOME,KC_PGDN,KC_PGDN,KC_END ,KC_PGDN,KC_DEL , \
    _______,_______,_______,        _______ ,_______,_______,_______,    _______, _______,_______, _______,       _______,_______,_______  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | S(A) | LOCK |      |      |      | INIT |                    |      | DV.  | Qw.  | CM.  |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | pDV. | pQw. | pCM. |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______,RESET  ,RGB_TOG,RGB_MOD,RGB_HUD,RGB_HUI,pDVORAK,                    _______,RGB_SAD,RGB_SAI ,RGB_VAD,RGB_VAI,_______,_______, \
    _______,S(KC_A),KC_LOCK,BL_BRTG,BL_INC ,BL_DEC ,INIT,                       _______,DVORAK ,QWERTY  ,COLEMAK ,_______,_______,_______, \
    _______,_______,_______,_______,_______,_______,_______,                    _______,pDVORAK,pQWERTY ,pCOLEMAK,_______,_______,_______, \
    _______,_______,_______,_______,        _______,_______,_______,    _______,_______,_______,        _______,_______,_______,_______  \
  )
};


bool default_layer_state_is(uint8_t layer) {
  return biton32(default_layer_state) == layer;
}

bool is_dvorak_mode(void) {
  return default_layer_state_is(_DVORAK);
}

bool is_pressed_shift = false;

void auto_switch_layer(void) {
  // turn on ADJUST with
  if ((is_pressed_shift && layer_state_is(_LOWER)) || // Shift+LOWER or
      (layer_state_is(_LOWER) && layer_state_is(_ADJUST))) //LOWER+RAISE
    layer_on(_ADJUST);
  else // turn off ADJUST
    layer_off(_ADJUST);

  return;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case INIT:
    if (record->event.pressed) {
      eeconfig_init(); // reset EEPROM
    }
    return false;
  case LOWER:
    if (record->event.pressed) layer_on(_LOWER);
    else layer_off(_LOWER);
    auto_switch_layer();
    return false;
  case RAISE:
    if (record->event.pressed) layer_on(_RAISE);
    else layer_off(_RAISE);
    auto_switch_layer();
    return false;
  case ADJUST:
    if (record->event.pressed) layer_on(_ADJUST);
    else layer_off(_ADJUST);
    auto_switch_layer();
      return false;
  case QWERTY: // turn to QWERTY
    if (record->event.pressed)
      default_layer_set(1UL<<_QWERTY);
    return false;
  case pQWERTY: // turn to QWERTY, persistently
    if (record->event.pressed)
      set_single_persistent_default_layer(_QWERTY);
    return false;
  case DVORAK: // turn to Dvorak
    if (record->event.pressed)
      default_layer_set(1UL<<_DVORAK);
    return false;
  case pDVORAK: // turn to Dvorak, persistently
    if (record->event.pressed)
      set_single_persistent_default_layer(_DVORAK);
    return false;
  case COLEMAK: // turn to COLEMAK
    if (record->event.pressed)
      default_layer_set(1UL<<_COLEMAK);
    return false;
  case pCOLEMAK: // turn to COLEMAK, persistently
    if (record->event.pressed)
      set_single_persistent_default_layer(_COLEMAK);
    return false;
  case KC_LSFT:
    if (record->event.pressed) is_pressed_shift = true;
    else is_pressed_shift = false;
    auto_switch_layer();
    return true;
  }
  return true;
}
