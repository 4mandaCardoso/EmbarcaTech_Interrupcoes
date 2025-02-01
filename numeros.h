
#include "controle_leds.h"
typedef unsigned int uint;

//definição de cores
double color_red_ativa[25] = {0.8, 0.8, 0.8, 0.8, 0.8,
                              0.8, 0.8, 0.8, 0.8, 0.8, 
                              0.8, 0.8, 0.8, 0.8, 0.8,
                              0.8, 0.8, 0.8, 0.8, 0.8,
                              0.8, 0.8, 0.8, 0.8, 0.8};
                            

double color_green_ativa[25] = {0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8, 
                                0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8};

double color_blue_ativa[25] =  {0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8, 
                                0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8,
                                0.8, 0.8, 0.8, 0.8, 0.8};

double color_red_desativa[25] =   {0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0, 
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0};
                            

double color_green_desativa[25] = {0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0, 
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0};

double color_blue_desativa[25] =  {0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0, 
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0,
                                   0.0, 0.0, 0.0, 0.0, 0.0};

// Definindo o frames de numeros
uint zero [25] =    {0, 1, 1, 1, 0,
                     0, 1, 0, 1, 0, 
                     0, 1, 0, 1, 0,
                     0, 1, 0, 1, 0,
                     0, 1, 1, 1, 0};

uint um [25] =      {0, 0, 1, 0, 0,
                     0, 1, 1, 0, 0, 
                     1, 0, 1, 0, 0,
                     0, 0, 1, 0, 0,
                     0, 0, 1, 0, 0};

uint dois[25] =     {0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0, 
                     0, 1, 1, 1, 0,
                     0, 1, 0, 0, 0,
                     0, 1, 1, 1, 0};


uint tres [25] =    {0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0, 
                     0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0,
                     0, 1, 1, 1, 0};


uint quatro [25] =  {0, 1, 0, 1, 0,
                     0, 1, 0, 1, 0, 
                     0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0,
                     0, 0, 0,1, 0};


uint cinco [25] =   {0, 1, 1, 1, 0,
                     0, 1, 0, 0, 0, 
                     0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0,
                     0, 1, 1, 1, 0};


uint seis [25] =    {0, 1, 1, 1, 0,
                     0, 1, 0, 0, 0, 
                     0, 1, 1, 1, 0,
                     0, 1, 0, 1, 0,
                     0, 1, 1, 1, 0};

uint sete [25] =    {0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0, 
                     0, 0, 0, 1, 0,
                     0, 0, 0, 1, 0,
                     0, 0, 0, 1, 0};

uint oito [25] =    {0, 1, 1, 1, 0,
                     0, 1, 0, 1, 0, 
                     0, 1, 1, 1, 0,
                     0, 1, 0, 1, 0,
                     0, 1, 1, 1, 0};

uint nove [25] =    {0, 1, 1, 1, 0,
                     0, 1, 0, 1, 0, 
                     0, 1, 1, 1, 0,
                     0, 0, 0, 1, 0,
                     0, 1, 1, 1, 0};

// Função para exibir o número na tela de LEDs
void exibir_numero(uint contador) {
    
    // Verifica qual número deve ser exibido
    switch (contador) {
        case 1:
           atualizar_matriz(zero, color_red_ativa, color_green_desativa, color_blue_desativa, valor_led, pio, sm);
            break;
        case 2:
           atualizar_matriz(um, color_red_desativa, color_green_ativa, color_blue_desativa, valor_led, pio, sm);
            break;
        case 3:
           atualizar_matriz(dois, color_red_desativa, color_green_desativa, color_blue_ativa, valor_led, pio, sm);
            break;
        case 4:
           atualizar_matriz(tres, color_red_ativa, color_green_ativa, color_blue_ativa, valor_led, pio, sm);
            break;
        case 5:
            atualizar_matriz(quatro, color_red_ativa, color_green_desativa, color_blue_desativa, valor_led, pio, sm);
            break;
        case 6:
           atualizar_matriz(cinco, color_red_desativa, color_green_ativa, color_blue_desativa, valor_led, pio, sm);
            break;
        case 7:
           atualizar_matriz(seis, color_red_desativa, color_green_desativa, color_blue_ativa, valor_led, pio, sm);
            break;
        case 8:
            atualizar_matriz(sete, color_red_ativa, color_green_ativa, color_blue_ativa, valor_led, pio, sm);
            break;
        case 9:
           atualizar_matriz(oito, color_red_ativa, color_green_desativa, color_blue_desativa, valor_led, pio, sm);
            break;
        case 10:
           atualizar_matriz(nove, color_red_desativa, color_green_ativa, color_blue_desativa, valor_led, pio, sm);
            break;

    }
}