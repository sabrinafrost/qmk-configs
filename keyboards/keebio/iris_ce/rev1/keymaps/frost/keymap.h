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


/*
   IDEA
   ----
   - Write a RGB effect the proper way and have it assign colours based on the keycodes.
   - Define the keycodes to include in each colour group.
   - This way mapping is consist and automatic between layers.
   - The only configuration required is what colours to map to which keycode groups.
*/

#define ZONE_NUMBERS          KC_1|KC_2|KC_3|KC_4|KC_5|KC_6|KC_7|KC_8|KC_9|KC_0

