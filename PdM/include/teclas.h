
#include <stdio.h>
//#include <secuencia.h>

#ifndef TECLAS_H
#define TECLAS_H

//Definicios de los estados de la MEF Button

enum EstadosB {bFALLING, bDOWN, bRISING, bUP};
// Funciones

void buttonPressed(int16_t tecla);
void buttonReleased(int16_t tecla);
bool updateMEF(int16_t boton);
bool botonPresionado(int16_t boton);
#endif