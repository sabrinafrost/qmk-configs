#include "shared.h"
#include "ledmap.h"

bool rgb_equal(rgb_t a, rgb_t b) {
    return a.r == b.r && a.g == b.g && a.b == b.b;
}

// Overwrite the blank keycode so we can use it as a pass-through
// colour the same way `KC_TRANS` does for keycodes. This define has
// to come after the keymaps.
#define _______ AF_TRANS
// Same idea, but for LEDs we want to turn off.
#define XXXXXXX AF_NO

const rgb_t PROGMEM lightmaps[][RGB_MATRIX_LED_COUNT] = {
   [DVORAK] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,     
      XXXXXXX, AF_RED,  AF_GOLD, AF_CYAN, AF_GRN,  AF_PURP,                            AF_PURP, AF_GRN,  AF_CYAN, AF_GOLD, AF_RED,  XXXXXXX, 
      AF_CYAN, AF_RED,  AF_GOLD, AF_CYAN, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, AF_CYAN, AF_GOLD, AF_RED,  AF_CYAN,
      AF_CYAN, XXXXXXX, AF_GOLD, AF_CYAN, AF_GRN,  XXXXXXX,                            XXXXXXX, AF_GRN,  AF_CYAN, AF_GOLD, AF_RED,  AF_CYAN,
      AF_CYAN, AF_RED,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_PURP,          AF_PURP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_CYAN,  
                                          AF_CYAN, AF_GRN,  AF_PURP,          AF_PURP, AF_GRN,  AF_CYAN,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX     
   ),

   [NAVIGATION] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, AF_GRN,  AF_GOLD, AF_ORN,  AF_RED,  XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, AF_CYAN, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, AF_CYAN, AF_CYAN, AF_CYAN, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX    
   ),

   [GAMING] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, AF_CYAN, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, AF_CYAN, AF_CYAN, AF_CYAN, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AF_RED,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX    
   ),
   
   [SETTINGS] = LIGHTMAP_KEYS(
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX,    
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                                          XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, AF_GRN,  XXXXXXX,
      XXXXXXX,          XXXXXXX,          XXXXXXX,                                              XXXXXXX,          XXXXXXX,          XXXXXXX
   )
};

/* 
   EMPTY LIGHTMAP LAYER
   --------------------
   Copy this into the array above for a fresh layer.
   Don't forget to add the layer name to the custom_layers enum!
   It should match the respective layer's name in the keymap above.

   [LAYER NAME] = LAYOUT(
      _______,          _______,          _______,                                              _______,          _______,          _______,    
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,          _______, _______, _______,
      _______,          _______,          _______,                                              _______,          _______,          _______,    
   ),
*/
