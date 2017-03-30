#include "preonic.h"
#include "action_layer.h"
#include "print.h"
#include "eeconfig.h"
#ifdef AUDIO_ENABLE
#include "audio.h"
#endif

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

enum preonic_layers {
  _QWERTY = 1,
  _FN,
  _FN2
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  FN,
  FN2
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Azerty
   * ,-----------------------------------------------------------------------------------.
   * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BACK |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  ^   |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | ESC  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   W  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ENTER |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  FN  | Ctrl | FN2  | ALT  | LGUI |     SPCE    | AltGr| RGUI |      |      | FN2  |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = {
    {FR_EQL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
    {KC_TAB,  FR_A,    FR_Z,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    FR_CIRC },
    {KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
    {FN, KC_LCTL, FN2,  KC_LALT,KC_LGUI, KC_SPC, KC_SPC, CU_ALGR,  KC_RGUI, _______, _______, FN2 }
  },

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
  [_FN] = {
    {RESET, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL },
    {_______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  FR_DLR },
    {_______, KC_VOLD, KC_VOLU, KC_MUTE, BL_TOGG, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, CU_ASTR },
    {_______, BL_DEC,  BL_INC,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______ },
    {_______,  _______,  _______,  MU_ON,   MU_OFF,  _______, _______, KC_MPLY, _______, KC_MPRV, KC_MNXT, _______ }
  },

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
  [_FN2] = {
    {FR_TILD, FR_EXLM, FR_AT,   FR_HASH, FR_DLR,  FR_PERC, FR_LESS, FR_GRTR, CU_ASTR, FR_LPRN, FR_RPRN, FR_PIPE},
    {FR_TILD, FR_EXLM, FR_AT,   FR_HASH, FR_DLR,  FR_PERC, FR_LESS, FR_GRTR, CU_ASTR, FR_LPRN, FR_RPRN, FR_PIPE},
    {_______,  _______,   _______,   _______,   _______,   _______,  _______,  KC_UNDS, KC_PLUS, FR_LCBR, FR_RCBR, _______},
    {_______, _______,   _______,   _______,   _______,  _______,  _______, _______, _______, BP_RBRC, FR_RBRC, _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______}
  },

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
  print_val_dec(keycode);
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
  PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
  PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
  _delay_ms(150);
  stop_all_notes();
}

void music_on_user(void)
{
  music_scale_user();
}

void music_scale_user(void)
{
  PLAY_NOTE_ARRAY(music_scale, false, 0);
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
