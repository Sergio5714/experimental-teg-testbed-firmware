#include "stm32f4xx.h"
#include "Board.h"
#include "Communication.h"

#include "Si7051.h"
#include "I2C_switcher.h"
#include "AD7705.h"




// I2C module for temperature sensor
extern I2C_Module_With_State_Typedef I2CModule;

// SPI module
extern SPI_Module_With_State_Typedef SPIModule;

// Time of start of operation
extern uint32_t timeOfStart;

float temperature [8];

uint8_t busNumber;

//loat result;
//float dutyCycle;

//float voltageDAC1;
//float voltageDAC2;

void initTempSensors()
{
	uint8_t i;
	for( i = 5; i < 8; i++)
	{
		// Switch to next bus
		switchToBus(i);
		
		// Reset temperature sensor
		resetTempSensor();
		
		delayInTenthOfMs(1000); // 100 ms
		
		// Set resolution for temperature sensor
		beginTempSensor();
	}
}

void dacInit()
{
	// Enable clock for DAC
	RCC->APB1ENR |= RCC_APB1ENR_DACEN;
	
	// GPIO
	gpioInitPin(GPIOA, GPIO_Pin_4, GPIO_MODE_IN, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_NOPULL);
	gpioInitPin(GPIOA, GPIO_Pin_5, GPIO_MODE_IN, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_NOPULL);
	
	// Event Trigger enabled 
	DAC->CR |= DAC_CR_TEN1 | DAC_CR_TEN2;
	
	// Software trigger
	DAC->CR |= DAC_CR_TSEL1 | DAC_CR_TSEL2;
	
	// Enable
	DAC->CR |= DAC_CR_EN1;
	DAC->CR |= DAC_CR_EN2;
}

int main()
{	
	// Init everything 
    boardInitAll();
	
	delayInTenthOfMs(20); // 2 ms
	
	// Init switcher of I2C bus
	initGpioI2CSwitcher();
	
	// Initialize all temperature sensors
	initTempSensors();
	
	delayInTenthOfMs(20); // 2 ms
	
	// Initialization of AD7705
	//adcInit(ADC_CHN_AIN1, ADC_UPDATE_RATE_25);
	
	// Initialization of internal DAC
	//dacInit();
	
	while (1)
	{
		/*
//		adcReadResult(ADC_CHN_AIN1, &result);
//		
//		dutyCycle = result/0.1f;
//		
//		if( dutyCycle > 1.0)
//		{
//			dutyCycle = 1.0;
//		}
//		
//		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, dutyCycle);
//		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_2, 0.0f);
//		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_3, 0.0f);
//		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_4, 0.0f);
//		
//		if (dutyCycle > 0.2)
//		{
//			timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_2, dutyCycle);
//		}
//		if (dutyCycle > 0.4)
//		{
//			timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_3, dutyCycle);
//		}
//		if (dutyCycle > 0.6)
//		{
//			timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_4, dutyCycle);
//		}
//		
//		
//		// DAC
//		
//		DAC->DHR12R1 |= ((uint16_t)((voltageDAC1 / 3.0f) * 4095)) & 0xfff;
//		DAC->DHR12R2 |= ((uint16_t)((voltageDAC2 / 3.0f) * 4095)) & 0xfff;
//		
//		// Software trigger
//		DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1 | DAC_SWTRIGR_SWTRIG2;
//		
*/
		delayInTenthOfMs(300); // 30 ms
		
		for (busNumber = 5; busNumber < 8; busNumber++)
		{
			switchToBus(busNumber);
			delayInTenthOfMs(10); // 1 ms
		
			if (startMeasurementsTempSensor() == ERROR)
			{
				if (checkTimeout(I2CModule.timeOfLastI2CResetMillis, 10000))
				{
					I2CReset(&I2CModule);
					delayInTenthOfMs(300); // 30 ms
				}
			}
			delayInTenthOfMs(1000); // 100 ms
			if(readTemperatureFromSensor(&temperature[busNumber]) == ERROR)
			{
				if (checkTimeout(I2CModule.timeOfLastI2CResetMillis, 10000))
				{
					I2CReset(&I2CModule);
					delayInTenthOfMs(300); // 30 ms
				}
			}
		}
	}
}
