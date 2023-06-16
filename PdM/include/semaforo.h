#include <stdio.h>

#ifndef SEMAFORO_H
#define SEMAFORO_H

enum semaforoLEDS {VERDE, AMARILLO, ROJO};
enum semaforoMODOS{NORMAL, DESCONECTADO, ALARMA};


void iniciarSemaforo();
void actualizarSemaforo(int16_t pinArduino[], int tiempo_Exe);
void modosSEMAFORO(int16_t veces, int16_t pinArduino[], int16_t tiempo_Exe);
bool relojNO (unsigned valor_tiempo);
void controlLED (int16_t pinArduino, int16_t estado);
#endif