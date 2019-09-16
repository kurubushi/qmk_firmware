#include QMK_KEYBOARD_H
#include <string.h>

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _MOUSE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
  INIT,
  CUSTOM_KEYCODE_END // END_OF_CUSTOM_KEYCODES
};

bool pressed_memo[CUSTOM_KEYCODE_END - SAFE_RANGE];
bool pressed_memo_is(uint16_t keycode) {
  if (keycode >= SAFE_RANGE || keycode < CUSTOM_KEYCODE_END)
    return pressed_memo[keycode - SAFE_RANGE];
  return false;
}
void pressed_memo_set(uint16_t keycode, bool value) {
  if (keycode >= SAFE_RANGE || keycode < CUSTOM_KEYCODE_END)
    pressed_memo[keycode - SAFE_RANGE] = value;
  return;
}
void pressed_memo_clear(void) {
  memset(&pressed_memo, 0, sizeof(pressed_memo));
  return;
}

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_MOUSE MOUSE
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_INIT INIT

#define LAYOUT_mini( \
    L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16, \
    L20, L21, L22, L23, L24, L25,           R21, R22, R23, R24, R25, R26, \
    L30, L31, L32,      L33, L34, L35, R31, R32, R33,      R34, R35, R36  \
    ) \
    LAYOUT( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05, KC_##L06, KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, KC_##R06, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L16, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, KC_##R16, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_XXXXX, KC_XXXXX, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, KC_##R26, \
        KC_##L30, KC_##L31, KC_##L32, KC_##L33, KC_##L34, KC_##L35, KC_XXXXX, KC_XXXXX, KC_##R31, KC_##R32, KC_##R33, KC_##R34, KC_##R35, KC_##R36  \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_mini( \
  //,------------------------------------------------.         ,------------------------------------------------.
        TAB,     Q,     W,     E,     R,     T, XXXXX,           XXXXX,     Y,     U,     I,     O,     P, MINUS, \
  //|------+------+------+------+------+------+------|         |------+------+------+------+------+------+------|
       LCTL,     A,     S,     D,     F,     G, XXXXX,           XXXXX,     H,     J,     K,     L,  SCLN,  QUOT, \
  //|------+------+------+------+------+------+------'         `------+------+------+------+------+------+------|
       LALT,     Z,     X,     C,     V,     B,                             N,     M,  COMM,   DOT,  SLSH, MOUSE, \
  //|------+------+------+------+------+------+------.         ,------+------+------+------+------+------+------|
      XXXXX, XXXXX, XXXXX,         LGUI,  LSFT,   SPC,             ENT, LOWER, RAISE,        XXXXX, XXXXX, XXXXX \
  //`--------------------'      `--------------------'         `--------------------'      `--------------------'
  ),

  [_LOWER] = LAYOUT_mini( \
  //,------------------------------------------------.         ,------------------------------------------------.
      _____,     1,     2,     3,     4,     5, _____,           _____,     6,     7,     8,     9,     0,  PIPE, \
  //|------+------+------+------+------+------+------|         |------+------+------+------+------+------+------|
      _____,  EXLM,    AT,  HASH,   DLR,  PERC, _____,           _____,  CIRC,  AMPR,  ASTR,  LPRN,  RPRN,  BSPC, \
  //|------+------+------+------+------+------+------'         `------+------+------+------+------+------+------|
      _____,   GRV,  TILD,   EQL,  PLUS, XXXXX,                           ESC,  LCBR,  LBRC,  RBRC,  RCBR,  BSLS, \
  //|------+------+------+------+------+------+------.         ,------+------+------+------+------+------+------|
      _____, _____, _____,        _____, _____, _____,           _____, _____, _____,        _____, _____, _____ \
  //`--------------------'      `--------------------'         `--------------------'      `--------------------'
  ),

  [_RAISE] = LAYOUT_mini( \
  //,------------------------------------------------.         ,------------------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5, _____,           _____,    F6,    F7,    F8,    F9,   F10,  CAPS, \
  //|------+------+------+------+------+------+------|         |------+------+------+------+------+------+------|
      _____,   F11,   F12, XXXXX, XXXXX, XXXXX, _____,           _____,  LEFT,  DOWN,    UP,  RGHT, XXXXX,   DEL, \
  //|------+------+------+------+------+------+------'         `------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                          HOME,  PGDN,  PGUP,   END, XXXXX,  RGUI, \
  //|------+------+------+------+------+------+------.         ,------+------+------+------+------+------+------|
      _____, _____, _____,        _____, _____, _____,           _____, _____, _____,        _____, _____, _____ \
  //`--------------------'      `--------------------'         `--------------------'      `--------------------'
  ),

  [_MOUSE] = LAYOUT_mini( \
  //,------------------------------------------------.         ,------------------------------------------------.
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, _____,           _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------|         |------+------+------+------+------+------+------|
      _____,   F11,   F12, XXXXX, XXXXX, XXXXX, _____,           _____, XXXXX,  WH_U,  MS_U,  WH_D, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------'         `------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                         XXXXX,  MS_L,  MS_D,  MS_R, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------.         ,------+------+------+------+------+------+------|
      _____, _____, _____,        _____, _____, _____,            BTN1,  BTN3,  BTN2,        _____, _____, _____ \
  //`--------------------'      `--------------------'         `--------------------'      `--------------------'
  ),

  [_ADJUST] = LAYOUT_mini( \
  //,------------------------------------------------.         ,------------------------------------------------.
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, _____,           _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------|         |------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  INIT,           _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------'         `------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                         XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------.         ,------+------+------+------+------+------+------|
      _____, _____, _____,        _____, _____, _____,           _____, _____, _____,        _____, _____, _____ \
  //`--------------------'      `--------------------'         `--------------------'      `--------------------'
  )
};

// Setting extra layer
void toggle_layer(void) {
  // QWERTY with
  if (pressed_memo_is(QWERTY)) {
    layer_clear();
    default_layer_set(1UL<<_QWERTY);
    layer_on(_QWERTY);
  }

  // LOWER with
  if (pressed_memo_is(LOWER)) layer_on(_LOWER);
  else layer_off(_LOWER);

  // RAISE with
  if (pressed_memo_is(RAISE)) layer_on(_RAISE);
  else layer_off(_RAISE);

  // MOUSE with
  if (pressed_memo_is(MOUSE)) layer_on(_MOUSE);
  else layer_off(_MOUSE);

  // ADJUST with
  if (pressed_memo_is(ADJUST) || // ADJUST
      (layer_state_is(_LOWER) && layer_state_is(_RAISE))) // LOWER+RAISE
    layer_on(_ADJUST);
  else // turn off ADJUST
    layer_off(_ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case INIT:
      if (record->event.pressed) {
        eeconfig_init(); // reset EEPROM
      }
      return false;
    case QWERTY:
    case LOWER:
    case RAISE:
    case MOUSE:
    case ADJUST:
      pressed_memo_set(keycode, record->event.pressed);
      toggle_layer();
      return false;
  }
  return true;
}
