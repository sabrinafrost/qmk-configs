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

 #include QMK_KEYBOARD_H

/*
    This LED config overrides the one provided in keyboard.json. I'm doing this
    to remap the "zones" you can cycle through in the RGB Matrix effects. My keyboard
    has some keys with opaque caps, so I've removed their flags, etc. This is very specific
    to my keyboard layout. If you're using my keyboard config as inspiration for your own
    but you don't want this to be included, delete this file and remove the reference to it
    in rules.mk.
*/
led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
        // LEFT SIDE
        {  0,  2,  3,  5,  6,  8 },
        { 14, 13, 12, 11, 10,  9 },
        { 15, 16, 17, 18, 19, 20 },
        { 26, 25, 24, 23, 22, 21 },
        { NO_LED, 29, 30, 32, 33 },

        // RIGHT SIDE
        { 34, 36, 37, 39, 40, 42 },
        { 48, 47, 46, 45, 44, 43 },
        { 49, 50, 51, 52, 53, 54 },
        { 60, 59, 58, 57, 56, 55 },
        { NO_LED, 63, 64, 66, 67 }
    },

    // LED Index to Physical Position
    {
        // LEFT SIDE
        {  0,  5 }, {  8,  5 }, { 16,  5 }, { 32,  2 }, { 40,  1 }, { 48,  0 }, { 64,  5 }, { 72,  3 }, { 80,  3 },
        { 80, 17 }, { 64, 15 }, { 48, 13 }, { 32, 15 }, { 16, 18 }, {  0, 18 },
        {  0, 32 }, { 16, 32 }, { 32, 28 }, { 48, 27 }, { 64, 28 }, { 80, 30 },
        { 80, 43 }, { 64, 42 }, { 48, 40 }, { 32, 42 }, { 16, 45 }, {  0, 45 },
        {  8, 43 }, { 40, 50 }, { 56, 47 }, { 72, 58 }, { 80, 58 }, { 90, 64 }, { 98, 52 },

        // RIGHT SIDE
        { 224,  5 }, { 216,  5 }, { 208,  5 }, { 192,  2 }, { 184,  1 }, { 176,  0 }, { 160,  5 }, { 152,  3 }, { 144,  3 },
        { 144, 17 }, { 160, 15 }, { 176, 13 }, { 192, 15 }, { 208, 18 }, { 224, 18 },
        { 224, 32 }, { 208, 32 }, { 192, 28 }, { 176, 27 }, { 160, 28 }, { 144, 30 },
        { 144, 43 }, { 160, 42 }, { 176, 40 }, { 192, 42 }, { 208, 45 }, { 224, 45 },
        { 216, 43 }, { 184, 50 }, { 168, 47 }, { 152, 58 }, { 144, 58 }, { 134, 64 }, { 126, 52 }
    },

    // LED Index to Flag
    {
        // LEFT SIDE
        0, 2, 4, 4, 2, 4, 4, 2, 4, // Row 1: From left to right
        0, 0, 4, 4, 4, 1,          // Row 2: From right to left
        1, 0, 4, 4, 4, 0,          // Row 3: From left to right
        0, 0, 0, 0, 4, 1,          // Row 4: From right to left
        2, 2, 1, 1, 2, 1, 8,       // Row 5: From left to right

        // RIGHT SIDE
        0, 2, 4, 4, 2, 4, 4, 2, 4, // Row 1: From right to left
        0, 0, 2, 4, 4, 1,          // Row 2: From left to right
        1, 4, 2, 2, 2, 0,          // Row 3: From right to left
        0, 0, 0, 0, 0, 1,          // Row 4: From left to right
        2, 2, 1, 1, 2, 1, 8        // Row 5: From right to left
    }
};