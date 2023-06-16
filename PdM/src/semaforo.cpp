#include <Arduino.h>
#include "semaforo.h"
unsigned long tespera = 0;


//variable que recibe 
//extern int16_t veces = 0;
// VARIABLES PARA ESTADO DE LED
semaforoLEDS ledACTUAL = VERDE;
semaforoLEDS ledPASADO = ROJO;

// VARIABLES PARA MODO DE FUNCIONAMIENTO
semaforoMODOS modoACTUAL = NORMAL;
semaforoMODOS modoPASADO = ALARMA;



//FUNCION PRINCIPAL
void modosSEMAFORO(int16_t veces, int16_t pinArduino[], int16_t tiempo_Exe){

    switch (modoACTUAL)
    {
    case NORMAL:        // EL MODO NORMAL ACTÚA COMO UN SEMÁFORO NORMAL
        if((veces == 1) && (modoPASADO == ALARMA)){
            actualizarSemaforo(pinArduino, tiempo_Exe);
        }
        else if ((veces == 2) && (modoPASADO == ALARMA)){
            modoPASADO = modoACTUAL;
            modoACTUAL = DESCONECTADO;
            for(int16_t i = 0; i<3; i++){
                controlLED(pinArduino[i], LOW);
            }
        }
        break;
    case DESCONECTADO:      //EL MODO DESCONECADO EL LED AMARILLO PARPADEA CADA 500 milisegundos
        if ((veces == 2) && (modoPASADO == NORMAL)){
            //controlLED(pinArduino[2], HIGH)
            if(relojNO(500*tiempo_Exe)){
                controlLED(pinArduino[1], LOW);
            }else{
                controlLED(pinArduino[1], HIGH);
            }
            //funcionar solo led amarillo
        }else if((veces == 3) && (modoPASADO == NORMAL)){
            modoPASADO = modoACTUAL;
            modoACTUAL = ALARMA;
            for(int16_t i = 0; i<3; i++){
                controlLED(pinArduino[i], LOW);
            }
        }
        break;
    
    case ALARMA:        //EL MODO ALARMA ENCIENDE EL LED ROJO PARPADEA CADA SEGUNDO
        if ((veces == 3) && (modoPASADO == DESCONECTADO)){
            if(relojNO(1000*tiempo_Exe)){
                controlLED(pinArduino[2], LOW);
            }else{
                controlLED(pinArduino[2], HIGH);
            }
        }else if((veces == 1) && (modoPASADO == DESCONECTADO)){
            modoPASADO = modoACTUAL;
            modoACTUAL = NORMAL;
            for(int16_t i = 0; i<3; i++){
                controlLED(pinArduino[i], LOW);
            }
        }
        break;
    
    default:
        modoPASADO = ALARMA;
        modoACTUAL = NORMAL;
        break;
    }

}

/************ FUNCION PARA EL MODO NORMAL DE OPERACION ****************/

void actualizarSemaforo(int16_t pinArduino[], int tiempo_Exe)
{
    switch (ledACTUAL)
    {
    case VERDE:
        if ((relojNO(2000*tiempo_Exe)) && (ledPASADO == ROJO)){
            controlLED(pinArduino[0], HIGH);
            controlLED(pinArduino[1], LOW);
            controlLED(pinArduino[2], LOW);
            ledPASADO = ledACTUAL;
            ledACTUAL = AMARILLO;
        }
        break;
    case AMARILLO:
        
        if ((relojNO(500*tiempo_Exe)) && (ledPASADO == VERDE)){
            controlLED(pinArduino[0], HIGH);
            controlLED(pinArduino[1], HIGH);
            controlLED(pinArduino[2], LOW);
            ledPASADO = ledACTUAL;
            ledACTUAL = ROJO;
        }
        break;
    case ROJO:
        if ((relojNO(2000*tiempo_Exe)) && (ledPASADO == AMARILLO)){
            controlLED(pinArduino[0], LOW);
            controlLED(pinArduino[1], LOW);
            controlLED(pinArduino[2], HIGH);
            ledPASADO = ledACTUAL;
            ledACTUAL = VERDE;
        }
        break;
    default:
        iniciarSemaforo();
        break;
    }
}
/************ FIN FUNCION PARA EL MODO NORMAL DE OPERACION ****************/


/*********** FUNCION PARA INICIALIZAR EL SEMAFORO ************/
void iniciarSemaforo(){
    ledACTUAL = VERDE;
    ledPASADO = ROJO;
}
/******* FIN FUNCION PARA INICIALIZAR EL SEMAFORO ************/

/***************** FUNCION DE CONTROL LEDS *******************/
void controlLED (int16_t pinArduino, int16_t estado){
    digitalWrite(pinArduino,estado);
}

/************ FIN FUNCION DE CONTROL LEDS ********************/

/************ FUNCION DE DELAY NO BLOQUEANTE *****************/
bool relojNO (unsigned valor_tiempo){
    static unsigned long tdespues;
    if ((millis() - tdespues) >= valor_tiempo){
        tdespues = millis();
        return true;
    }else{
        return false;
    }
}
/************ FIN FUNCION DE DELAY NO BLOQUEANTE *****************/