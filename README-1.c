/**
  ******************************************************************************
  * @file    PROJET-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    29-04-2024
  *****************************************************************************
/* Includes ------------------------------------------------------------------*/


/**
  * @brief  Enable clock for the gpio_x peripheral.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable (unsigned int * gpio_x)
{
.................
................
}
/**
  * @brief  Deinitializes the gpio_x peripheral registers to their default reset values.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_DeInit(unsigned int * gpio_x)
{
  .......................
.....................    

}

/**
  * @brief  Configure the gpio_x
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  Mode: can be INPUT, OUTPUT, AF or AN
  * @param  typeOutput: can be PP or OD
  * @param  pin: can be 0...15
  * @retval None
  */

void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin)
{
 ....................
....................

 }

  
/**
  * @brief  Reads the specified input port pin.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin:  specifies the port bit to read.
  *   This parameter can be GPIO_Pin_x where x can be (0..15).
  * @retval The input port pin value.
  */
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin)
{
.......................
.......................
}

/**
  * @brief  Reads the specified GPIO input data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval GPIO input data port value.
  */
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x)
{
................
................
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *   This parameter can be one of GPIO_Pin_x where x can be (0..15).
  * @param  BitVal: specifies the value to be written to the selected bit.
  *   This parameter can be one of the BitAction enum values:
  *     @arg Bit_RESET: to clear the port pin
  *     @arg Bit_SET: to set the port pin
  * @retval None
  */
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal)
{
..........
.........
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal)
{
...............
..............
}

/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/
