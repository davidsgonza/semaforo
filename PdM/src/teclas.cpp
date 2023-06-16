#include <Arduino.h>
#include <math.h>
#include "teclas.h"

EstadosB estadoBOTON = bUP;      //valor de inicial
EstadosB estadoANTERIOR;
extern int16_t BT1;
unsigned long lastDebounceTime = 0;
bool variable = false;

bool botonPresionado(int16_t boton){
  return digitalRead(boton) == LOW;
}

bool updateMEF(int16_t boton){
    switch (estadoBOTON)
    {
    case bUP:
        if (botonPresionado(boton)){
          buttonPressed(1);
          //return 1;
        }
        break;
    case bFALLING:
        if ((millis() -lastDebounceTime) >= 40){
          if (botonPresionado(boton)){
            buttonPressed(2);
            Serial.println("Presionado");
            variable = true;
          }else{
            estadoANTERIOR = estadoBOTON;
            estadoBOTON = bUP;
          }
        }
        break;
    case bDOWN:
        if (!botonPresionado(boton)){
            buttonReleased(1);
        }
        break;    
    case bRISING:
        if ((millis() - lastDebounceTime) >= 40){
          if (!botonPresionado(boton)){
            buttonReleased(2);
            Serial.println("Suelto");
            variable = false;
            //return 0;
          }else{
              estadoANTERIOR = estadoBOTON;
              estadoBOTON = bDOWN;
          }
        }
        //return 1;
        break;
    default:
        estadoANTERIOR = estadoBOTON;
        estadoBOTON = bUP;
        //return 1;
        break;
    }
  return variable;
}


//CUANDO EL BOTÓN ESTÁ PULSADO
void buttonPressed(int16_t tecla){
  if (tecla == 1){
    //Serial.println("UP -> changing");
    lastDebounceTime = millis();
    estadoANTERIOR = estadoBOTON;
    estadoBOTON = bFALLING;
  }else if (tecla == 2){
    lastDebounceTime = 0;
    //Serial.println("boton presionado");
    estadoANTERIOR = estadoBOTON;
    estadoBOTON = bDOWN;
  }
}

//CUANDO EL BOTÓN NO ESTÁ PULSADO
void buttonReleased(int16_t tecla){
  if (tecla == 1){
    lastDebounceTime = millis();
    estadoANTERIOR = estadoBOTON;
    estadoBOTON = bRISING;
  }else if (tecla == 2){
    lastDebounceTime = 0;
    //Serial.println("boton suelto");
    estadoANTERIOR = estadoBOTON;
    estadoBOTON = bUP;
  }
}