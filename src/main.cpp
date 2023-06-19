#include <Arduino.h>
#include <stdio.h>
#include "teclas.h"
#include "semaforo.h"
#include "reloj.h"
int16_t SW1 = 34;
int16_t SW2 = 35;


int16_t ROJO = 19;
int16_t AMARILLO = 5;
int16_t VERDE= 4;


int16_t Vled[] ={ROJO, AMARILLO,VERDE};
int16_t len_leds = sizeof(Vled)/sizeof(int16_t);
int16_t Vbotones[] = {SW1, SW2};
int16_t len_button = sizeof(Vbotones)/sizeof(int16_t);

int16_t tecla;
int16_t t_delay = 40;
int fsmButtonState;
int16_t estado = 0;
int16_t tiempo_Exe = 500; 


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
    estado = fsmButtonUpdate(t_delay,tecla, fsmButtonState);
      Serial.println(estado);
      nbDelay(500);
    actualizarSemaforo();
  }
}

