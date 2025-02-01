#include "pico/stdlib.h"
#include "pico/time.h"
#include "pico/bootrom.h"    
#include "controle_leds.h"
#include "numeros.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/adc.h"
#include "matriz_de_leds.pio.h"
#include <stdlib.h>

#define WS2812_GPIO      7
#define BUTTON_A         5
#define BUTTON_B         6
#define BUT_JSTICK       22
#define LED_VERMELHO     13
#define DEBOUNCE_DELAY_MS 200

typedef unsigned int uint;

// Variáveis de debounce para os botões A e B (usando absolute_time_t)
volatile absolute_time_t last_button_a_time = {0};
volatile absolute_time_t last_button_b_time = {0};

// Variável de debounce para o botão do joystick (em microssegundos)
static volatile uint32_t last_joystick_time = 0;

// Variáveis globais para o PIO e state machine
PIO pio_global;
uint sm_global;
uint offset_global;

// Variável para controle do número exibido (0 a 9)
volatile int contador = 0;

// Função para piscar o LED vermelho (5x por segundo)
void piscar_led_vermelho() {
    gpio_put(LED_VERMELHO, 1);
    sleep_ms(100);
    gpio_put(LED_VERMELHO, 0);
    sleep_ms(100);
}

// Inicializa o LED RGB (neste caso, apenas o LED vermelho em GPIO 13)
void iniciar_led_rgb() {
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
}

// Função de callback unificada para interrupção dos botões
static void gpio_irq_handler(uint gpio, uint32_t events) {
    absolute_time_t now = get_absolute_time();
    uint32_t current_time = to_us_since_boot(now);

    // Botão A: incrementa o contador (até 9)
    if (gpio == BUTTON_A) {
        if (absolute_time_diff_us(last_button_a_time, now) > DEBOUNCE_DELAY_MS * 1000) {
            last_button_a_time = now;
            if (contador < 9) {
                contador++;
                exibir_numero(contador);
            }
        }
    }
    // Botão B: decrementa o contador (até 0)
    else if (gpio == BUTTON_B) {
        if (absolute_time_diff_us(last_button_b_time, now) > DEBOUNCE_DELAY_MS * 1000) {
            last_button_b_time = now;
            if (contador > 0) {
                contador--;
                exibir_numero(contador);
            }
        }
    }
    // Botão do joystick: exibe estado especial e reinicia a placa
    else if (gpio == BUT_JSTICK) {
        // Verifica se passaram pelo menos 200 ms (200000 µs) desde o último evento do joystick
        if (current_time - last_joystick_time > 200000) {
            last_joystick_time = current_time;
            // Exibe o número 10 na matriz de LEDs (estado especial)
            print_number(10, pio_global, sm_global);
            // Aguarda um curto intervalo para a exibição ser percebida
            sleep_ms(100);
            // Reinicia a placa em modo de gravação (reset USB boot)
            reset_usb_boot(0, 0);
        }
    }
}

// Configura os botões com resistores de pull-up e habilita as interrupções
void configurar_botoes() {
    // Configura o botão A
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    // Configura o botão B
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
    // Configura o botão do joystick
    gpio_init(BUT_JSTICK);
    gpio_set_dir(BUT_JSTICK, GPIO_IN);
    gpio_pull_up(BUT_JSTICK);

    // Habilita a interrupção para os botões usando a mesma callback
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, gpio_irq_handler);
    gpio_set_irq_enabled(BUTTON_B, GPIO_IRQ_EDGE_FALL, true);
    gpio_set_irq_enabled(BUT_JSTICK, GPIO_IRQ_EDGE_FALL, true);
}

int main() {
    stdio_init_all();

    pio_global = pio0;
    sm_global = 0;

    // Configura o clock do sistema (128 MHz, se suportado)
    set_sys_clock_khz(128000, false);

    iniciar_led_rgb();
    configurar_botoes();

    // Inicializa o PIO: adiciona o programa e o configura para os LEDs WS2812
    offset_global = pio_add_program(pio_global, &matriz_de_leds_program);
    matriz_de_leds_program_init(pio_global, sm_global, offset_global, WS2812_GPIO);

    // Exibe o número inicial (0) na matriz de LEDs
    exibir_numero(contador);

    // Loop principal: pisca o LED vermelho continuamente (5 vezes por segundo)
    while (true) {
        piscar_led_vermelho();
    }

    return 0;
}
