/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H

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

    /* BASE Level: Default Layer
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------|
     | Cont  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----|
     | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | RGUI|
     |-------+---+---+---+---+---+---+---+---+---+---+-------+-----|

            |------+------+-----------------------+------+------|
            | LAlt | Fn0  | ******* Space ******* | Fn1  | RAlt |
            |------+------+-----------------------+------+------|
    */

    [BASE] = LAYOUT( //  default layer
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RGUI,
        KC_LALT, MO(HHKB1), /*        */ KC_SPC, MO(HHKB2), KC_RALT),

    /* Layer HHKB1: Left Fn
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | Top| Hom| Up  | End | Btom|     | Ins   |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------|
      |      |Ctl-A|Ctl-S|LCtrl|LShf|    | BS | Lef| Dow | Rig | Del | Esc |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------|
      |      |Ctl-Z|Ctl-X|Ctl-C|CtlV|    |PgDn|PSCR| SCLK|     | PgU |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******* Enter ****** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [HHKB1] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, U_TOP,   KC_HOME, KC_UP,   KC_END,  U_BTM,   KC_TRNS, KC_INS,  KC_TRNS,
        KC_TRNS, LCTLA,   LCTLS,   KC_LCTL, KC_LSFT, KC_TRNS, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_ESC,  KC_TRNS,
        KC_TRNS, LCTLZ  , LCTLX,   LCTLC,   LCTLV,   KC_TRNS, KC_PGDN, KC_PSCR, KC_SLCK, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENT , KC_TRNS, KC_TRNS),

    /* Layer HHKB2: Right Fn
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |WH_U |BTN1 |MS_U |BTN2| Esc|    |    |     |     |     |     |       |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------|
      |      |WH_L |MS_L |MS_D |MS_R|WH_R|BSLS|RShf|RCtrl|     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------|
      |      | BSLS| EQL |MINS |PPLS|WH_D|PPLS|MINS|EQL  |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******* Enter ****** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [HHKB2] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_BSLS, KC_RSFT, KC_RCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_BSLS, KC_EQL,  KC_MINS, KC_PPLS, KC_WH_D, KC_PPLS, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENT , KC_TRNS, KC_TRNS)};

