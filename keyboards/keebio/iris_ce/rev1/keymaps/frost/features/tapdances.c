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
#include "./tapdances.h"
#include "../keymap.h"

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  TRIPLE_TAP,
  TRIPLE_HOLD,
  OTHER_TAP,
  OTHER_HOLD,
} td_state_t;

static td_state_t td_state;

tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_COUNT] = {
  [TD_MEDIA]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_media_finished,  dance_media_reset),
  [TD_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_layers_finished, dance_layers_reset),
  };

int cur_dance (tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (state->interrupted || !state->pressed) return SINGLE_TAP;
            return SINGLE_HOLD;
        case 2:
            if (state->interrupted || !state->pressed) return DOUBLE_TAP;
            return DOUBLE_HOLD;
        case 3:
            if (state->interrupted || !state->pressed) return TRIPLE_TAP;
            return TRIPLE_HOLD;
        default:
            if (state->interrupted || !state->pressed) return OTHER_HOLD;
            return OTHER_TAP;
    }
}

/*
 * Simulates AirPod controls for controlling music.
 *  • One tap toggles play / pause.
 *  • Two taps skips to the next track.
 *  • Three taps skips to the previous track.
 */
void dance_media_finished (tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP: register_code(KC_MPLY); break;
        case DOUBLE_TAP: register_code(KC_MNXT); break;
        case TRIPLE_TAP: register_code(KC_MPRV); break;
        default: break;
    }
}

void dance_media_reset (tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP: unregister_code(KC_MPLY); break;
        case DOUBLE_TAP: unregister_code(KC_MNXT); break;
        case TRIPLE_TAP: unregister_code(KC_MPRV); break;
        default: break;
    }
}

/*
 * Jumps to the layer corresponding to the number of taps.
 *  • One tap jumps to the first layer (layer 0).
 *  • One hold momentarily toggles the navigation layer (layer 1).
 *  • Two taps jumps to the second layer (layer 2).
 *  • And so on.
 */
void dance_layers_finished (tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP: layer_move(DVORAK); break;
        case SINGLE_HOLD: layer_on(NAVIGATION); break;
        case DOUBLE_TAP: layer_move(GAMING); break;
        case TRIPLE_TAP: layer_move(SETTINGS); break;
        default: break;
    }
}

void dance_layers_reset (tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_HOLD: layer_off(NAVIGATION); break;
        default: break;
    }
}
