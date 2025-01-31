#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do buzzer e dos LEDs
#define buzzer 21
#define LED_G 11
#define LED_B 12
#define LED_R 13

// Definição do número de linhas e colunas do teclado matricial
#define row 4
#define column 4

// Pinos GPIO dispostos segundo linhas e colunas de cima para baixo, esquerda para direita
// Linha 1 = GPIO_4, Linha 2 = GPIO_8...
// Coluna 1 = GPIO_17, Coluna 2 = GPIO_18...
const uint rowPin[row] = {8, 7, 6, 5};
const uint columnPin[column] = {4, 3, 2, 1};

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
                break;
        }

        sleep_ms(100);
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
    gpio_pull_up(columnPin[j]);  // Ativa pull-up
    }

    // Inicializa o buzzer
    gpio_init(buzzer);
    gpio_set_dir(buzzer, GPIO_OUT);
    gpio_put(buzzer, 0);

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
        gpio_put(rowPin[i], 0);  // Ativa a linha atual (nível baixo)

        for (int j = 0; j < column; j++) {
            // Verifica se o botão foi pressionado
            if (!gpio_get(columnPin[j])) {  // Detecta nível baixo (tecla pressionada)
                sleep_ms(50);  // Aguarda para debounce
                if (!gpio_get(columnPin[j])) {  // Confirma a tecla pressionada
                    while (!gpio_get(columnPin[j])) {
                        // Aguarda a tecla ser solta
                    }
                    gpio_put(rowPin[i], 1);  // Desativa a linha
                    return TecladoMatricial[i][j];  // Retorna o caractere pressionado
                }
            }
        }

        gpio_put(rowPin[i], 1);  // Desativa a linha após a verificação
    }

    return '\0';  // Retorna '\0' se nenhuma tecla for pressionada
}


void tocar_buzzer() {
    gpio_put(buzzer, 1);
    sleep_ms(1000);
    gpio_put(buzzer, 0);
}

void acionar_LED_verde(){
    gpio_put(LED_G, 1);
    sleep_ms(1000);
    gpio_put(LED_G, 0);
}


void acionar_LED_azul(){
    gpio_put(LED_B, 1);
    sleep_ms(1000);
    gpio_put(LED_B, 0);
}


void acionar_LED_vermelho(){
    gpio_put(LED_R, 1);
    sleep_ms(1000);   
    gpio_put(LED_R, 0); 
}
