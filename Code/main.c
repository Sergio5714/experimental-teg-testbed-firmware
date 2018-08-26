#include "stm32f4xx.h"
#include "Board.h"
#include "Communication.h"

#include "Si7051.h"
#include "I2C_switcher.h"
#include "AD7705.h"
#include "Facility.h"
#include "Interrupts.h"

// I2C module for temperature sensor
extern I2C_Module_With_State_Typedef I2CModule;

// SPI module
extern SPI_Module_With_State_Typedef SPIModule;

// Time of start of operation
extern uint32_t timeOfStart;

float voltagesADC[2];

Pid_Regulator_Struct_Typedef tempRegulatorHot;
Pid_Regulator_Struct_Typedef tempRegulatorCold;

extern Temp_Sensors_Typedef tempSensors;

uint8_t selector;

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
	tempSensorsInit();
	
	delayInTenthOfMs(1000); // 100 ms
	
	// Initialization of AD7705
	adcReset();
	
	// Init channels of ADC
	adcInit(ADC_CHN_AIN2, ADC_UPDATE_RATE_25);
	adcInit(ADC_CHN_AIN1, ADC_UPDATE_RATE_25);
	
	// Initialization of internal DAC
	dacInit();
	
	
	pidInit(&tempRegulatorHot);
	pidInit(&tempRegulatorCold);
	
	// Enable timer for temp sensors
	timEnable(TEMP_MEASUREMENTS_TIM_MODULE);
	
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
*/		
//		// Start temperature measurements
//		tempSensorsStartMeasurements();
		
//		// Wait for measurements
//		delayInTenthOfMs(1000); // 100 ms
		
		NVIC_DisableIRQ(TEMP_MEASUREMENTS_IRQN);
		if (selector == 0x00)
		{
			adcReadResult(ADC_CHN_AIN1, &voltagesADC[0]);
		}
		else
		{
			adcReadResult(ADC_CHN_AIN2, &voltagesADC[1]);
		}
//		//adcReadResult(ADC_CHN_AIN2, &voltagesADC[1]);
		NVIC_EnableIRQ(TEMP_MEASUREMENTS_IRQN);
//		
		delayInTenthOfMs(300); // 30 ms
	}
}
