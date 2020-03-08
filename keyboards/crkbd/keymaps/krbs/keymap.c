#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 3
#define _RAISE 4
#define _MOUSE 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
  CUSTOM_KEYCODE_END, // END_OF_CUSTOM_KEYCODES
  KC_KEY1,
  KC_KEY2,
  KC_KEY3,
  KC_KEY4,
  KC_KEY5,
  KC_KEY6,
  KC_KEY7,
  KC_SWT0,
  KC_SWT1
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
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
#define KC_QWERTY QWERTY
#define KC_CLMAK COLEMAK
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_MOUSE MOUSE

uint16_t thumblist_index = 0;
const uint16_t thumblist[][7] =
  {
   {KC_LGUI, KC_LALT, KC_LSFT, KC_SPC, RAISE, LOWER, MOUSE},
   {KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_LSFT, RAISE, KC_ESC}
  };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P, MINUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     A,     S,     D,     F,     G,                      H,     J,     K,     L,  SCLN,   ENT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       KEY1,     Z,     X,     C,     V,     B,                      N,     M,  COMM,   DOT,  SLSH,  LALT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                   KEY2,  KEY3,  KEY4,     KEY5,  KEY6,  KEY7 \
                              //`--------------------'  `--------------------'
  ),

  // Modified Colemak by kurubushi
  [_COLEMAK] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
        TAB,     Q,     W,     F,     P,     G,                      K,     L,     U,     Y,  QUOT, MINUS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LCTL,     A,     R,     S,     T,     D,                      H,     N,     E,     I,     O,  SCLN,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,                      J,     M,  COMM,   DOT,  SLSH, MOUSE,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,     1,     2,     3,     4,     5,                      6,     7,     8,     9,     0,  PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,  EXLM,    AT,  HASH,   DLR,  PERC,                   CIRC,  AMPR,  ASTR,  LPRN,  RPRN,   EQL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,   GRV,  QUOT,  DQUO,  TILD,  PLUS,                   PLUS,  LCBR,  LBRC,  RBRC,  RCBR,  BSLS,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____,    F1,    F2,    F3,    F4,   F5,                      F6,    F7,    F8,    F9,   F10,   DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____,   F11,   F12, XXXXX, XXXXX, XXXXX,                   LEFT,  DOWN,    UP,  RGHT,   ESC,  BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                   HOME,  PGDN,  PGDN,   END,  CAPS,  RGUI,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_MOUSE] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      _____, XXXXX, XXXXX,  MS_U, XXXXX, XXXXX,                  XXXXX, XXXXX,  WH_U, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX,  MS_L,  MS_D,  MS_R, XXXXX,                  XXXXX,  BTN1,  BTN3,  BTN2, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX,  WH_D, XXXXX, XXXXX, XXXXX, \
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  _____, _____, _____,    _____, _____, _____ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT_kc( \
  //,-----------------------------------------.                ,-----------------------------------------.
      XXXXX,QWERTY, CLMAK, XXXXX, XXXXX, XXXXX,                   SWT0,  SWT1, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
      XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,                  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                  XXXXX, XXXXX, XXXXX,    XXXXX, XXXXX, XXXXX \
                              //`--------------------'  `--------------------'
  )
};

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

// Setting extra layer
void toggle_layer(void) {
  // QWERTY with
  if (pressed_memo_is(QWERTY)) {
    layer_clear();
    default_layer_set(1UL<<_QWERTY);
    layer_on(_QWERTY);
  }

  // Colemak with
  if (pressed_memo_is(COLEMAK)) {
    layer_clear();
    default_layer_set(1UL<<_COLEMAK);
    layer_on(_COLEMAK);
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
    case KC_KEY1:
    case KC_KEY2:
    case KC_KEY3:
    case KC_KEY4:
    case KC_KEY5:
    case KC_KEY6:
    case KC_KEY7:
      keycode = thumblist[thumblist_index][keycode - KC_KEY1];
      // return process_record_user(keycode, record); // doesn't send keycode
      if (keycode < SAFE_RANGE) {
        if (record->event.pressed)
          register_code(keycode);
        else
          unregister_code(keycode);
      }
  }

  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
  }
  
  switch (keycode) {
    case QWERTY:
    case COLEMAK:
    case LOWER:
    case RAISE:
    case MOUSE:
    case ADJUST:
      pressed_memo_set(keycode, record->event.pressed);
      toggle_layer();
      return false;
    case KC_SWT0:
    case KC_SWT1:
      pressed_memo_clear();
      thumblist_index = keycode - KC_SWT0;
      return false;
  }
  return true;
}

