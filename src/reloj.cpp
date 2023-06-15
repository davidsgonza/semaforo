# include <stdio.h>
#include "reloj.h"

int16_t nbDelay(int16_t t_delay){
  int16_t t_base = 1;
  static int16_t count = 0;
  int16_t n_time = t_delay/t_base;
  if (count>=n_time){
    return 1;
  }else{
    count=count+1;
  }
}
