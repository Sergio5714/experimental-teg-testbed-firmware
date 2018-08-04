#ifndef STM32F4_BOARD
#define STM32F4_BOARD

#include "STM32F4_GPIO.h"
#include "STM32F4_TIM.h"
#include "STM32F4_UART.h"
#include "STM32F4_RCC.h"
#include "STM32F4_I2C.h"
#include "STM32F4_EXTI.h"
#include "STM32F4_SPI.h"
#include "Interrupts.h"

//--------------------------------------------- I2C module ---------------------------------------------------//
#define I2C_MODULE                       I2C3
#define I2C_MODULE_EVENT_IRQN            I2C3_EV_IRQn
#define I2C_MODULE_ERROR_IRQN            I2C3_ER_IRQn
#define I2C_MODULE_PIN_AF                GPIO_AF_I2C3
#define I2C_MODULE_SDA_PIN_PORT          GPIOC
#define I2C_MODULE_SDA_PIN_NUMBER        GPIO_Pin_9
#define I2C_MODULE_SCL_PIN_PORT          GPIOA
#define I2C_MODULE_SCL_PIN_NUMBER        GPIO_Pin_8

//--------------------------------------------- USART modules ------------------------------------------------//

#define COM_USART_MODULE                 USART1
#define COM_USART_IRQN                   USART1_IRQn
#define COM_USART_BAUDRATE               250000
#define COM_USART_PIN_AF                 GPIO_AF_USART1
#define COM_USART_TX_PIN_PORT            GPIOB
#define COM_USART_TX_PIN_NUMBER          GPIO_Pin_6
#define COM_USART_RX_PIN_PORT            GPIOB
#define COM_USART_RX_PIN_NUMBER          GPIO_Pin_7

//--------------------------------------------- SPI module --------------------------------------------------//

#define SPI_MODULE                       SPI2
#define SPI_IRQN                         SPI2_IRQHandler
#define SPI_MOSI_PORT                    GPIOB
#define SPI_MOSI_PIN                     GPIO_Pin_15
#define SPI_MISO_PORT                    GPIOB
#define SPI_MISO_PIN                     GPIO_Pin_14
#define SPI_SCLK_PORT                    GPIOB
#define SPI_SCLK_PIN                     GPIO_Pin_13

//--------------------------------------------- LED PWM control  ------------------------------------------//

// ARR = 42000, PSC = 2, fapb1 = 42 MHZ, PWM frequency = 1000 Hz
#define LED_PWM_TIM_MODULE             TIM4
#define LED_PWM_TIM_PSC                0x02
#define LED_PWM_TIM_ARR                0xA410
#define LED_PWM_PIN_AF                 GPIO_AF_TIM4

#define LED_CH1_NUMBER                 0x01
#define LED_CH2_NUMBER                 0x02
#define LED_CH3_NUMBER                 0x03
#define LED_CH4_NUMBER                 0x04

#define LED_CH_PWM_PORT                GPIOD
#define LED_CH1_PWM_PIN                GPIO_Pin_12
#define LED_CH2_PWM_PIN                GPIO_Pin_13
#define LED_CH3_PWM_PIN                GPIO_Pin_14
#define LED_CH4_PWM_PIN                GPIO_Pin_15

//--------------------------------------------- GPIO for LED --------------------------------------------------//
#define COLL_AVOID_LED_PIN               GPIO_Pin_2
#define COLL_AVOID_LED_PORT              GPIOD

//--------------------------------------------- Timer for local time in one tenth of a ms (10000 Hz) ----------//
// ARR = 4200, PSC = 2, fapb1 = 42 MHZ, Frequency = 10000 Hz
#define LOCAL_TIME_TIM_MODULE            TIM7
#define LOCAL_TIME_TIM_PSC               0x02
#define LOCAL_TIME_TIM_ARR               0x1068
#define LOCAL_TIME_IRQN                  TIM7_IRQn
#define LOCAL_TIME_PERIOD                0.0001f


// Initialize all necessary peripheral devices
void boardInitAll(void);

// Indicate error
void showError(void);

// Indicate error
void showNoError(void);

#endif
