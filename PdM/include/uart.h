#include <stdio.h>

#ifndef UART_H
#define UART_H

void uart_init();
void uart_send_byte(uint8_t data);
uint8_t uart_receive_byte();

#endif  // UART_H