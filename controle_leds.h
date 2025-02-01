#ifndef CONTROLE_LEDS_H
#define CONTROLE_LEDS_H

#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "matriz_de_leds.pio.h"

#define TOTAL_LEDS 25

static inline uint32_t definir_cor(double r, double g, double b) {
    unsigned char R = r * 255;
    unsigned char G = g * 255;
    unsigned char B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

static inline void atualizar_matriz(uint *numeros, double *red, double *green, double *blue, PIO pio, uint sm) {
    for (int i = 0; i < TOTAL_LEDS; i++) {
        uint32_t cor_led = definir_cor(red[24 - i], green[24 - i], blue[24 - i]);
        if (numeros[24 - i])
            pio_sm_put_blocking(pio, sm, cor_led);
        else
            pio_sm_put_blocking(pio, sm, 0);
    }
}

#endif
