#pragma once

#include "quantum.h"

/*
    COLOURS
    ---
    The following colours are available for use in the functions below.
*/
#define AF_AZURE       (rgb_t){0x99, 0xF5, 0xFF}
#define AF_BLACK       (rgb_t){0x00, 0x00, 0x00}
#define AF_BLUE        (rgb_t){0x00, 0x00, 0xFF}
#define AF_CHARTREUSE  (rgb_t){0x80, 0xFF, 0x00}
#define AF_CORAL       (rgb_t){0xFF, 0x7C, 0x4D}
#define AF_CYAN        (rgb_t){0x00, 0xFF, 0xFF}
#define AF_GOLD        (rgb_t){0xFF, 0xD9, 0x00}
#define AF_GOLDENROD   (rgb_t){0xD9, 0xA5, 0x21}
#define AF_GRN         (rgb_t){0x00, 0xFF, 0x00}
#define AF_MAGENTA     (rgb_t){0xFF, 0x00, 0xFF}
#define AF_ORN         (rgb_t){0xFF, 0x80, 0x00}
#define AF_PINK        (rgb_t){0xFF, 0x80, 0xBF}
#define AF_PURP        (rgb_t){0x7A, 0x00, 0xFF}
#define AF_RED         (rgb_t){0xFF, 0x00, 0x00}
#define AF_SPRINGGREEN (rgb_t){0x00, 0xFF, 0x80}
#define AF_TEAL        (rgb_t){0x00, 0x80, 0x80}
#define AF_TURQUOISE   (rgb_t){0x47, 0x6E, 0x6A}
#define AF_WHITE       (rgb_t){0xFF, 0xFF, 0xFF}
#define AF_YELLOW      (rgb_t){0xFF, 0xFF, 0x00}
#define AF_OFF         AF_BLACK
#define ______         AF_OFF

/*
    LED MAP
    ---
    This is how I've "zoned" out my LEDs. You can do this properly with flags, but I'd like to 
    make use of QMK's userspace, which doesn't allow you to edit keyboard.json. This makes the
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

/*
    Generate a lightmap by targeting the individual LEDs.

    Example
    ---
    ```
    const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = LIGHTMAP_KEYS(
            ______,           ______,           ______,                                            ______,           ______,           ______,
            AF_OFF,  ______,  AF_GOLD, AF_BLUE, AF_GRN, AF_PURP,                          AF_PURP, AF_GRN,  AF_BLUE, ______,  AF_RED,  ______,
            AF_CYAN, AF_RED,  AF_GOLD, AF_BLUE, ______,  ______,                          ______,  ______,  ______,  AF_GOLD, AF_RED,  AF_CYAN,
            AF_CYAN, ______,  ______,  ______,  AF_GRN,  ______,                          ______,  AF_GRN,  ______,  ______,  AF_RED,  AF_CYAN,
            AF_CYAN, ______,  ______,  ______,  ______,  ______,  AF_PURP,       AF_PURP, ______,  ______,  ______,  ______,  ______,  AF_CYAN,  
                                                AF_BLUE, AF_GRN,  ______,        AF_PURP, AF_GRN,  AF_BLUE,
            ______,           ______,           ______,                                            ______,           ______,           ______
        ),
    };
    ```
*/
#define LIGHTMAP_KEYS( \
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
    const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = LIGHTMAP_ZONES(
            AF_BLUE, // Numbers
            AF_OFF,  // Letters
            AF_OFF,  // Special Characters
            AF_OFF,  // Modifiers
            AF_CYAN, // Actions
            AF_OFF,  // Underglow
            AF_OFF   // Keys without shine-through caps.
        ),
    };
    ```
*/
#define LIGHTMAP_ZONES(LTR, NUM, SPC, MOD, ACT, GLW, OFF){ \
    LTR, GLW, NUM, NUM, GLW, NUM, NUM, GLW, NUM, \
    OFF, OFF, SPC, SPC, SPC, ACT, \
    MOD, OFF, OFF, OFF, LTR, OFF, \
    OFF, OFF, OFF, OFF, OFF, MOD, \
    GLW, GLW, MOD, MOD, GLW, OFF, ACT, \
    OFF, GLW, NUM, NUM, GLW, NUM, NUM, GLW, NUM, \
    OFF, OFF, OFF, SPC, SPC, SPC, \
    SPC, SPC, NUM, NUM, LTR, MOD, \
    OFF, OFF, OFF, OFF, OFF, MOD, \
    GLW, GLW, ACT, ACT, GLW, ACT, ACT \
}

/*
    Generate a solid lightmap for all keys.

    Example
    ---
    ```
    const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
        [DVORAK] = LIGHTMAP_ZONES(AF_BLUE),
    };
    ```
*/
#define LIGHTMAP_ALL(ALL) { \
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
