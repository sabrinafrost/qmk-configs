/*
   CREDITS
   -------
   Custom keymap for the Iris CE by Alys Frost (2026)
   SPDX-License-Identifier: GPL-2.0-or-later

   INSTRUCTIONS
   ------------
   Take a look at README.md first, but these are the commands to run once your
   environment is set up with external userspaces.

   To compile firmware with this keymap, enter this command into your terminal.
      qmk compile -kb keebio/iris_ce/rev1 -km frost
   
   To flash the firmware to your board, use QMK Toolbox or enter this command into your terminal.
      qmk flash -kb keebio/iris_ce/rev1 -km frost
*/
#include QMK_KEYBOARD_H
#include "ledmap.h"

/*
   ALIASES
   -------
   It drives me nuts when lengthy keycodes mess up the visual columns of the keymaps.
   These are aliases to shorten those keycodes so they fit nicely into the columns.
   Each alias follows the format of my initials, underscore, and then whatever makes sense.
*/
#define AF_SPC LGUI(KC_SPC)           // Activates Spotlight
#define AF_SCR LGUI(LSFT(KC_3))       // Takes a screenshot
#define AF_REC LGUI(LALT(LSFT(KC_3))) // Toggles recording in OBS

/*
   COMBOS
   ------
   I'm using combos to enter bootloader mode from either half independently without needed
   to press the reset pin. The combos are mirrored on each half. Just press the first four
   keys on the top row of the left half, or the last four keys on the top row of the right
   half. Eventually I'd like to improve this so the same actions will also exit that state.
*/
const uint16_t PROGMEM boot_left[]  = { QK_GESC, KC_1, KC_2, KC_3, COMBO_END };
const uint16_t PROGMEM boot_right[] = { KC_BSPC, KC_0, KC_9, KC_8, COMBO_END };

combo_t key_combos[] = {
   COMBO(boot_left, QK_BOOT),
   COMBO(boot_right, QK_BOOT),
};

/*
   LAYERS
   ------
   I mean... it's pretty self-explanatory, but my need for consistency dictates
   that I put a title and description here like I have everywhere else, so... welcome to my neurosis!
*/
enum custom_layers {
   DVORAK,
   NAVIGATION,
   GAMING,
   SETTINGS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [DVORAK] = LAYOUT(
      QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
      KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC,          KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                                          KC_LALT, KC_LGUI, KC_SPC,           AF_SPC,  MO(1),   KC_MPLY
   ),

    [NAVIGATION] = LAYOUT(
      KC_GRAVE,_______, TO(0),   TO(1),   TO(2),   TO(3),                              _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   KC_SLSH, KC_EQL,  _______,
      _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, _______,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, _______, _______
   ),

   [GAMING] = LAYOUT(
      _______, _______, _______, _______, TO(0),   _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, KC_Q,    KC_W,    KC_E,    KC_R,                               _______, _______, _______, _______, _______, _______,
      _______, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                               _______, _______, _______, _______, _______, _______,
      _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    AF_REC,           _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, TO(1),   _______
   ),

   [SETTINGS] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_FLGP, RM_VALU, RM_FLGN, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            RM_PREV, RM_VALD, RM_NEXT, _______, _______, RM_TOGG,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, MO(1),   _______
   )
};

/* 
   EMPTY LAYER TEMPLATE
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!
   `_______` acts as a transparent key, passing through the keycode from the layer above.

   [LAYER NAME] = LAYOUT(
         _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                             _______, _______, _______,          _______, _______, _______,
   ),
*/

// Overwrite the blank keycode so we can use it as a pass-through
// colour the same way `KC_TRANS` does for keycodes. This define has
// to come after the keymaps.
#define _______ AF_TRANS
// Same idea, but for LEDs we want to turn off.
#define XXXXXXX AF_NO

const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
   [DVORAK] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,     
      XXXXXXX, AF_RED,  AF_GOLD, AF_CYAN, AF_GRN,  AF_PURP,                            AF_PURP, AF_GRN,  AF_CYAN, AF_GOLD, AF_RED,  XXXXXXX, 
      AF_CYAN, AF_RED,  AF_GOLD, AF_CYAN, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, AF_CYAN, AF_GOLD, AF_RED,  AF_CYAN,
      AF_CYAN, XXXXXXX, AF_GOLD, AF_CYAN, AF_GRN,  XXXXXXX,                            XXXXXXX, AF_GRN,  AF_CYAN, AF_GOLD, AF_RED,  AF_CYAN,
      AF_CYAN, AF_RED,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_PURP,          AF_PURP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_CYAN,  
                                          AF_CYAN, AF_GRN,  AF_PURP,          AF_PURP, AF_GRN,  AF_CYAN,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX     
   ),
   [NAVIGATION] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, XXXXXXX, AF_GRN,  AF_GOLD, AF_ORN,  AF_RED,                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, AF_CYAN, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, AF_CYAN, AF_CYAN, AF_CYAN, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX    
   ),
   [GAMING] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, AF_CYAN, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, AF_CYAN, AF_CYAN, AF_CYAN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_RED,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX    
   ),
   [SETTINGS] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX
   )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   for (uint8_t i = led_min; i < led_max; i++) {
      uint8_t layer = get_highest_layer(layer_state);
      rgb_t colour = lightmaps[layer][i];
      
      // Check if the colour from the referenced layer
      // matches _______ / AF_TRANS. If it does, search
      // the previous layers until a colour is found and
      // pass that colour through.
      if (layer > 0 && rgb_equal(colour, _______)) {
         for (uint8_t l = layer; l < sizeof(keymaps)/sizeof(keymaps[0]); l--) {
            // We've reached the last layer and no colour
            // was found so we'll just turn it off.
            if (l < 0) {
               colour = XXXXXXX;
               break;
            };
            
            // A colour was found so we'll use it and break the loop.
            if (!rgb_equal(lightmaps[l][i], _______)) {
               colour = lightmaps[l][i];
               break;
            }
         }
      }
      
      rgb_matrix_set_color(i, colour.r, colour.g, colour.b);
   }

   return false;
}

void keyboard_post_init_user(void) {
   rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
   rgb_matrix_sethsv_noeeprom(HSV_OFF);
}