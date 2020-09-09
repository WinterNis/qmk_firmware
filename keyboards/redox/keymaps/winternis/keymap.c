#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

extern keymap_config_t keymap_config;
//extern rgblight_config_t rgblight_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BEPO 0
#define _QWERTY 1
#define _SYMB 2
#define _NAV 3

enum custom_keycodes {
  BEPO = SAFE_RANGE,
  QWERTY,
  SYMB,
  NAV,
};

// Shortcut to make keymap more readable
#define KC_BKSL KC_BSLASH
#define SYM_L   MO(_SYMB)

#define LT_NAV  LT(_NAV, KC_SPC)

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BEPO
 * ,------------------------------------------------.            ,------------------------------------------------.
 * |  $   |   "  |   «  |   »  |   (  |   )  | ESC  |            |   %  |   @  |   +  |   -  |   /  |   *  |  =   |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Tab  |   B  |   É  |   P  |   O  |   è  |  _   |            |   W  |   !  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Shift|   A  |   U  |   I  |   E  |   ;  | PgDw |            | End  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Shift|   À  |   Y  |   X  |   .  |   K  | PgUp |            | Home |   ?  |   Q  |   G  |   H  |   F  |  c   |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * |H_SYMB | Ctrl | Alt  | Cmd | Cmd  |Bcksp | Del  |            |Enter |Space | H_NAV| AtlGr|      |      |      |
 * `------------------------------------------------'            `------------------------------------------------'
 */
  [_BEPO] = LAYOUT(
     BP_DLR,    BP_DQOT,  BP_LGIL, BP_RGIL, BP_LPRN,  BP_RPRN,                       /**/                      BP_AT,   BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL,
     KC_TAB,    BP_B,     BP_ECUT, BP_P ,   BP_O,     BP_EGRV, KC_ESC,               /**/            BP_PERC,  BP_DCRC, BP_V,   BP_D,    BP_L,    BP_J,    BP_Z,
     KC_LSFT,   BP_A,     BP_U,    BP_I,    BP_E,     BP_COMM, KC_SPC,               /**/            BP_W,     BP_C,    BP_T,   BP_S,    BP_R,    BP_N,    BP_M,
     KC_LSFT,   BP_AGRV,  BP_Y,    BP_X ,   BP_DOT,   BP_K,    KC_DEL,   KC_ENT,     /**/   KC_UNDO, KC_AGIN,  BP_APOS, BP_Q,   BP_G,    BP_H ,   BP_F,    BP_CCED,
     MO(_SYMB), KC_LCTRL, KC_LALT, KC_SPC,      KC_LGUI,       KC_BSPC,  LT_NAV,   /**/   KC_ENT,  KC_SPC,      KC_RALT,      XXXXXXX, XXXXXXX, CG_TOGG,   DF(_QWERTY)
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_ESC  ,                          KC_EQL  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_LBRC  ,                         KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_DEL   ,KC_ENT,         KC_UNDO ,KC_AGIN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_BKSL ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
    KC_LCTRL ,KC_LCTRL,KC_LALT ,KC_SPC  ,     KC_LGUI ,    KC_BSPC ,LT_NAV,         KC_ENT  ,KC_SPC  ,    KC_RALT ,     XXXXXXX  ,XXXXXXX ,XXXXXXX ,DF(_BEPO)
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

/* Symbols
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  VUP |      |      |      |      |      |      |      |      |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  VDW |      |      |      |      |      |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      | CUT  | COPY |PASTE |      |      |      |      |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   0  |   0  |   .  |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */

  [_SYMB] = LAYOUT(
    XXXXXXX, KC_F1,      KC_F2,      KC_F3,      KC_F4,   KC_F5,                                              XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_VOLU, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, _______,                          XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX,
    KC_VOLD, LCTL(BP_X), LCTL(BP_C), LCTL(BP_V),    XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX,
    _______, LCTL(BP_X), LCTL(BP_C), LCTL(BP_V), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        _______, _______, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX,
    _______, XXXXXXX,    XXXXXXX,    XXXXXXX,         XXXXXXX,     _______, _______,        _______, _______,      KC_KP_0,     KC_KP_0, KC_PDOT, XXXXXXX, XXXXXXX
  ),

/* Navigation
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | PgUp | Home |  UP  | End  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | PgDw | LEFT | DOWN | RIGHT|      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                     _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                     _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,  _______, _______,
    XXXXXXX, _______, _______, _______,      _______,     _______, _______,                   _______, KC_LALT,      _______,     _______, _______,  _______, _______
  ),

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif
