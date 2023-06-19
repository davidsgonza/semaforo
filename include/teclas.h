//Genera la MAQUINA DE ESTADOS

#include <stdio.h>

#ifndef TECLAS_H
#define TECLAS_H

enum estados{BUTTON_FALLING, BUTTON_RISING, BUTTON_DOWN,BUTTON_UP};
enum tecla{t1, t2};


//typedef struct { // estructura para controlar el antirrebote de una tecla
//        int16_t tecla;
//        int16_t delay;        
//}dbn_t;


//void fsmButtonUpdate(void);


int fsmButtonUpdate(int16_t t_delay, int16_t tecla, int16_t fsmButtonState);
void fsmButtonIni(void);
int buttonPressed(int16_t tecla);
int buttonReleased(int16_t tecla);
void PruebabuttonPressed(int16_t tecla);
void PruebabuttonNoPressed(int16_t tecla);

#endif