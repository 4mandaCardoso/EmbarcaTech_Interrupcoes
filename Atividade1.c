#include "pico/stdlib.h"
#include "controle_leds.h"
#include "hardware/pio.h"
#include "numeros.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/adc.h"
//Arquivo .pio
#include "matriz_de_leds.pio.h"

#define LED_VERMELHO 11
#define LED_VERDE 12
#define LED_AZUL 13
#define BUTTON_A 5
#define BUTTON_B 6
#define WS2812_GPIO 7
#define DEBOUNCE_DELAY 200
typedef unsigned int uint;
// Variáveis globais para controle dos números exibidos na matriz de LEDs
uint numeros[25] = {0};
double red[25], green[25], blue[25];

// Variáveis de controle dos botões
volatile bool button_a_pressed = false;
volatile bool button_b_pressed = false;
int contador;

// Pisca o LED vermelho 5x por segundo
void piscar_led_vermelho() {
    gpio_put(LED_VERMELHO, 1);
    sleep_ms(100);
    gpio_put(LED_VERMELHO, 0);
    sleep_ms(100);
}

// Configura os LEDs RGB
void iniciar_led_rgb() {
    gpio_init(LED_VERMELHO);
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
}


// Configura o botão A com interrupção
void configurar_botao_a() {
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);  // Resistor de pull-up interno
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao_a);
}

// Configura o botão B com interrupção
void configurar_botao_b() {
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);  // Resistor de pull-up interno
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao_b);
}

// Interrupção do botão A
void interrupcao_botao_a(uint gpio, uint32_t events) {
    if (!button_a_pressed) {
        button_a_pressed = true;
        if (contador < 9) {  // Limite máximo de 9
            contador++;
        }
        sleep_ms(DEBOUNCE_DELAY);  // Debouncing
        button_a_pressed = false;
        exibir_numero(contador);  // Atualiza a exibição do número
    }
}


// Interrupção do botão B
void interrupcao_botao_b(uint gpio, uint32_t events) {
    if (!button_b_pressed) {
        button_b_pressed = true;
    if (contador > 0) {  // Limite mínimo de 0
            contador--;}
        sleep_ms(DEBOUNCE_DELAY);  // Debouncing
        button_b_pressed = false;
       exibir_numero(contador);  // Atualiza a exibição do número
    }
}

int main() {
    stdio_init_all();
    PIO pio = pio0; 
    bool ok;
    uint16_t i;
    uint32_t valor_led;
    
    // Iniciar LEDs RGB e configurar GPIOs
    iniciar_led_rgb();

    // Configurar o botão A e B com interrupções
    configurar_botao_a();
    configurar_botao_b();
    
    // Inicializar os LEDs WS2812
    PIO pio = pio0;
    uint sm = 0;
    iniciar_pio(pio, sm, WS2812_GPIO);

    // Piscar LED vermelho 5x por segundo
    while (true) {
        piscar_led_vermelho();
        interrupcao_botao_a();
        interrupcao_botao_b();
    }

    return 0;
}
