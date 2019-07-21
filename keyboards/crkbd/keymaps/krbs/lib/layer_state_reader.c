#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _MOUSE 5
#define _ADJUST 16

char layer_state_str[24];

// layer_state = 1U<<_LOWER + 1U<<_RAISE + ...
const char *read_layer_state(void) {
  snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  if (layer_state_is(_QWERTY))
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
  if (layer_state_is(_LOWER))
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
  if (layer_state_is(_RAISE))
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
  if (layer_state_is(_MOUSE))
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
  if (layer_state_is(_ADJUST))
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");

  return layer_state_str;
}
