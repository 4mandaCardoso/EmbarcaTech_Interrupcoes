#ifndef CONTROLE_LEDS_H
#define CONTROLE_LEDS_H
#include "hardware/pio.h"
#include "pico/stdlib.h"
#define TOTAL_LEDS 25

// Função para converter valores RGB (0 a 1) para um formato de 24 bits (WS2812)
uint32_t definir_cor(double r, double g, double b) {
    unsigned char R = r * 255;
    unsigned char G = g * 255;
    unsigned char B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

// Função para atualizar a matriz de LEDs com base nos números exibidos
void atualizar_matriz(uint *numeros, double *red, double *green, double *blue, uint32_t cor_led, PIO pio, uint sm) {
    for (int16_t i = 0; i < TOTAL_LEDS; i++) {
        cor_led = definir_cor(red[24 - i], green[24 - i], blue[24 - i]);
        if (numeros[24 - i]) {
            pio_sm_put_blocking(pio, sm, cor_led);
        } else {
            pio_sm_put_blocking(pio, sm, 0);
        }
    }
}

#endif
