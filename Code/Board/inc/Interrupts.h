#ifndef STM32F4_INTERRUPTS
#define STM32F4_INTERRUPTS

#include "stm32f4xx.h"
#include "Board.h"
#include "Facility.h"


// Interrupt handler for receiving data from High level (DEBUG_USART_MODULE = USART1)
// This Interrupt is implemented in Communication.c
void USART1_IRQHandler(void);

// Interrupt handler for I2C errors
void I2C3_ER_IRQHandler(void);

// Interrupt for Local time timer (that counts in ms)
void TIM7_IRQHandler(void);

// Interrupt handler for temperature measurements
void TIM8_TRG_COM_TIM14_IRQHandler(void);


//--------------------------------------------- Some funtions for local time calculations --------------------------------------//
uint32_t getLocalTime(void);
uint32_t getTimeDifference(uint32_t startTime);
uint8_t checkTimeout(uint32_t startTime, uint32_t timeout);
void delayInTenthOfMs(uint16_t delay);

#endif
