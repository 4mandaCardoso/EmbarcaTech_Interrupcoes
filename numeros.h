#ifndef NUMEROS_H
#define NUMEROS_H

#include "controle_leds.h"
#include "matriz_de_leds.pio.h"
#include "hardware/pio.h"

// Para utilizar os objetos pio_global e sm_global definidos em Atividade1.c
extern PIO pio_global;
extern uint sm_global;

// Definição das cores (vetores de 25 elementos – TOTAL_LEDS)
double color_red_ativa[TOTAL_LEDS]   = {0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8};

double color_green_ativa[TOTAL_LEDS] = {0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8};

double color_blue_ativa[TOTAL_LEDS]  = {0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8,
                                        0.8, 0.8, 0.8, 0.8, 0.8};

double color_red_desativa[TOTAL_LEDS]  = {0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0};

double color_green_desativa[TOTAL_LEDS]= {0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0};

double color_blue_desativa[TOTAL_LEDS] = {0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0,
                                          0.0, 0.0, 0.0, 0.0, 0.0};

// Definição dos frames dos números (cada vetor com 25 elementos)
uint zero[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0};

uint um[TOTAL_LEDS]     = {0, 0, 1, 0, 0,
                           0, 1, 1, 0, 0,
                           1, 0, 1, 0, 0,
                           0, 0, 1, 0, 0,
                           0, 0, 1, 0, 0};

uint dois[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 0, 0, 0,
                           0, 1, 1, 1, 0};

uint tres[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 1, 1, 1, 0};

uint quatro[TOTAL_LEDS] = {0, 1, 0, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 0, 0, 1, 0};

uint cinco[TOTAL_LEDS]  = {0, 1, 1, 1, 0,
                           0, 1, 0, 0, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 1, 1, 1, 0};

uint seis[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 1, 0, 0, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0};

uint sete[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 0, 0, 1, 0};

uint oito[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0};

uint nove[TOTAL_LEDS]   = {0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 1, 0,
                           0, 1, 1, 1, 0};

void exibir_numero(uint contador) {
    switch (contador) {
        case 0:
            atualizar_matriz(zero, color_red_ativa, color_green_desativa, color_blue_desativa, pio_global, sm_global);
            break;
        case 1:
            atualizar_matriz(um, color_red_desativa, color_green_ativa, color_blue_desativa, pio_global, sm_global);
            break;
        case 2:
            atualizar_matriz(dois, color_red_desativa, color_green_desativa, color_blue_ativa, pio_global, sm_global);
            break;
        case 3:
            atualizar_matriz(tres, color_red_ativa, color_green_ativa, color_blue_ativa, pio_global, sm_global);
            break;
        case 4:
            atualizar_matriz(quatro, color_red_ativa, color_green_desativa, color_blue_desativa, pio_global, sm_global);
            break;
        case 5:
            atualizar_matriz(cinco, color_red_desativa, color_green_ativa, color_blue_desativa, pio_global, sm_global);
            break;
        case 6:
            atualizar_matriz(seis, color_red_desativa, color_green_desativa, color_blue_ativa, pio_global, sm_global);
            break;
        case 7:
            atualizar_matriz(sete, color_red_ativa, color_green_ativa, color_blue_ativa, pio_global, sm_global);
            break;
        case 8:
            atualizar_matriz(oito, color_red_ativa, color_green_desativa, color_blue_desativa, pio_global, sm_global);
            break;
        case 9:
            atualizar_matriz(nove, color_red_desativa, color_green_ativa, color_blue_desativa, pio_global, sm_global);
            break;
        default:
            break;
    }
}

#endif
