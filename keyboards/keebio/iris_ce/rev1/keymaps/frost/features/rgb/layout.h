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

    LED MAP
    ---
    This is how I've "zoned" out my LEDs. You can do this properly with flags, but I'd like to 
    make use of QMK's userspace, which doesn't allow you to edit `keyboard.json`. This makes the
    zone skipping features in QMK useless, but that doesn't really matter to me because I'm
    handling my own lighting.

    MAP LEGEND
    ---
    NUM: Numbers
    LTR: Letters
    SPC: Special Characters
    MOD: Modifiers
    ACT: Actions (keys that do things, like tab, enter, layer toggling, etc.)
    GLW: Underglow (the lights on the bottom of the keyboard)
    OFF: Keys without shine-through caps

    ┌─────┬─────┬─────┬─────┬─────┐                             ┌─────┬─────┬─────┬─────┬─────┐
      GLW         GLW         GLW                                 GLW         GLW         GLW
    └─────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴─────┘
    ┌─────┬─────┬─────┬─────┬─────┬─────┐                 ┌─────┬─────┬─────┬─────┬─────┬─────┐  
      OFF   OFF   NUM   NUM   NUM   NUM                     NUM   NUM   NUM   OFF   NUM   OFF
    ├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
      ACT   SPC   SPC   SPC   OFF   OFF                     OFF   OFF   OFF   SPC   SPC   SPC
    ├─────┼─────┼─────┼─────┼─────┼─────┤                 ├─────┼─────┼─────┼─────┼─────┼─────┤
      MOD   OFF   OFF   OFF   LTR   OFF                     OFF   LTR   OFF   OFF   SPC   ACT
    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐     ┌─────┼─────┼─────┼─────┼─────┼─────┤─────┤
      MOD   OFF   OFF   OFF   OFF   OFF   ACT         ACT   OFF   OFF   OFF   OFF   OFF   MOD
    └─────┴─────┴─────┴─────┴─────┼─────┤─────┤     ├─────┼─────┼─────┼─────┴─────┴─────┴─────┘
                              MOD   MOD   OFF         ACT   ACT   ACT
                            └─────┴─────┴─────┘     └─────┴─────┴─────┘
    ┌─────┬─────┬─────┬─────┬─────┐                             ┌─────┬─────┬─────┬─────┬─────┐
      GLW         GLW         GLW                                 GLW         GLW         GLW
    └─────┴─────┴─────┴─────┴─────┘                             └─────┴─────┴─────┴─────┴─────┘
*/

#include "./colours.h"

/*
    Generate a lightmap by targeting the individual LEDs.

    Example
    ---
    ```
    const rgb_t PROGMEM rgbmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = RGB_LAYOUT(
            FR_OFF,           FR_OFF,           FR_OFF,                                            FR_OFF,           FR_OFF,           FR_OFF,
            FR_OFF,  FR_OFF,  FR_GOLD, FR_BLUE, FR_GRN, FR_PURP,                          FR_PURP, FR_GRN,  FR_BLUE, FR_OFF,  FR_RED,  FR_OFF,
            FR_CYAN, FR_RED,  FR_GOLD, FR_BLUE, FR_OFF,  FR_OFF,                          FR_OFF,  FR_OFF,  FR_OFF,  FR_GOLD, FR_RED,  FR_CYAN,
            FR_CYAN, FR_OFF,  FR_OFF,  FR_OFF,  FR_GRN,  FR_OFF,                          FR_OFF,  FR_GRN,  FR_OFF,  FR_OFF,  FR_RED,  FR_CYAN,
            FR_CYAN, FR_OFF,  FR_OFF,  FR_OFF,  FR_OFF,  FR_OFF,  FR_PURP,       FR_PURP, FR_OFF,  FR_OFF,  FR_OFF,  FR_OFF,  FR_OFF,  FR_CYAN,  
                                                FR_BLUE, FR_GRN,  FR_OFF,        FR_PURP, FR_GRN,  FR_BLUE,
            FR_OFF,           FR_OFF,           FR_OFF,                                            FR_OFF,           FR_OFF,           FR_OFF
        ),
    };
*/
#define RGB_LAYOUT( \
    LG01,       LG02,       LG03,                             RG03,       RG02,       RG01, \
    LH01, LH02, LH03, LH04, LH05, LH06,                 RH06, RH05, RH04, RH03, RH02, RH01, \
    LH10, LH11, LH12, LH13, LH14, LH15,                 RH15, RH14, RH13, RH12, RH11, RH10, \
    LH16, LH17, LH18, LH19, LH20, LH21,                 RH21, RH20, RH19, RH18, RH17, RH16, \
    LH22, LH23, LH24, LH25, LH26, LH27, LH31,     RH31, RH27, RH26, RH25, RH24, RH23, RH22, \
                            LH28, LH29, LH30,     RH30, RH29, RH28,                         \
    LG04,       LG05,       LG06,                             RG06,       RG05,       RG04  \
) { \
    LH01, LG01, LH02, LH03, LG02, LH04, LH05, LG03, LH06, \
    LH15, LH14, LH13, LH12, LH11, LH10, \
    LH16, LH17, LH18, LH19, LH20, LH21, \
    LH27, LH26, LH25, LH24, LH23, LH22, \
    LG04, LG05, LH28, LH29, LG06, LH30, LH31, \
    RH01, RG01, RH02, RH03, RG02, RH04, RH05, RG03, RH06, \
    RH15, RH14, RH13, RH12, RH11, RH10, \
    RH16, RH17, RH18, RH19, RH20, RH21, \
    RH27, RH26, RH25, RH24, RH23, RH22, \
    RG04, RG05, RH28, RH29, RG06, RH30, RH31, \
}

/*
    Generate a lightmap by targeting zones instead of individual keys.

    NUM: Numbers
    LTR: Letters
    SPC: Special Characters
    MOD: Modifiers
    ACT: Actions
    GLW: Underglow
    OFF: Keys without shine-through caps.

    Example
    ---
    ```
    const rgb_t PROGMEM rgbmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = RGB_ZONES(
            FR_BLUE, // Numbers
            FR_OFF,  // Letters
            FR_OFF,  // Special Characters
            FR_OFF,  // Modifiers
            FR_CYAN, // Actions
            FR_OFF,  // Underglow
            FR_OFF   // Keys without shine-through caps.
        ),
    };
    ```
*/
#define RGB_ZONES(NUMB,EDGE,THMB,ARRW,GLOW,OFF) RGB_LAYOUT(\
    GLOW,       GLOW,       GLOW,                              GLOW,       GLOW,       GLOW, \
    OFF,  NUMB, NUMB, NUMB, NUMB, NUMB,                  NUMB, NUMB, NUMB, NUMB, NUMB, OFF,  \
    EDGE, NUMB, NUMB, ARRW, OFF,  OFF,                   OFF,  OFF,  ARRW, NUMB, NUMB, EDGE, \
    EDGE, OFF,  ARRW, ARRW, ARRW, OFF,                   OFF,  ARRW, ARRW, ARRW, NUMB, EDGE, \
    EDGE, NUMB, OFF,  OFF,  OFF,  OFF,  ARRW,      ARRW, OFF,  OFF,  OFF,  OFF,  OFF,  EDGE, \
                            EDGE, EDGE, THMB,      THMB, EDGE, EDGE,                         \
    GLOW,       GLOW,       GLOW,                              GLOW,       GLOW,       GLOW  \
)

/*
    Generate a solid lightmap for all keys.

    Example
    ---
    ```
    const rgb_t PROGMEM rgbmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = RGB_ALL(FR_BLUE),
    };
    ```
*/
#define RGB_ALL(ALL) { \
    ALL, ALL, ALL, ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, \
    ALL, ALL, ALL, ALL, ALL, ALL, ALL, \
}
