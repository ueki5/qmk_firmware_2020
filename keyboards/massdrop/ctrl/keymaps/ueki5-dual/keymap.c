#include QMK_KEYBOARD_H
#include "keymap_jp.h"

enum ctrl_layouts {
    _JP = 0, //JP Layout
    _JL,     //JP Lower
    _JR,     //JP Raise
    _US,     //US Layout
    _UL,     //JP Lower
    _GN,     //General
};

enum ctrl_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    SW_PC1,                //Switch to PC1
    SW_PC2,                //Switch to PC2
    SW_PC3,                //Switch to PC3
    SW_PC4,                //Switch to PC4
};

keymap_config_t keymap_config;

// Original Key define
#define LCTLA LCTL(KC_A)
#define LCTLC LCTL(KC_C)
#define LCTLS LCTL(KC_S)
#define LCTLV LCTL(KC_V)
#define LCTLX LCTL(KC_X)
#define LCTLZ LCTL(KC_Z)
#define U_TOP LCTL(KC_HOME)
#define U_BTM LCTL(KC_END)

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
const uint16_t PROGMEM combo_01[] = {KC_LSFT, KC_2   , COMBO_END};
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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_JP] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        JP_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, JP_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_LBRC, JP_RBRC, KC_JYEN,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,                              KC_UP, \
        MO(_GN), KC_LALT, LT(_JL, JP_MHEN), KC_SPC,                  LT(_JL, JP_HENK),   KC_LALT, KC_LGUI, KC_LCTL,          KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_JL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   U_TOP, KC_HOME,   KC_UP,  KC_END,   U_BTM, JP_UNDS, JP_PIPE, _______,   _______, _______, _______, \
        _______,   LCTLA,   LCTLS, KC_LCTL, KC_LSFT, DF(_US), KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, JP_BSLS, _______, \
        _______,   LCTLZ,   LCTLX,   LCTLC,   LCTLV, _______,  KC_ESC, KC_PGDN, KC_PSCR, KC_PGUP, _______, _______,                              _______, \
        _______, _______, _______,                    KC_ENT,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [_JR] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,   _______, _______, _______, \
        _______, JP_LBRC, JP_RBRC, JP_MINS, JP_UNDS, JP_GRV,  _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, JP_LCBR, JP_RCBR, JP_EQL,  JP_PLUS, JP_TILD, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, JP_QUOT, JP_DQUO, _______, _______, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [_US] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        MO(_GN), KC_LALT, MO(_UL), KC_SPC,                             MO(_UL), KC_LALT, KC_LGUI, KC_LCTL,                   KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [_UL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______,   U_TOP, KC_HOME,   KC_UP,  KC_END,   U_BTM, _______, _______, _______,   _______, _______, _______, \
        _______,   LCTLA,   LCTLS, KC_LCTL, KC_LSFT, DF(_JP), KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______, _______, \
        _______,   LCTLZ,   LCTLX,   LCTLC,   LCTLV, _______, KC_ESC,  KC_PGDN, KC_PSCR, KC_PGUP, _______, _______,                              _______, \
        _______, _______, _______,                    KC_ENT,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [_GN] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______,U_T_AUTO,U_T_AGCR, _______, _______, _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______,  SW_PC1,  SW_PC2,  SW_PC3,  SW_PC4, _______, _______, \
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   JP_ZKHK,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_MASK_SHIFT)
#define MODS_CTRL   (get_mods() & MOD_MASK_CTRL)
#define MODS_ALT    (get_mods() & MOD_MASK_ALT)

void sw_to_pc(uint8_t keycode,  uint8_t layer) {
    if (layer == _JP) {
        dprintf("sw_to_pc combo_enable! keycode=%u, layer=%u\n", keycode, layer);
        combo_enable();
    } else {
        dprintf("sw_to_pc combo_disable! keycode=%u, layer=%u\n", keycode, layer);
        combo_disable();
    };
    tap_code(DF(layer));
    tap_code(KC_HOME);
    wait_ms(200);
    tap_code(KC_HOME);
    wait_ms(200);
    tap_code(keycode);
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    // dprintf("process_record_user keycode=%u, record->event.pressed=%u\n", keycode, record->event.pressed);
    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        case SW_PC1:
            sw_to_pc(KC_1, _JP);
            return false;
        case SW_PC2:
            sw_to_pc(KC_2, _JP);
            return false;
        case SW_PC3:
            sw_to_pc(KC_3, _US);
            return false;
        case SW_PC4:
            sw_to_pc(KC_4, _US);
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

// Combo related functions
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable combo on US layout layer */
    // 新しいバージョンの機能らしい（後で最新化）
    if (layer_state_is(_US) || layer_state_is(_UL)) {
        dprintf("combo_should_trigger=false\n");
        // dprintf("combo_should_trigger=false\n");
        return false;
    }
    dprintf("combo_should_trigger=true\n");
    // dprintf("combo_should_trigger=true\n");
    return true;
}
void process_combo_event(uint8_t combo_index, bool pressed) {
    // 新しいバージョンの機能らしい（後で最新化）
    dprintf("process_combo_event combo_index=%u,pressed=%u\n", combo_index, pressed);
//   switch(combo_index) {
//     case COMBO_01:
//       if (pressed) {
//         tap_code16(LSFT(KC_C));
//       }
//       break;
//     case COMBO_02:
//       if (pressed) {
//         tap_code16(LSFT(KC_D));
//       }
//       break;
//     case COMBO_03:
//       if (pressed) {
//         tap_code16(LSFT(KC_E));
//       }
//       break;
//   }
}
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
}
