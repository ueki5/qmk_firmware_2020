/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define BASE  0
#define HHKB1 1
#define HHKB2 2

// Original Key define
#define LCTLA LCTL(KC_A)
#define LCTLC LCTL(KC_C)
#define LCTLS LCTL(KC_S)
#define LCTLV LCTL(KC_V)
#define LCTLX LCTL(KC_X)
#define LCTLZ LCTL(KC_Z)
#define U_TOP LCTL(KC_HOME)
#define U_BTM LCTL(KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer */

    [BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RGUI,
        KC_LALT, LT(HHKB1, JP_MHEN), /*        */ KC_SPC, LT(HHKB2, JP_HENK), KC_RALT),

    /* Layer HHKB1: Left Fn */

    [HHKB1] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, U_TOP,   KC_HOME, KC_UP,   KC_END,  U_BTM,   JP_UNDS, JP_PIPE,  KC_TRNS,
        KC_TRNS, LCTLA,   LCTLS,   KC_LCTL, KC_LSFT, KC_TRNS, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  JP_BSLS, KC_TRNS,
        KC_TRNS, LCTLZ  , LCTLX,   LCTLC,   LCTLV,   KC_TRNS, KC_ESC,  KC_PGDN, KC_PSCR, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENT , KC_TRNS, KC_TRNS),

    /* Layer HHKB2: Right Fn */

    [HHKB2] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCBR, KC_RCBR, KC_MINS, KC_UNDS, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LBRC, KC_RBRC, KC_EQL , KC_PLUS, KC_BSLS, KC_TRNS, KC_RSFT, KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};
