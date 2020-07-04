#include "keymap_french.h"

#ifndef ALTGR
#define ALTGR(kc)   RALT(kc)
#endif

#define CU_ALGR KC_RALT
#define CU_ASTR KC_PAST

#define BP_LBRACKET         ALTGR(KC_4)         // [
#define BP_LBRC             BP_LBRACKET
#define BP_RBRACKET         ALTGR(KC_5)         // ]
#define BP_RBRC             BP_RBRACKET

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
/* #define _QWERTY 1 */
/* #define _FN 0 */
#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _FN,
  _FN2
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
  FN2
};

#define _ _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BACK |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  $   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENTER |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  FN  | FN2  | LGUI  | ALT |     SPCE    | AltGr| RGUI |      |      | FN2  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  FR_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
  KC_TAB, FR_A, FR_Z, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, FR_DLR, \
  KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, \
  KC_LCTL, FN, FN2, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, CU_ALGR, KC_RGUI, _, _, FN2\
),

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |   $  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | VOL- | VOL+ | MUTE |BLtogg|      | LEFT | DOWN |  UP  | RGHT |      |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | BL-  | BL+  |Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Mus on|MusOff|      |      |PLY/PS|      | PREV | NEXT |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(\
RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_DEL, \
_, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, FR_DLR, \
_, KC_VOLD, KC_VOLU, KC_MUTE, BL_TOGG, _, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _, CU_ASTR, \
_, _, _, _, _, _, _, _, _, _, _, _, \
_, _, _, _, _, _, _, KC_MPLY, _, KC_MPRV, KC_MNXT, _\
),

/* FN 2
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   %  |   <  |   >  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   %  |   <  |   >  |   &  |   *  |   (  |   )  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             | Next | Vol- | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN2] = LAYOUT_preonic_grid(\
FR_TILD, FR_EXLM, FR_AT, FR_HASH, FR_DLR, FR_PERC, FR_LESS, FR_GRTR, CU_ASTR, FR_LPRN, FR_RPRN, FR_PIPE, \
FR_TILD, FR_EXLM, FR_AT, FR_HASH, FR_DLR, FR_PERC, FR_LESS, FR_GRTR, CU_ASTR, FR_LPRN, FR_RPRN, FR_PIPE, \
_, _, _, _, _, _, _, KC_UNDS, KC_PLUS, FR_LCBR, FR_RCBR, _, \
_, _, _, _, _, _, _, _, _, BP_RBRC, FR_RBRC, _, \
_, _, _, _, _, _, _, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _\
),

};

float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
        /* update_tri_layer(_LOWER, _RAISE, _ADJUST); */
      } else {
        layer_off(_FN);
        /* update_tri_layer(_LOWER, _RAISE, _ADJUST); */
      }
      return false;
      break;

    case FN2:
      if (record->event.pressed) {
        layer_on(_FN2);
        /* update_tri_layer(_LOWER, _RAISE, _ADJUST); */
      } else {
        layer_off(_FN2);
        /* update_tri_layer(_LOWER, _RAISE, _ADJUST); */
      }
      return false;
      break;
  }

  return true;
};

void matrix_init_user(void) {
  startup_user();
}

void startup_user()
{
  _delay_ms(20); // gets rid of tick
  PLAY_SONG(tone_startup);
}

void shutdown_user()
{
  PLAY_SONG(tone_goodbye);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  PLAY_SONG(music_scale);
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  /* switch(id) { */
  /*   case _ULCK: */
  /*     if (record->event.pressed) { */
  /*       /1* time.heals.nothing *1/ */
  /*       return MACRO( I(220), T(T), T(I), T(M), T(E), T(DOT), T(H), T(E), T(A), T(L), T(S), T(DOT), T(N), T(O), T(T), T(H), T(I), T(N), T(G), END); */
  /*     } */
  /*     break; */
  /* } */
  return MACRO_NONE;
};
