#include <Arduino.h>
#include "uart.h"

#define UART_BAUDRATE 9600
#define UART_SERIAL Serial1  

void uart_init() {
  UART_SERIAL.begin(UART_BAUDRATE);
}

void uart_send_byte(uint8_t data) {
  UART_SERIAL.write(data);
}

uint8_t uart_receive_byte() {
  while (!UART_SERIAL.available());
  return UART_SERIAL.read();
}