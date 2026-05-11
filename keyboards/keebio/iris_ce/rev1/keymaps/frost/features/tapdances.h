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

/* TAP DANCE DEFINITIONS */
enum tap_dances {
  TD_MEDIA,
  TD_LAYERS,
  TAP_DANCE_ACTIONS_COUNT,
};

extern tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_COUNT];

void dance_media_finished (tap_dance_state_t *state, void *user_data);
void dance_media_reset (tap_dance_state_t *state, void *user_data);

void dance_layers_finished (tap_dance_state_t *state, void *user_data);
void dance_layers_reset (tap_dance_state_t *state, void *user_data);