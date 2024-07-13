#include "gpio.h"

void INVALID()
{
  while(1){
  }
};
void VALID()
{ 
  __asm("NOP")
    ;}

void GPIO_ClockEnable(unsigned int* gpio_x) {
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
           
         *RCC_AHB1ENR|= CLK_GPIO(gpio_x);
}


void GPIO_DeInit(unsigned int * gpio_x)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));

             { *RCC_AHB1RSTR|= CLK_GPIO(gpio_x);
               *RCC_AHB1RSTR&=~CLK_GPIO(gpio_x); }
}



void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
 __assert(__VALID_MODE(Mode));
 __assert(__VALID_TYPE_OUTPUT(typeOutput));
 __assert(__VALID_PIN(pin));
 
 if (Mode == MODE_INPUT)
   {*(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin));
    *(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin+1));}
 
  else if (Mode == MODE_OUTPUT)
   {*(gpio_x + OFFSET_MODER) |= (1<<(2*pin));
    *(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin+1));}
 
  else if (Mode == MODE_ALTERNATE )
   {*(gpio_x + OFFSET_MODER) &=~ (1<<(2*pin));
    *(gpio_x + OFFSET_MODER) |= (1<<(2*pin+1));}  
 
  else if (Mode == MODE_ANALOG )
   {*(gpio_x + OFFSET_MODER) |= (1<<(2*pin));
    *(gpio_x + OFFSET_MODER) |= (1<<(2*pin+1));} 
 
 unsigned int* GPIO_OTYPER = (unsigned int*)((int) gpio_x + OFFSET_OTYPER);
 
 if (typeOutput == PUSH_PULL)
    *(GPIO_OTYPER) &=~ (1<<pin); 
     
  else if (typeOutput == OPEN_DRAIN) 
    *(GPIO_OTYPER) |= (1<<pin); 
 }
 

unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));

unsigned int* GPIO_IDR = (unsigned int*)((int) gpio_x + OFFSET_IDR);

if ((* GPIO_IDR &= (1<<GPIO_Pin)) == 0x00)
  return 0;
 else 
  return 1;
}



unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));

unsigned int* GPIO_IDR = (unsigned int*)((int) gpio_x + OFFSET_IDR);

return * GPIO_IDR;
}


void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));
__assert(__VALID_PIN(GPIO_Pin));
__assert(__VALID_VALUE(BitVal));

unsigned int* GPIO_ODR = (unsigned int*)((int) gpio_x + OFFSET_ODR);

if (BitVal == 0x00)
  *GPIO_ODR &=~ (1<<(GPIO_Pin)) ;
 else *GPIO_ODR |= (1<<GPIO_Pin) ;
}

void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
__assert(__IS_GPIO_ALL_INSTANCE(gpio_x));

unsigned int* GPIO_ODR = (unsigned int*)((int) gpio_x + OFFSET_ODR);

* GPIO_ODR = PortVal;
}