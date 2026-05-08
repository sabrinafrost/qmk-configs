// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

#undef  RGB_MATRIX_MAXIMUM_BRIGHTNESS
#undef  RGB_MATRIX_FLAG_STEPS

#define RGB_MATRIX_SLEEP // turn off effects when suspended
#define RGB_MATRIX_LED_FLUSH_LIMIT 8 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_FLAG_STEPS { LED_FLAG_ALL, LED_FLAG_KEYLIGHT, LED_FLAG_MODIFIER, LED_FLAG_UNDERGLOW, LED_FLAG_INDICATOR } // Sets the flags which can be cycled through.