/* Copyright 2019 kakunpc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Original Key define

enum layers{
    BASE = 0,
    LOWER,
    UPPER
};
// key Combo definition
enum combos {
  COMBO_01,
  COMBO_02,
  COMBO_03,
  COMBO_04,
  COMBO_05,
  COMBO_06,
  COMBO_07,
  COMBO_08,
  COMBO_09,
  COMBO_10,
  COMBO_11,
  COMBO_12,
  COMBO_13,
  COMBO_14
};
// @   ^&*()_+|~
const uint16_t PROGMEM combo_01[] = {KC_RSFT, KC_2   , COMBO_END};
const uint16_t PROGMEM combo_02[] = {KC_LSFT, KC_6   , COMBO_END};
const uint16_t PROGMEM combo_03[] = {KC_LSFT, KC_7   , COMBO_END};
const uint16_t PROGMEM combo_04[] = {KC_LSFT, KC_8   , COMBO_END};
const uint16_t PROGMEM combo_05[] = {KC_LSFT, KC_9   , COMBO_END};
const uint16_t PROGMEM combo_06[] = {KC_LSFT, KC_0   , COMBO_END};
const uint16_t PROGMEM combo_07[] = {KC_LSFT, KC_MINS, COMBO_END};
const uint16_t PROGMEM combo_08[] = {KC_LSFT, JP_EQL , COMBO_END};
const uint16_t PROGMEM combo_09[] = {KC_LSFT, KC_JYEN, COMBO_END};
const uint16_t PROGMEM combo_10[] = {KC_LSFT, JP_GRV , COMBO_END};
// {}
const uint16_t PROGMEM combo_11[] = {KC_LSFT, JP_LBRC, COMBO_END};
const uint16_t PROGMEM combo_12[] = {KC_LSFT, JP_RBRC, COMBO_END};
// :"
const uint16_t PROGMEM combo_13[] = {KC_LSFT, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_14[] = {KC_LSFT, JP_QUOT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // @   ^&*()_+|~
  [COMBO_01] = COMBO(combo_01, JP_AT),
  [COMBO_02] = COMBO(combo_02, JP_CIRC),
  [COMBO_03] = COMBO(combo_03, JP_AMPR),
  [COMBO_04] = COMBO(combo_04, JP_ASTR),
  [COMBO_05] = COMBO(combo_05, JP_LPRN),
  [COMBO_06] = COMBO(combo_06, JP_RPRN),
  [COMBO_07] = COMBO(combo_07, JP_UNDS),
  [COMBO_08] = COMBO(combo_08, JP_PLUS),
  [COMBO_09] = COMBO(combo_09, JP_PIPE),
  [COMBO_10] = COMBO(combo_10, JP_TILD),
  // {}
  [COMBO_11] = COMBO(combo_11, JP_LCBR),
  [COMBO_12] = COMBO(combo_12, JP_RCBR),
  // :"
  [COMBO_13] = COMBO(combo_13, JP_COLN),
  [COMBO_14] = COMBO(combo_14, JP_DQUO)
};
void process_combo_event(uint8_t combo_index, bool pressed) {
// dprintf("process_combo_event combo_index=%u,pressed=%u\n", combo_index, pressed);
  switch(combo_index) {
      break;
  }
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// dprintf("process_record_user keycode=%u, record->event.pressed=%u\n", keycode, record->event.pressed);
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_all(
        KC_ESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,
        KC_TAB, KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        KC_LCTL,KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
        KC_LSFT,KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_PGDOWN,
        KC_NO,  KC_LGUI, KC_LALT, LT(LOWER, KC_F13),   KC_SPC,    LT(UPPER, KC_F14),  KC_LALT, KC_LCTL, KC_NO,  KC_LEFT, KC_DOWN, KC_RIGHT),
    [LOWER] = LAYOUT_all(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   KC_PGDOWN,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  LCTL(KC_A),  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_TRNS,  KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,   KC_INS,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LCTL(KC_V),  KC_TRNS,  KC_ESC,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_TRNS,  KC_CAPS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),
    [UPPER] = LAYOUT_all(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
  // Host Keyboard LED Status
  oled_write_P(IS_HOST_LED_ON(USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(IS_HOST_LED_ON(USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(IS_HOST_LED_ON(USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}
#endif
