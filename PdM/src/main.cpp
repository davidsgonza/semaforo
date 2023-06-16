#include <Arduino.h>
#include "teclas.h"
#include "semaforo.h"

/******************Declaración Pines a usar**************/
// Pines PULSANTES
    int16_t SW1 = 6;
    int16_t SW2 = 7;
//  Pines LEDs
    int16_t LED_GREEN = 2;
    int16_t LED_YELLOW = 3;
    int16_t LED_RED = 4;
/********************************************************/

/***************************************************/
int16_t Vled[] ={LED_GREEN, LED_YELLOW, LED_RED};
int16_t len_leds = sizeof(Vled)/sizeof(int16_t);
int16_t Vbotones[] = {SW1, SW2};
int16_t len_button = sizeof(Vbotones)/sizeof(int16_t);
/*****************************************************/
/******************ZONA DE VARIABLES******************/

int16_t contadorPulsos = 0;
int16_t tiempoEJEC = 1;
int16_t veces = 1;
int16_t veces2 = 1;
bool bandera = true;
/**************************************************/


/******************INICIO DEL SETUP ***********************/
void setup() {
    Serial.begin(9600);
    for (int16_t i=0; i<len_leds;i++) pinMode(Vled[i],OUTPUT);
    for (int16_t i=0; i<len_button;i++) pinMode(Vbotones[i],INPUT);
}
/**********************FIN DEL SETUP***********************/

/********************INICIO LOOP***************************/
void loop() {

    // SW1 CAMBIA MODOS
    // SW2 CAMBIA VELOCIDAD
    if (updateMEF(SW1) && (bandera)){
        Serial.println(veces);
        bandera = false;
    }else if ((!updateMEF(SW1)) && (!bandera)){
        veces = veces+1;
        bandera = true;
        if (veces == 4) veces = 1;
    }
    if (updateMEF(SW2)){
        if (veces2 == 1){
            tiempoEJEC = 2;               // velocidad de x0,5
            
        }else if(veces2 == 2){
            tiempoEJEC = 1;                 // velocidad de x1
        }else if (veces2 == 3){
            tiempoEJEC = 0.5;               // veclodiad x2
            veces2 = 0;
        }
        veces2 = veces2 + 1;
    }   
    
    modosSEMAFORO(veces, Vled, tiempoEJEC);

}
/*********************FIN LOOP*************************/