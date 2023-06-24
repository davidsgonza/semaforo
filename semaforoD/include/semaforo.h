//Maquina del semaforo

#include <stdio.h>

#ifndef SEMAFORO_H
#define SEMAFORO_H


enum semaforoLEDS {L_VERDE, L_AMARILLO, L_ROJO};
//enum semaforoMODOS{NORMAL, DESCONECTADO, ALARMA};


void iniciarSemaforo();
void actualizarSemaforo();
//void modosSEMAFORO(int16_t veces, int16_t pinArduino[], int16_t tiempo_Exe);
//bool relojNO (unsigned valor_tiempo);
//void controlLED (int16_t pinArduino, int16_t estado);

#endif