/*
   Copyright 2026 Alys Frost

   This program is free software: you can AF_REDistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR AF_PURPOSE.  See the
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
   to press the reset pin. The combos are mirroAF_RED on each half. Just press the first four
   keys on the top row of the left half, or the last four keys on the top row of the right
   half. Eventually I'd like to improve this so the same actions will also exit that state.
*/
const uint16_t PROGMEM boot_left[]  = { QK_GESC, KC_1, KC_2, KC_3, COMBO_END };
const uint16_t PROGMEM boot_right[] = { KC_BSPC, KC_0, KC_9, KC_8, COMBO_END };

combo_t key_combos[] = {
   COMBO(boot_left, QK_BOOT),
   COMBO(boot_right, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [DVORAK] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
      KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC,          AF_LYR,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX,
                                          KC_LALT, KC_LGUI, KC_SPC,           AF_SPC,  MO(1),  AF_MED
   ),
   [NAVIGATION] = LAYOUT(
      KC_GRV,  TO(0),   _______, TO(3),   TO(2),   _______,                            _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   KC_SLSH, KC_EQL,  _______,
      _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, _______,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, _______, _______
   ),
   [SETTINGS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_FLGP, RM_VALU, RM_FLGN, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_PREV, RM_VALD, RM_NEXT, _______, _______, RM_TOGG,
      _______, _______, _______, _______, _______, _______, _______,          AF_LYR,  _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, MO(1),   _______
   ),
   [GAMING] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, KC_Q,    KC_W,    KC_E,    KC_R,                               _______, _______, _______, _______, _______, _______,
      _______, KC_RSFT, KC_A,    KC_S,    KC_D,    KC_F,                               _______, _______, _______, _______, _______, _______,
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    AF_REC,           AF_LYR,  _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, TO(1),  _______
   )
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
      AF_CYAN,          AF_CYAN,          AF_CYAN,                                              AF_CYAN,          AF_CYAN,          AF_CYAN,
      AF_NONE, AF_PINK, AF_GOLD, AF_CYAN, AF_LIME, AF_PURP,                            AF_PURP, AF_LIME, AF_CYAN, AF_GOLD, AF_PINK, AF_NONE,    
      AF_CYAN, AF_PINK, AF_GOLD, AF_CYAN, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_CYAN, AF_GOLD, AF_PINK, AF_CYAN,   
      AF_CYAN, AF_NONE, AF_GOLD, AF_CYAN, AF_LIME, AF_NONE,                            AF_NONE, AF_LIME, AF_CYAN, AF_GOLD, AF_PINK, AF_CYAN,   
      AF_CYAN, AF_PINK, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_CYAN,          AF_PURP, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_CYAN,     
                                          AF_CYAN, AF_LIME, AF_PURP,          AF_PURP, AF_CYAN, AF_CYAN,
      AF_CYAN,          AF_CYAN,          AF_CYAN,                                              AF_CYAN,          AF_CYAN,          AF_CYAN
   ),
   [NAVIGATION] = RGB_LAYOUT(
      AF_LIME,          AF_LIME,          AF_LIME,                                              AF_LIME,          AF_LIME,          AF_LIME,     
      AF_NONE, AF_CYAN, AF_LIME, AF_GOLD, AF_FIRE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_CYAN, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_CYAN, AF_CYAN, AF_CYAN, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_LIME,          AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
                                          AF_NONE, AF_NONE, AF_NONE,          AF_NONE, AF_LIME, AF_NONE, 
      AF_LIME,          AF_LIME,          AF_LIME,                                              AF_LIME,          AF_LIME,          AF_LIME
   ),
   [SETTINGS] = RGB_LAYOUT(
      AF_GOLD,          AF_GOLD,          AF_GOLD,                                              AF_GOLD,          AF_GOLD,          AF_GOLD,    
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_GOLD,          AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
                                          AF_NONE, AF_NONE, AF_NONE,          AF_NONE, AF_GOLD, AF_NONE, 
      AF_GOLD,          AF_GOLD,          AF_GOLD,                                              AF_GOLD,          AF_GOLD,          AF_GOLD
   ),
   [GAMING] = RGB_LAYOUT(
      AF_FIRE,          AF_FIRE,          AF_FIRE,                                              AF_FIRE,          AF_FIRE,          AF_FIRE,    
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_CYAN, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_CYAN, AF_CYAN, AF_CYAN, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_FIRE,          AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, 
                                          AF_NONE, AF_NONE, AF_NONE,          AF_NONE, AF_FIRE, AF_NONE, 
      AF_FIRE,          AF_FIRE,          AF_FIRE,                                              AF_FIRE,          AF_FIRE,          AF_FIRE
   )
};

/* 
   EMPTY LIGHTMAP LAYER
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!
   It should match the respective layer's name in the keymap above.

   [LAYER NAME] = LAYOUT(
      AF_NONE,          AF_NONE,          AF_NONE,                                              AF_NONE,          AF_NONE,          AF_NONE,    
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_OFF, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_OFF, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,                            AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_OFF, 
      AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE,          AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_NONE, AF_OFF, 
                                          AF_NONE, AF_NONE, AF_NONE,          AF_NONE, AF_NONE, AF_OFF, 
      AF_NONE,          AF_NONE,          AF_NONE,                                              AF_NONE,          AF_NONE,          AF_OFF
   )
*/

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   for (uint8_t i = led_min; i < led_max; i++) {
      uint8_t layer = get_highest_layer(layer_state);
      rgb_t colour = rgbmaps[layer][i];
      
      // Check if the colour from the referenced layer
      // matches _______ / AF_TRANS. If it does, search
      // the previous layers until a colour is found and
      // pass that colour through.
      if (layer > 0 && rgb_equal(colour, AF_TRNS)) {
         for (uint8_t l = layer; l < sizeof(keymaps)/sizeof(keymaps[0]); l--) {
            // We've reached the last layer and no colour
            // was found so we'll just turn it AF_OFF.
            if (l < 0) {
               colour = AF_NONE;
               break;
            };
            
            // A colour was found so we'll use it and break the loop.
            if (!rgb_equal(rgbmaps[l][i], AF_TRNS)) {
               colour = rgbmaps[l][i];
               break;
            }
         }
      }
      
      rgb_matrix_set_color(i, colour.r, colour.g, colour.b);
   }

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