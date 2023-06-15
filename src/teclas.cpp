# include <Arduino.h>
# include <stdio.h>
# include "teclas.h"
# include "reloj.h"

extern int fsmButtonState;
extern int16_t LED_GREEN;
extern int16_t LED_YELLOW;
extern int16_t SW1;
extern int16_t SW2;
extern int tecla;
extern int16_t t_delay;

void fsmButtonIni(void){
fsmButtonState = BUTTON_UP;
}


void fsmButtonUpdate(int16_t t_delay,int16_t tecla,int16_t fsmButtonState){
    
  
  buttonPressed(tecla); 
  buttonReleased(tecla);

}





void buttonPressed(int16_t tecla){
switch (fsmButtonState)
{
case BUTTON_DOWN:
   if (digitalRead(tecla)){
      fsmButtonState = BUTTON_RISING;
    }
    break;

  case BUTTON_FALLING:
   if (nbDelay(t_delay))
   {
    if (!digitalRead(tecla)){
      fsmButtonState = BUTTON_DOWN;
      PruebabuttonPressed(tecla);
    }else{
      fsmButtonState = BUTTON_UP;
      
    }
   }
   
    break;
default:
    break;
}

}


void buttonReleased(int16_t tecla){
switch (fsmButtonState)
  {
  case BUTTON_UP:
    if (!digitalRead(tecla)){
      fsmButtonState = BUTTON_FALLING;
    }
    break;  

   case BUTTON_RISING:
   if (nbDelay(t_delay))
   {
    if (digitalRead(tecla)){
      fsmButtonState = BUTTON_UP;
      PruebabuttonNoPressed(tecla);
    }else{
      fsmButtonState = BUTTON_DOWN;
      
    }
   }   
    break;
  default:
    break;
  }

}


void PruebabuttonPressed(int16_t tecla){
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, LOW);
 
}

void PruebabuttonNoPressed(int16_t tecla){
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, HIGH);
}