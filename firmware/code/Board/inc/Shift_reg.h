#ifndef SHIFT_REGISTER
 #define I2C_SWITCHER

#include "STM32F4_GPIO.h"
#include "Interrupts.h"
 
//--------------------------------------------- MACROS ----------------------------------------------------------//
#define SHIFT_REG_NUMBER_OF_OUTPUTS        16

#define SHIFT_REG_LATCH_PORT               GPIOC
#define SHIFT_REG_LATCH_PIN                GPIO_Pin_6
#define SHIFT_REG_SER_PORT                 GPIOC
#define SHIFT_REG_SER_PIN                  GPIO_Pin_11
#define SHIFT_REG_CLOCK_PORT               GPIOC
#define SHIFT_REG_CLOCK_PIN                GPIO_Pin_7
#define SHIFT_REG_OE_PORT                  GPIOC
#define SHIFT_REG_OE_PIN                   GPIO_Pin_8
#define SHIFT_REG_CLR_PORT                 GPIOC
#define SHIFT_REG_CLR_PIN                  GPIO_Pin_10

 //--------------------------------------------- High level functions -------------------------------------------//

// Shift out data
void shiftRegShiftOut(uint16_t value);
// Generate a clock impulse
static void shiftRegGenClock(void);
// Clear reg
static void shiftRegClear(void);
// Setup shift register
void shiftRegSetup(void);

#endif

