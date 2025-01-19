#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do buzzer e dos LEDs
#define pino_buzzer 10
#define LED_G 11
#define LED_B 12
#define LED_R 13

// Definição do número de linhas e colunas do teclado matricial
#define row 4
#define column 4

// Pinos GPIO dispostos segundo linhas e colunas de cima para baixo, esquerda para direita
// Linha 1 = GPIO_4, Linha 2 = GPIO_8...
// Coluna 1 = GPIO_17, Coluna 2 = GPIO_18...
const uint rowPin[row] = {4, 8, 9, 16};
const uint columnPin[column] = {17, 18, 19, 20};

// Matriz representando os botões do teclado matricial
// Exemplo: 'A' corresponde aos pinos 4 (Linha 1) e 20 (Coluna 4) sendo ligados
const char TecladoMatricial[row][column] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Protótipo de funções a serem utilizadas
void inicializar_pinos();
char ler_teclado_matricial();
void tocar_buzzer();
void acionar_LED_verde();
void acionar_LED_azul();
void acionar_LED_vermelho();

int main()
{
    printf("Controle de GPIO por um teclado matricial - Grupo 4 Subgrupo 3\n");

    stdio_init_all();
    inicializar_pinos();

    printf("Sistema inicializado!\n");
    printf("\nAperte uma tecla: \n\n1 - Aciona LED verde\n2 - Aciona LED azul\n3 - Aciona LED vermelho\n"
    "A - Aciona LEDs verde e azul\nB - Aciona LEDs azul e vermelho\nC - Aciona LEDs verde e vermelho\n"
    "D - Aciona todos os LEDs\n* - Aciona o Buzzer\n\n");

    while (true) {
        char tecla = ler_teclado_matricial();
        switch (tecla){
            case '1':
                acionar_LED_verde();
                printf("LED verde acionado\n");
                break;
            case '2':
                acionar_LED_azul();
                printf("LED azul acionado\n");
                break;
            case '3':
                acionar_LED_vermelho();
                printf("LED vermelho acionado\n");
                break;
            case 'A':
                acionar_LED_verde();
                acionar_LED_azul();
                printf("LEDs verde e azul acionados\n");
                break;
            case 'B':
                acionar_LED_azul();
                acionar_LED_vermelho();
                printf("LEDs azul e vermelho acionados\n");
                break;
            case 'C':
                acionar_LED_verde();
                acionar_LED_vermelho();
                printf("LEDs verde e vermelho acionados\n");
                break;
            case 'D':
                acionar_LED_verde();
                acionar_LED_azul();
                acionar_LED_vermelho();
                printf("Todos os LEDs acionados\n");
                break;
            case '*':
                tocar_buzzer();
                printf("Buzzer acionado\n");
                break;
            default:
                printf("Tecla sem atribuicao");
                break;
        }
    }
}


void inicializar_pinos(){
    // Inicializa os pinos GPIO das linhas
    for (int i = 0; i < row; i++) {
        gpio_init(rowPin[i]);
        gpio_set_dir(rowPin[i], GPIO_OUT);
        gpio_put(rowPin[i], 0); // Na inicialização, os pinos estarão em low
    }

    // Inicializa os pinos GPIO das colunas
    for (int j = 0; j < column; j++) {
        gpio_init(columnPin[j]);
        gpio_set_dir(columnPin[j], GPIO_IN);
        gpio_put(columnPin[j], 0); // Na inicialização, os pinos estarão em low
    }

     // Inicializa o buzzer
    gpio_init(pino_buzzer);
    gpio_set_dir(pino_buzzer, GPIO_OUT);
    gpio_put(pino_buzzer, 0);

    // Inicializa o LED verde
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_put(LED_G, 0);

    // Inicializa o LED azul
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_put(LED_B, 0);

    // Inicializa o LED vermelho
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_put(LED_R, 0);

}


char ler_teclado_matricial() {
    for (int i = 0; i < row; i++) {
        gpio_put(rowPin[i], 1);  // Ativa a linha atual

        for (int j = 0; j < column; j++) {
            if (gpio_get(columnPin[j]) == 1) {  // Se o botão for pressionado
                while (gpio_get(columnPin[j]) == 1);  // Aguarda até a tecla ser liberada
                gpio_put(rowPin[i], 0);  // Desativa a linha
                return TecladoMatricial[i][j];  // Retorna o caractere pressionado
            }
        }

        gpio_put(rowPin[i], 0);  // Desativa a linha após a verificação
    }

    return '\0';  // Se nenhuma tecla for pressionada, retorna um caractere nulo
}



void tocar_buzzer(){

}


void acionar_LED_verde(){

}


void acionar_LED_azul(){

}


void acionar_LED_vermelho(){

}