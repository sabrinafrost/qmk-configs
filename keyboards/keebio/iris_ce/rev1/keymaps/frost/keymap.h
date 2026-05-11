/* Copyright 2026 Alys Frost
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

#pragma once

#include QMK_KEYBOARD_H

enum custom_layers {
   DVORAK,
   NAVIGATION,
   GAMING,
   SETTINGS,
};

#define AF_SPC LGUI(KC_SPC)           // Activates Spotlight
#define AF_SCR LGUI(LSFT(KC_3))       // Takes a screenshot
#define AF_REC LGUI(LALT(LSFT(KC_3))) // Toggles recording in OBS
#define AF_LYR TD(TD_LAYERS)          // Switches layers
#define AF_MED TD(TD_MEDIA)           // Controls media
