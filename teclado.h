// teclado.h
#ifndef TECLADO_H
#define TECLADO_H

// Declaração da função
char ler_teclado_matricial();

// Protótipos das funções GPIO (devem ser implementadas em outro lugar)
void set_gpio_low(int pin);
void set_gpio_high(int pin);
int read_gpio(int pin);

#endif
