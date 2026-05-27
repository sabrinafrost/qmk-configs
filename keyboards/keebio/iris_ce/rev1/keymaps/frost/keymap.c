/*
   Copyright 2026 Alys Frost

   This program is free software: you can FR_REDistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR FR_PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "./keymap.h"
#include "./features/tapdances.h"
#include "./features/rgb.h"

/*
   COMBOS
   ------
   I'm using combos to enter bootloader mode from either half independently without needed
   to press the reset pin. The combos are mirroFR_RED on each half. Just press the first four
   keys on the top row of the left half, or the last four keys on the top row of the right
   half. Eventually I'd like to improve this so the same actions will also exit that state.
*/
const uint16_t PROGMEM boot_left[]  = { KC_ESC,  KC_1, KC_2, KC_3, COMBO_END };
const uint16_t PROGMEM boot_right[] = { KC_BSPC, KC_0, KC_9, KC_8, COMBO_END };

combo_t key_combos[] = {
   COMBO(boot_left, QK_BOOT),
   COMBO(boot_right, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [DVORAK] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
      KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC,          KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                                          KC_LALT, KC_LGUI, KC_SPC,           FR_SPC,  MO_NAV,  FR_MED
   ),
   [NAVIGATION] = LAYOUT(
      KC_GRV,  TO_DVK,  _______, TO_GMG,  TO_PIC,  TO_SET,                              _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   KC_SLSH, KC_EQL,  _______,
      _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, _______,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, _______, _______
   ),
   [GAMING] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, KC_Q,    KC_W,    KC_E,    KC_R,                               _______, _______, _______, _______, _______, _______,
      _______, KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,                               _______, _______, _______, _______, _______, _______,
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    FR_REC,           _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, MO_NAV, _______
   ),
   [PHOTOGRAPHY] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_PMNS,          KC_PPLS, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, MO_NAV, _______
   ),
   [SETTINGS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_FLGP, RM_VALU, RM_FLGN, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_PREV, RM_VALD, RM_NEXT, _______, _______, RM_TOGG,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, MO_NAV,  _______
   ),
};

/* 
   EMPTY KEYMAP LAYER
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!

   [LAYER NAME] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, _______, _______,
   )
*/

const rgb_t PROGMEM rgbmaps[][RGB_MATRIX_LED_COUNT] = {
   [DVORAK] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,
      RGB_NONE, RGB_CYN1, RGB_PNK2, RGB_PNK2, RGB_PNK2, RGB_PNK2,                            RGB_PNK2, RGB_PNK2, RGB_PNK2, RGB_PNK2, RGB_PNK2, RGB_NONE,
      RGB_GLD3, RGB_GLD3, RGB_GLD3, RGB_CYN1, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_CYN1, RGB_GLD3, RGB_GLD3, RGB_GLD3,
      RGB_GLD3, RGB_NONE, RGB_CYN1, RGB_CYN1, RGB_CYN1, RGB_NONE,                            RGB_NONE, RGB_CYN1, RGB_CYN1, RGB_CYN1, RGB_GLD3, RGB_GLD3,
      RGB_GLD3, RGB_GLD3, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_CYN1,        RGB_CYN1, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_GLD3,
                                              RGB_GLD3, RGB_GLD3, RGB_PUR1,        RGB_PUR1, RGB_GLD3, RGB_GLD3,  
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   ),
   [NAVIGATION] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,     
      RGB_NONE, RGB_CYN1, RGB_LIM1, RGB_GLD1, RGB_RED1, RGB_WHT1,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_CYN1, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_CYN1, RGB_CYN1, RGB_CYN1, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_LIM1,        RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
                                              RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_LIM1, RGB_NONE, 
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   ),
   [GAMING] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,    
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_CYN1, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_CYN1, RGB_CYN1, RGB_CYN1, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_RED1,        RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
                                              RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_RED1, RGB_NONE, 
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   ),
   [PHOTOGRAPHY] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,    
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_LIM1, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_RED1, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_RED1,        RGB_LIM1, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
                                              RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   ),
   [SETTINGS] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,    
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_GLD1,        RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
                                              RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_GLD1, RGB_NONE, 
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   ),
};

/* 
   EMPTY RGBMAP LAYER
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!
   It should match the respective layer's name in the keymap above.

   [LAYER NAME] = RGB_LAYOUT(
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE,    
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,                            RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, RGB_NONE, 
                                              RGB_NONE, RGB_NONE, RGB_NONE,        RGB_NONE, RGB_NONE, RGB_NONE, 
      RGB_NONE,           RGB_NONE,           RGB_NONE,                                                RGB_NONE,           RGB_NONE,           RGB_NONE
   )
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   //  if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                  switch(keymap_key_to_keycode(layer, (keypos_t){col,row})) {
                     case KC_1:
                     case KC_2:
                     case KC_3:
                     case KC_4:
                     case KC_5:
                     case KC_6:
                     case KC_7:
                     case KC_8:
                     case KC_9:
                     case KC_0:
                        rgb_matrix_set_color(index, RGB_GREEN);
                        break;
                     default:
                        rgb_matrix_set_color(index, 0, 0, 0);
                        break;
                  }

                }
            }
        }
   //  }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_LAYERS):
            return 175;
        default:
            return TAPPING_TERM;
    }
}

void keyboard_post_init_user(void) {
   rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
   rgb_matrix_sethsv_noeeprom(HSV_OFF);
}