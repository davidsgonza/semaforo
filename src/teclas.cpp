# include <Arduino.h>
# include <stdio.h>
# include "teclas.h"
# include "reloj.h"

extern int fsmButtonState;

extern int16_t SW1;
extern int16_t SW2;
extern int tecla;
extern int16_t t_delay;
int16_t presionado;
void fsmButtonIni(void){
fsmButtonState = BUTTON_UP;
}


int fsmButtonUpdate(int16_t t_delay,int16_t tecla,int16_t fsmButtonState){
      
  presionado = buttonPressed(tecla); 
  presionado = buttonReleased(tecla);
  return presionado;
}





int buttonPressed(int16_t tecla){
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
      return 1;
    }else{
      fsmButtonState = BUTTON_UP;
      
    }
   }
   
    break;
default:
    break;
}

}


int buttonReleased(int16_t tecla){
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
      return 0;
    }else{
      fsmButtonState = BUTTON_DOWN;
      
    }
   }   
    break;
  default:
    break;
  }

}


