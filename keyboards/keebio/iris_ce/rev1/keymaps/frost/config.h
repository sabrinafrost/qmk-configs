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
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#undef  RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_DEFAULT_BRIGHTNESS 50 // sets default brightness of LEDs to 0 out of 100. Used in the HEX macro defined in ./features/rgb/map.h. Useful for preventing overcurrent from demanding colours.
#undef  RGB_MATRIX_FLAG_STEPS
#define RGB_MATRIX_FLAG_STEPS { LED_FLAG_ALL, LED_FLAG_KEYLIGHT, LED_FLAG_MODIFIER, LED_FLAG_UNDERGLOW, LED_FLAG_INDICATOR } // Sets the flags which can be cycled through.
#define RGB_MATRIX_SLEEP // turn off effects when suspended
#define RGB_MATRIX_TIMEOUT 60000 // number of milliseconds to wait until RGB automatically turns off
#define RGB_MATRIX_LED_FLUSH_LIMIT 8 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)