## PROJETO - Interrupção
**(SUB GRUPO 6 - ATIVIDADE DA AULA SÍNCRONA 27/01)**

─────────────────────────────────── ───────────────────────────────────





*idealizadora do projeto:*
**AMANDA CARDOSO LOPES**

─────────────────────────────────── ───────────────────────────────────

## OBJETIVO DO PROJETO

─────────────────────────────────── ───────────────────────────────────

O objetivo deste projeto é consolidar a compreensão dos conceitos relacionados ao uso de interrupções no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab. O projeto envolve a implementação de um sistema de controle de LEDs e botões, aplicando interrupções para resposta rápida e debouncing via software para evitar leituras erradas.



─────────────────────────────────── ───────────────────────────────────

## FUNCIONALIDADES DO PROJETO

─────────────────────────────────── ───────────────────────────────────

1. O LED vermelho do LED RGB deve piscar continuamente 5 vezes por segundo.
2. O botão A incrementa o número exibido na matriz de LEDs cada vez que for pressionado.
3. O botão B decrementa o número exibido na matriz de LEDs cada vez que for pressionado.
4. A matriz de LEDs WS2812 exibe números de 0 a 9, feito pelos leds.
5. EXTRA: Caso se clique no joystick, se entra no modo bootsel




─────────────────────────────────── ───────────────────────────────────

## TECNOLOGIAS UTILIZADAS

─────────────────────────────────── ───────────────────────────────────

- **Linguagem:** C
- **Microcontrolador:** RP2040 (BitDogLab)
- **Componentes:**
  - Matriz de LEDs 5x5 WS2812 (GPIO 7)
  - LED RGB (GPIOs 11, 12 e 13)
  - Botão A (GPIO 5)
  - Botão B (GPIO 6)




─────────────────────────────────── ───────────────────────────────────

## COMO EXECUTAR O PROJETO?

─────────────────────────────────── ───────────────────────────────────

1. **Configuração Inicial:**
   - Clone o repositório do projeto:
     ```sh
     git clone https://github.com/4mandaCardoso/EmbarcaTech_Interrupcoes.git
     ```
   - Abra o código no VS Code ou no ambiente de desenvolvimento de sua preferência.

2. **Compilação e Upload:**
   - Compile o código e gere o arquivo .uf2.
   - Arraste o arquivo .uf2 para o diretório da placa BitDogLab.

3. **Execução:**
   - Pressione os botões A e B para interagir com a matriz de LEDs.
   - Observe a piscagem do LED RGB.




─────────────────────────────────── ───────────────────────────────────

## CONCLUSÃO

─────────────────────────────────── ───────────────────────────────────

Este projeto permitiu a exploração prática das interrupções no microcontrolador RP2040, consolidando o aprendizado sobre debouncing, controle de LEDs e manipulação de entradas digitais. A implementação na BitDogLab foi um desafio enriquecedor, que proporcionou uma experiência prática no uso de técnicas como interrupção e debouncing para a garantia de uma resposta eficiente aos comandos do usuário.




─────────────────────────────────── ───────────────────────────────────

## VÍDEO DO PROJETO

─────────────────────────────────── ───────────────────────────────────

*link:* https://drive.google.com/drive/folders/1Rvlse6CShJNtHR-vX4LIsW58eVneJFcK?usp=drive_link




