//adresses de base des GPIOs :

#define GPIO_A (unsigned int*)(0x40020000)
#define GPIO_B (unsigned int*)(0x40020400)
#define GPIO_C (unsigned int*)(0x40020800)
#define GPIO_D (unsigned int*)(0x40020c00)
#define GPIO_E (unsigned int*)(0x40021000)
#define GPIO_F (unsigned int*)(0x40021400)
#define GPIO_G (unsigned int*)(0x40021800)
#define GPIO_H (unsigned int*)(0x40021c00)
#define GPIO_I (unsigned int*)(0x40022000)



#define CLK_GPIO(gpio_x) ( gpio_x == GPIO_A ? 1 : gpio_x == GPIO_B ? (1<<1) : \
                                          gpio_x == GPIO_C ? (1<<2):   \
                                          gpio_x == GPIO_D ? (1<<3):  \
                                          gpio_x == GPIO_E ? (1<<4):   \
                                          gpio_x == GPIO_F ? (1<<5): \
                                          gpio_x == GPIO_G ? (1<<6): \
                                          gpio_x == GPIO_H ? (1<<7): \
                                          gpio_x == GPIO_I ? (1<<8) : 0)
// offset des registres : 

#define OFFSET_MODER 0x00
#define OFFSET_ODR 0x14
#define OFFSET_IDR 0x10
#define OFFSET_OTYPER 0x04
#define OFFSET_BSRR 0x18
#define OFFSET_RCC_AHB1ENR 0x30
#define OFFSET_RCC_AHB1RSTR 0x10

// adresse debut 
#define RCC_BASE_ADRESS (0x40023800)
#define RCC_AHB1RSTR (unsigned short int*)( RCC_BASE_ADRESS+OFFSET_RCC_AHB1RSTR)
#define RCC_AHB1ENR (unsigned short int*)( RCC_BASE_ADRESS+OFFSET_RCC_AHB1ENR)

// differents modes de fonctionnement : 

#define MODE_INPUT 0x00
#define MODE_OUTPUT 0X01
#define MODE_ALTERNATE 0X10
#define MODE_ANALOG 0X11

// types de sortie  push pull 0x00  opendrain 0x01

#define PUSH_PULL 0
#define OPEN_DRAIN 1


#define SET_PIN 1
#define RESET_PIN 0
// position des pins dans les registres 

#define GPIO_PIN_0 ((unsigned short ) 0x0000
#define GPIO_PIN_1 ((unsigned short) 0x0001
#define GPIO_PIN_2 ((unsigned short) 0x0002
#define GPIO_PIN_3 ((unsigned short) 0x0003
#define GPIO_PIN_4 ((unsigned short) 0x0004
#define GPIO_PIN_5 ((unsigned short) 0x0005
#define GPIO_PIN_6 ((unsigned short) 0x0006
#define GPIO_PIN_7 ((unsigned short) 0x0007
#define GPIO_PIN_8 ((unsigned short int) 0x0008
#define GPIO_PIN_9 ((unsigned short) 0x0009
#define GPIO_PIN_10 ((unsigned short) 0x000A
#define GPIO_PIN_11 ((unsigned short) 0x000B
#define GPIO_PIN_12 ((unsigned short) 0x000C
#define GPIO_PIN_13 ((unsigned short) 0x000D
#define GPIO_PIN_14 ((unsigned short) 0x000E
#define GPIO_PIN_15 ((unsigned short) 0x000F

// mask

//mask PINS
#define MASK_GPIO_PIN0 0x0001
#define MASK_GPIO_PIN1 0x0002
#define MASK_GPIO_PIN2 0x0004
#define MASK_GPIO_PIN3 0x0008
#define MASK_GPIO_PIN4 0x0010
#define MASK_GPIO_PIN5 0x0020
#define MASK_GPIO_PIN6 0x0040
#define MASK_GPIO_PIN7 0x0080
#define MASK_GPIO_PIN8 0x0100
#define MASK_GPIO_PIN9 0x0200 
#define MASK_GPIO_PIN10 0x0400
#define MASK_GPIO_PIN11 0x0800
#define MASK_GPIO_PIN12 0x1000
#define MASK_GPIO_PIN13 0x2000
#define MASK_GPIO_PIN14 0x4000
#define MASK_GPIO_PIN15 0x8000




void INVALID();
void VALID();
#define __assert(e) (e ?  VALID():INVALID())
#define __IS_GPIO_ALL_INSTANCE(INSTANCE) (  ((INSTANCE)== GPIO_A)|| \
                                          ((INSTANCE)== GPIO_B)|| \
                                          ((INSTANCE)== GPIO_C)|| \
                                          ((INSTANCE)== GPIO_D)|| \
                                          ((INSTANCE)== GPIO_E)|| \
                                          ((INSTANCE)== GPIO_F)|| \
                                          ((INSTANCE)== GPIO_G)|| \
                                          ((INSTANCE)== GPIO_H)|| \
                                          ((INSTANCE)== GPIO_I))

#define __VALID_MODE(mode) (  ((mode)== MODE_INPUT)|| \
                              ((mode)== MODE_OUTPUT)|| \
                              ((mode)== MODE_ALTERNATE)|| \
                              ((mode)== MODE_ANALOG))
 
#define __VALID_TYPE_OUTPUT(TypeOutput) (  ((TypeOutput)== PUSH_PULL)|| \
                                           ((TypeOutput)== OPEN_DRAIN))

#define __VALID_VALUE(BitVal) (  ((BitVal)== SET_PIN)|| \
                                 ((BitVal)== RESET_PIN))
#define __VALID_PIN(pin) ((pin) <16 )


//functions
void GPIO_ClockEnable(unsigned int* gpio_x);
void GPIO_DeInit(unsigned int * gpio_x);
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin);
unsigned  char GPIO_ReadInputDataBit(unsigned int *  gpio_x, unsigned  short int GPIO_Pin);
unsigned  short int GPIO_ReadInputData(unsigned int *  gpio_x);
void GPIO_WriteBit(unsigned int * gpio_x, unsigned  short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned  short int PortVal);