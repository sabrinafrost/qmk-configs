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
#include QMK_KEYBOARD_H

// Define this in config.h to control the default brightness of LEDs when using
// the HEX macro. This is helpful for preventing, say, an entire layout of pure
// red LEDs from drawing too much current and flickering as a result.
#ifndef RGB_MATRIX_DEFAULT_BRIGHTNESS
    #define RGB_MATRIX_DEFAULT_BRIGHTNESS 100
#endif

// INTERNAL (use HEX instead): Converts HEX code to RGB and uses a 0-100 value
// to darken the output, acting as a dimmer for LED lighting.
#define HEX_TO_RGB(hex, pct) ((rgb_t) {                   \
    .r = (uint8_t)((((hex) >> 16) & 0xFF) * (pct) / 100), \
    .g = (uint8_t)((((hex) >>  8) & 0xFF) * (pct) / 100), \
    .b = (uint8_t)((((hex) >>  0) & 0xFF) * (pct) / 100)  \
})
// INTERNAL (use HEX instead): Allows for the 0x HEX prefix to be omitted.
#define HEX_FORCE(hex) (0x##hex)
// INTERNAL (use HEX instead): Argument selector (chooses 1 or 2 args version)
#define HEX_GET_MACRO(_1, _2, NAME, ...) NAME
// INTERNAL (use HEX instead): 1-arg version (default brightness)
#define HEX_1(hex) HEX_TO_RGB(HEX_FORCE(hex), RGB_MATRIX_DEFAULT_BRIGHTNESS)
// INTERNAL (use HEX instead): 2-arg version (explicit brightness)
#define HEX_2(hex, pct) HEX_TO_RGB(HEX_FORCE(hex), pct)

/*
    HEX(...)

    Converts a 24-bit hex color into a QMK `rgb_t` with optional brightness scaling.

    ### Usage
    ```
    HEX(RRGGBB)      // full brightness   (100%)
    HEX(RRGGBB, pct) // scaled brightness (0–100)
    ```
    ### Parameters
        `hex`  - 24-bit hexadecimal color in RRGGBB format (no 0x prefix)
        `pct`  - Optional brightness percentage (0–100)
                If omitted, defaults to 100.

    ### Behavior
        - Extracts RGB channels from the hex value.
        - Applies linear brightness scaling per channel.
        - Returns a fully populated `rgb_t` struct.

    ### Notes
        - The macro internally converts the input into a valid hex literal.
        - Brightness scaling is linear (not gamma-corrected).
        - Designed for QMK RGB matrix / LED effects.
 */
#define HEX(...) HEX_GET_MACRO(__VA_ARGS__, HEX_2, HEX_1)(__VA_ARGS__)

/*
    NAMED COLOURS
    -------------
    Commonly used colours picked from the available named HTML colours.
    Organized by the spectrum of the rainbow, with the named HTML colour
    added as a comment for reference.
*/
#define AF_FIRE   HEX(FF0000) // Red
#define AF_PINK   HEX(FF1493) // Pink
#define AF_GOLD   HEX(FFD700) // Gold
#define AF_LIME   HEX(60FF00) // Green
#define AF_CYAN   HEX(00FFFF) // Cyan
#define AF_BLUE   HEX(0000FF) // Blue
#define AF_PURP   HEX(9932CC) // Purple
#define AF_WHTE   HEX(FFFFFF) // White

#define AF_NONE   HEX(000000, 100) // Black. Simply means the LED is off.
#define AF_TRNS   HEX(000001, 100) // Almost black, used to pass colours through from layers above.

// Checks if two `rgb_t` values are equal.
bool rgb_equal(rgb_t a, rgb_t b);

