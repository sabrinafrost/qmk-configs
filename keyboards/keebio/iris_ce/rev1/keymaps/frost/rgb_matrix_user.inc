RGB_MATRIX_EFFECT(per_key_per_layer)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
extern const rgb_t lightmaps[][RGB_MATRIX_LED_COUNT];
    static bool per_key_per_layer(effect_params_t* params) {
        RGB_MATRIX_USE_LIMITS(led_min, led_max);

        for (uint8_t i = led_min; i < led_max; i++) {
            uint8_t layer = get_highest_layer(layer_state);
            rgb_t colour = lightmaps[layer][i];

            // Check if the colour from the referenced layer
            // matches _______ / AF_TRANS. If it does, search
            // the previous layers until a colour is found and
            // pass that colour through.
            // if (layer > 0 && rgb_equal(colour, _______)) {
            //     for (int8_t l = layer - 1; l >= 0; l--) {
            //     // We've reached the last layer and no colour
            //     // was found so we'll just turn it off.
            //     if (l == 0) {
            //         colour = XXXXXXX;
            //         break;
            //     };

            //     // A colour was found so we'll use it and break the loop.
            //     if (!rgb_equal(lightmaps[l][i], _______)) {
            //         colour = lightmaps[l][i];
            //         break;
            //     }
            //     }
            // }

            rgb_matrix_set_color(i, colour.r, colour.g, colour.b);
        }

        return rgb_matrix_check_finished_leds(led_max);
    }

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
