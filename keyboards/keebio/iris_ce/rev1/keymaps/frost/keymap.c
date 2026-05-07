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
// #include "ledmap.h"

/*
   ALIASES
   -------
   It drives me nuts when lengthy keycodes mess up the visual columns of the keymaps.
   These are aliases to shorten those keycodes so they fit nicely into the columns.
   Each alias follows the format of my initials, underscore, and then whatever makes sense.
*/
#define AF_SPC LGUI(KC_SPC) // Activates Spotlight

/*
   LAYERS
   ------
   I mean... it's pretty self-explanatory, but my need for consistency dictates
   that I put a title and description here like I have everywhere else, so... welcome to my neurosis!
*/
enum custom_layers {
     DVORAK,
     NAVIGATION,
     LIGHTING,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [DVORAK] = LAYOUT(
      // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          KC_LSFT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          KC_LCTL, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_LBRC,          KC_RBRC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
      // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                         KC_LALT, KC_LGUI, KC_SPC,                    AF_SPC,  MO(1),   RM_TOGG
      //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

    [NAVIGATION] = LAYOUT(
      // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          KC_GRAVE, TO(0),   TO(1),   TO(2),   TO(3),   TO(4),                              TO(5),   TO(6),   TO(7),   TO(8),   TO(9),   KC_DEL,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            _______, _______, KC_UP,   KC_SLSH, KC_EQL,  _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
      // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                         _______, _______, _______,                   _______, MO(1),   _______
      //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),

   [LIGHTING] = LAYOUT(
      // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      // ├────────┼────────┼────────┼──────1──┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            RM_FLGP, RM_VALU, RM_FLGN, _______, _______, _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            RM_PREV, RM_VALD, RM_NEXT, _______, _______, RM_TOGG,
      // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
      // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                         _______, _______, _______,                   _______, MO(1),   QK_BOOT
      //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   )
};

/* 
   EMPTY LAYER TEMPLATE
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!
   "_______" acts as a transparent key, passing through the keycode from the layer above.

   [LAYER NAME] = LAYOUT(
      // ┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
      // └────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                         _______, _______, _______,                   _______, _______, _______,
      //                                └────────┴────────┴────────┘                 └────────┴────────┴────────┘
   ),
*/

// const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
//     [DVORAK] = LIGHTMAP_KEYS(
//         // ┌──GLOW──┬────────┬──GLOW──┬────────┬──GLOW──┐                                         ┌──GLOW──┬────────┬──GLOW──┬────────┬──GLOW──┐
//             ______,           ______,           ______,                                            ______,           ______,           ______,
//         // └────────┴────────┴────────┴────────┴────────┘                                         └────────┴────────┴────────┴────────┴────────┘
//         // ┌──OFF───┬──OFF───┬──NUM───┬──NUM───┬──NUM───┬──NUM───┐                       ┌──NUM───┬──NUM───┬──NUM───┬──OFF───┬──NUM───┬──OFF───┐  
//             AF_OFF,  ______,  AF_GOLD, AF_BLUE, AF_GRN, AF_PURP,                          AF_PURP, AF_GRN,  AF_BLUE, ______,  AF_RED,  ______,
//         // ├──ACT───┼──SPC───┼──SPC───┼──SPC───┼──OFF───┼──OFF───┤                       ├──OFF───┼──OFF───┼──OFF───┼──SPC───┼──SPC───┼──SPC───┤
//             AF_CYAN, AF_RED,  AF_GOLD, AF_BLUE, ______,  ______,                          ______,  ______,  ______,  AF_GOLD, AF_RED,  AF_CYAN,
//         // ├──MOD───┼──OFF───┼──OFF───┼──OFF───┼──LTR───┼──OFF───┤                       ├──OFF───┼──LTR───┼──OFF───┼──OFF───┼──SPC───┼──ACT───┤
//             AF_CYAN, ______,  ______,  ______,  AF_GRN,  ______,                          ______,  AF_GRN,  ______,  ______,  AF_RED,  AF_CYAN,
//         // ├──MOD───┼──OFF───┼──OFF───┼──OFF───┼──OFF───┼──OFF───┼──ACT───┐     ┌──ACT───┼──OFF───┼──OFF───┼──OFF───┼──OFF───┼──OFF───┤──MOD───┤
//             AF_CYAN, ______,  ______,  ______,  ______,  ______,  AF_PURP,       AF_PURP, ______,  ______,  ______,  ______,  ______,  AF_CYAN,  
//         // └────────┴────────┴────────┴────────┴──MOD───┼──MOD───┤──OFF───┤     ├──ACT───┼──ACT───┼──ACT───┼────────┴────────┴────────┴────────┘
//                                                 AF_BLUE, AF_GRN,  ______,        AF_PURP, AF_GRN,  AF_BLUE,
//         //                                     └────────┴────────┴────────┘     └────────┴────────┴────────┘
//         // ┌──GLOW──┬────────┬──GLOW──┬────────┬──GLOW──┐                                         ┌──GLOW──┬────────┬──GLOW──┬────────┬──GLOW──┐
//             ______,           ______,           ______,                                            ______,           ______,           ______
//         // └────────┴────────┴────────┴────────┴────────┘                                         └────────┴────────┴────────┴────────┴────────┘
//     ),
//    // [DVORAK] = LIGHTMAP_ZONES(
//    //    AF_CYAN, // Numbers
//    //    AF_WHITE,  // Letters
//    //    AF_PINK,  // Special Characters
//    //    AF_GOLD,  // Modifiers
//    //    AF_GRN, // Actions
//    //    AF_OFF,  // Underglow
//    //    AF_OFF   // Keys without shine-through caps.
//    //  ),
//     [NAVIGATION] = LIGHTMAP_ZONES(
//       AF_BLUE, // Numbers
//       AF_OFF,  // Letters
//       AF_OFF,  // Special Characters
//       AF_OFF,  // Modifiers
//       AF_CYAN, // Actions
//       AF_OFF,  // Underglow
//       AF_OFF   // Keys without shine-through caps.
//     ),
//     [LIGHTING] = LIGHTMAP_ZONES(
//       AF_OFF,  // Numbers
//       AF_OFF,  // Letters
//       AF_OFF,  // Special Characters
//       AF_OFF,  // Modifiers
//       AF_RED,  // Actions
//       AF_BLUE, // Underglow
//       AF_OFF   // Keys without shine-through caps.
//     ),
// };

// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     for (uint8_t i = led_min; i < led_max; i++) {
//         uint8_t layer = get_highest_layer(layer_state);
//         rgb_t color = lightmaps[layer][i];
//         rgb_matrix_set_color(i, color.r, color.g, color.b);
//     }

//     return false;
// }

// void keyboard_post_init_user(void) {
//     rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
//     rgb_matrix_sethsv_noeeprom(HSV_OFF);
// }