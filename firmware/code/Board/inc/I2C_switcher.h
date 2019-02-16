#ifndef I2C_SWITCHER
 #define I2C_SWITCHER
#include "stm32f4xx.h"
#include "STM32F4_I2C.h"
 
//--------------------------------------------- MACROS ----------------------------------------------------------//
#define I2C_SWITCHER_A_0_PORT               GPIOE
#define I2C_SWITCHER_A_0_PIN                GPIO_Pin_1
#define I2C_SWITCHER_A_1_PORT               GPIOB
#define I2C_SWITCHER_A_1_PIN                GPIO_Pin_9
#define I2C_SWITCHER_A_2_PORT               GPIOC
#define I2C_SWITCHER_A_2_PIN                GPIO_Pin_13

#define I2C_SWITCHER_RESET_PORT             GPIOB
#define I2C_SWITCHER_RESET_PIN              GPIO_Pin_7

#define I2C_SWITCHER_SLAVE_ADDRESS          0x70 // If A0, A1, A2 = 0

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//

// Initialization
void initGpioI2CSwitcher(void);

// Switch to particular bus
ErrorStatus switchToBus(uint8_t busNumber);

#endif

