/*
   Copyright 2026 Alys Frost

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.oRGLW_/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

enum custom_layers {
   DVORAK,
   NAVIGATION,
   GAMING,
   PHOTOGRAPHY,
   SETTINGS,
};

// Aliases
#define FR_SPC LGUI(KC_SPC)           // Activates Spotlight
#define FR_SCR LGUI(LSFT(KC_3))       // Takes a screenshot
#define FR_REC LGUI(LALT(LSFT(KC_3))) // Toggles recording in OBS
#define FR_LYR TD(TD_LAYERS)          // Switches layers
#define FR_MED TD(TD_MEDIA)           // Controls media

// Layers
#define TO_DVK TO(DVORAK)             // Switches to default (Dvorak) layer
#define TO_NAV TO(NAVIGATION)         // Switches to navigation layer
#define MO_NAV MO(NAVIGATION)         // Momentarily switches to navigation layer
#define TO_GMG TO(GAMING)             // Switches to gaming layer
#define TO_PIC TO(PHOTOGRAPHY)        // Switches to photo editing layer
#define TO_SET TO(SETTINGS)           // Switches to keyboard settings layer

#define LAYER( \
   LGLW_01,          LGLW_02,          LGLW_03,                                         RGLW_03,          RGLW_02,          RGLW_01, \
                                                                                                                                     \
   LLED_01, LLED_02, LLED_03, LLED_04, LLED_05, LLED_06,                       RLED_06, RLED_05, RLED_04, RLED_03, RLED_02, RLED_01, \
   LKEY_01, LKEY_02, LKEY_03, LKEY_04, LKEY_05, LKEY_06,                       RKEY_06, RKEY_05, RKEY_04, RKEY_03, RKEY_02, RKEY_01, \
                                                                                                                                     \
   LLED_10, LLED_11, LLED_12, LLED_13, LLED_14, LLED_15,                       RLED_15, RLED_14, RLED_13, RLED_12, RLED_11, RLED_10, \
   LKEY_10, LKEY_11, LKEY_12, LKEY_13, LKEY_14, LKEY_15,                       RKEY_15, RKEY_14, RKEY_13, RKEY_12, RKEY_11, RKEY_10, \
                                                                                                                                     \
   LLED_16, LLED_17, LLED_18, LLED_19, LLED_20, LLED_21,                       RLED_21, RLED_20, RLED_19, RLED_18, RLED_17, RLED_16, \
   LKEY_16, LKEY_17, LKEY_18, LKEY_19, LKEY_20, LKEY_21,                       RKEY_21, RKEY_20, RKEY_19, RKEY_18, RKEY_17, RKEY_16, \
                                                                                                                                     \
   LLED_22, LLED_23, LLED_24, LLED_25, LLED_26, LLED_27, LLED_31,     RLED_31, RLED_27, RLED_26, RLED_25, RLED_24, RLED_23, RLED_22, \
   LKEY_22, LKEY_23, LKEY_24, LKEY_25, LKEY_26, LKEY_27, LKEY_31,     RKEY_31, RKEY_27, RKEY_26, RKEY_25, RKEY_24, RKEY_23, RKEY_22, \
                                                                                                                                     \
                                       LLED_28, LLED_29, LLED_30,     RLED_30, RLED_29, RLED_28,                                     \
                                       LKEY_28, LKEY_29, LKEY_30,     RKEY_30, RKEY_29, RKEY_28,                                     \
                                                                                                                                     \
   LGLW_04,          LGLW_05,          LGLW_06,                                         RGLW_06,          RGLW_05,          RGLW_04  \
) { \
   LAYOUT( \
      LKEY_01, LKEY_02, LKEY_03, LKEY_04, LKEY_05, LKEY_06,                       RKEY_06, RKEY_05, RKEY_04, RKEY_03, RKEY_02, RKEY_01, \
      LKEY_10, LKEY_11, LKEY_12, LKEY_13, LKEY_14, LKEY_15,                       RKEY_15, RKEY_14, RKEY_13, RKEY_12, RKEY_11, RKEY_10, \
      LKEY_16, LKEY_17, LKEY_18, LKEY_19, LKEY_20, LKEY_21,                       RKEY_21, RKEY_20, RKEY_19, RKEY_18, RKEY_17, RKEY_16, \
      LKEY_22, LKEY_23, LKEY_24, LKEY_25, LKEY_26, LKEY_27, LKEY_31,     RKEY_31, RKEY_27, RKEY_26, RKEY_25, RKEY_24, RKEY_23, RKEY_22, \
                                          LKEY_28, LKEY_29, LKEY_30,     RKEY_30, RKEY_29, RKEY_28                                      \
   ), \
   RGB_LAYOUT( \
      LGLW_01,          LGLW_02,          LGLW_03,                                         RGLW_03,          RGLW_02,          RGLW_01, \
      LLED_01, LLED_02, LLED_03, LLED_04, LLED_05, LLED_06,                       RLED_06, RLED_05, RLED_04, RLED_03, RLED_02, RLED_01, \
      LLED_10, LLED_11, LLED_12, LLED_13, LLED_14, LLED_15,                       RLED_15, RLED_14, RLED_13, RLED_12, RLED_11, RLED_10, \
      LLED_16, LLED_17, LLED_18, LLED_19, LLED_20, LLED_21,                       RLED_21, RLED_20, RLED_19, RLED_18, RLED_17, RLED_16, \
      LLED_22, LLED_23, LLED_24, LLED_25, LLED_26, LLED_27, LLED_31,     RLED_31, RLED_27, RLED_26, RLED_25, RLED_24, RLED_23, RLED_22, \
                                          LLED_28, LLED_29, LLED_30,     RLED_30, RLED_29, RLED_28,                                     \
      LGLW_04,          LGLW_05,          LGLW_06,                                         RGLW_06,          RGLW_05,          RGLW_04  \
   ), \
}
