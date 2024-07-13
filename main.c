#include "gpio.h"

void Delay(volatile unsigned int nCount)
{
  while(nCount--)
  {
  }
}
int main(void)
{
    GPIO_ClockEnable(GPIO_D);
    
    GPIO_DeInit(GPIO_D);
  
    GPIO_Init(GPIO_D,MODE_OUTPUT,OPEN_DRAIN,8);
    GPIO_Init(GPIO_D,MODE_OUTPUT,OPEN_DRAIN,9);
    
    while(1){
    GPIO_WriteBit(GPIO_D,8,SET_PIN);
    GPIO_WriteBit(GPIO_D,9,SET_PIN);
    Delay(0XFFFFFF);
    GPIO_WriteBit(GPIO_D,8,RESET_PIN);
    GPIO_WriteBit(GPIO_D,9,RESET_PIN);
    Delay(0XFFFFFF);
   
    }
   
    
  
 }