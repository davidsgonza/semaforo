#include <Arduino.h>
#include <stdio.h>
#include "teclas.h"

int16_t SW1 = 34;
int16_t SW2 = 35;
int16_t SW3 = 32;
int16_t SW4 = 33;

int16_t LED_GREEN = 19;
int16_t LED_YELLOW = 5;
int16_t LED_RED = 4;
int16_t LED_BLUE = 2;

int16_t Vled[] ={LED_GREEN, LED_YELLOW, LED_RED, LED_BLUE};
int16_t len_leds = sizeof(Vled)/sizeof(int16_t);
int16_t Vbotones[] = {SW1, SW2, SW3, SW4};
int16_t len_button = sizeof(Vbotones)/sizeof(int16_t);

int16_t tecla;
int16_t t_delay = 40;
int fsmButtonState;


void setup() {
  //DECLARAMOS INGRESOS Y SALIDAS
    for (int16_t i=0; i<len_leds;i++) pinMode(Vled[i],OUTPUT);
    for (int16_t i=0; i<len_button;i++) pinMode(Vbotones[i],INPUT);

    Serial.begin(9600);
}

void loop() {
  tecla = SW1;  
  fsmButtonIni();
  while(1){
    fsmButtonUpdate(t_delay,tecla, fsmButtonState);
  }
}

