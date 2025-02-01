#include "pico/stdlib.h"
#include "pico/time.h"
#include "controle_leds.h"
#include "numeros.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "matriz_de_leds.pio.h"
#include <stdlib.h>

#define LED_VERMELHO 11
#define LED_VERDE   12
#define LED_AZUL    13
#define BUTTON_A     5
#define BUTTON_B     6
#define WS2812_GPIO  7
#define DEBOUNCE_DELAY_MS 200

typedef unsigned int uint;

// Variáveis globais para o PIO e state machine
PIO pio_global;
uint sm_global;
uint offset_global;

// Variável para controle do número exibido (0 a 9)
volatile int contador = 0;

// Variáveis para debounce (tempo da última interrupção)
volatile absolute_time_t last_button_a_time = {0};
volatile absolute_time_t last_button_b_time = {0};

// Função para piscar o LED vermelho (5x por segundo)
void piscar_led_vermelho() {
    gpio_put(LED_VERMELHO, 1);
    sleep_ms(100);
    gpio_put(LED_VERMELHO, 0);
    sleep_ms(100);
}

// Configuração dos LEDs RGB
void iniciar_led_rgb() {
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
}

// Rotina de interrupção para os botões com debounce sem bloqueio
void gpio_callback(uint gpio, uint32_t events) {
    absolute_time_t now = get_absolute_time();
    if (gpio == BUTTON_A) {
        if (absolute_time_diff_us(last_button_a_time, now) > DEBOUNCE_DELAY_MS * 1000) {
            last_button_a_time = now;
            if (contador < 9) contador++;
            exibir_numero(contador);
        }
    } else if (gpio == BUTTON_B) {
        if (absolute_time_diff_us(last_button_b_time, now) > DEBOUNCE_DELAY_MS * 1000) {
            last_button_b_time = now;
            if (contador > 0) contador--;
            exibir_numero(contador);
        }
    }
}

// Configuração dos botões com interrupção
void configurar_botoes() {
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, gpio_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, gpio_callback);
}

int main() {
    stdio_init_all();

    pio_global = pio0;
    sm_global = 0;

    // Define o clock do sistema se necessário
    set_sys_clock_khz(128000, false);

    iniciar_led_rgb();
    configurar_botoes();

    // Inicializa o PIO: adiciona o programa e o configura para os LEDs WS2812
    offset_global = pio_add_program(pio_global, &matriz_de_leds_program);
    matriz_de_leds_program_init(pio_global, sm_global, offset_global, WS2812_GPIO);

    // Exibe o número inicial (0)
    exibir_numero(contador);

    while (true) {
        piscar_led_vermelho();
    }

    return 0;
}
