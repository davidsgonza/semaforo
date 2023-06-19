#include <Arduino.h>
#include "semaforo.h"
#include "reloj.h"



extern int16_t ROJO;
extern int16_t AMARILLO;
extern int16_t VERDE;
extern int16_t tiempo_Exe;

semaforoLEDS ledACTUAL =L_VERDE;
semaforoLEDS ledPASADO =L_ROJO;

/************ FUNCION PARA EL MODO NORMAL DE OPERACION ****************/

void actualizarSemaforo()
{
    
    switch (ledACTUAL)
    {
    case L_VERDE:
        if ( ledPASADO == L_ROJO){
            digitalWrite(VERDE,HIGH);
            digitalWrite(AMARILLO,LOW);
            digitalWrite(ROJO,LOW);
            ledPASADO = ledACTUAL;
            ledACTUAL = L_AMARILLO;
            nbDelay(tiempo_Exe);
        }
        break;
    case L_AMARILLO:
        
        if (ledPASADO == L_VERDE){
            digitalWrite(VERDE,HIGH);
            digitalWrite(AMARILLO,HIGH);
            digitalWrite(ROJO,LOW);
            ledPASADO = ledACTUAL;
            ledACTUAL = L_ROJO;
            nbDelay(tiempo_Exe);
        }
        break;
    case L_ROJO:
        if (ledPASADO == L_AMARILLO){
            digitalWrite(VERDE,LOW);
            digitalWrite(AMARILLO,LOW);
            digitalWrite(ROJO,HIGH);
            ledPASADO = ledACTUAL;
            ledACTUAL = L_VERDE;
            nbDelay(tiempo_Exe);
        }
        break;
    default:
        iniciarSemaforo();
        break;
    }
    Serial.print(ledACTUAL);
}
/************ FIN FUNCION PARA EL MODO NORMAL DE OPERACION ****************/


/*********** FUNCION PARA INICIALIZAR EL SEMAFORO ************/
void iniciarSemaforo(){
    ledACTUAL = L_VERDE;
    ledPASADO = L_ROJO;
}
/******* FIN FUNCION PARA INICIALIZAR EL SEMAFORO ************/

