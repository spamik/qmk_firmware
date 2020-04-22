#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, LM(3, MOD_LGUI | MOD_LALT | MOD_LSFT), KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F17, LT(3,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LALT_T(KC_F14), LT(2,KC_LGUI), KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_LCTL, KC_LALT, KC_DEL, KC_BSPC, KC_ENT, MO(1), KC_F18, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_F15, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_F16, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, KC_EQL, KC_MINS, LSFT(KC_DOT), KC_INS, TG(2), KC_RALT, KC_LGUI, LM(1, MOD_LALT), MO(1), KC_LSFT, KC_SPC),
	[1] = LAYOUT_ergodox(RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_NO, KC_LCTL, KC_LSFT, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO),
	[2] = LAYOUT_ergodox(RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, KC_TRNS, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_NO, KC_TRNS, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_NO, KC_P0, KC_DOT, KC_PDOT, KC_PENT, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
	[3] = LAYOUT_ergodox(KC_NO, KC_NO, KC_NO, KC_NO, KC_F15, KC_F16, KC_TRNS, KC_NO, MEH(KC_Q), LGUI(KC_UP), MEH(KC_E), KC_NO, KC_NO, KC_TRNS, KC_NO, LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT), KC_NO, KC_NO, KC_NO, MEH(KC_Z), MEH(KC_X), MEH(KC_C), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, SGUI(KC_X), SGUI(KC_D), SGUI(KC_M), KC_NO, KC_NO, KC_NO, LGUI(KC_ENT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

uint32_t layer_state_set_user(uint32_t state) {
  if (biton32(state) == 0) {
    ergodox_right_led_3_off();
  } else {
    ergodox_right_led_3_on();
  }
  return state;
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        ergodox_right_led_2_on();
    } else {
        // Turn capslock off
        ergodox_right_led_2_off();
	}
	 if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // Turn numlock on
        ergodox_right_led_1_on();
    } else {
        // Turn numlock off
        ergodox_right_led_1_off();
	}
}