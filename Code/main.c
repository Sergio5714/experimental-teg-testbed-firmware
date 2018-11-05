#include "stm32f4xx.h"
#include "Board.h"
#include "Communication.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "Si7051.h"
#include "I2C_switcher.h"
#include "AD7705.h"
#include "Facility.h"
#include "Interrupts.h"
#include "Shift_reg.h"

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
uint16_t counter;

void taskReadTemps(void * arg)
{
	while(1)
	{
		if (tempSensors.errorFlags[5] == TEMP_SENSOR_MEASURING)
		{
			// Read temperatures
			tempSensorsReadTemperatures();
			// Filter value
			filterTemperatures();
		}
		
		// Start temperature measurements
		tempSensorsStartMeasurements();
		
		tempRegulatorHot.current = tempSensors.temperatures[7];
		
		tempRegulatorCold.current = tempSensors.temperatures[5];
		
		pidCalc(&tempRegulatorHot);
		pidCalc(&tempRegulatorCold);

		// DAC
		DAC->DHR12R2 = ((uint16_t)((tempRegulatorHot.output / 3.0f) * 4095)) & 0xfff;
		DAC->DHR12R1 = ((uint16_t)((tempRegulatorCold.output / 3.0f) * 4095)) & 0xfff;
		
		// Software trigger
		DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1 | DAC_SWTRIGR_SWTRIG2;
		
		vTaskDelay(100);
	}
	vTaskDelete( NULL );
}
void taskCheckFan(void * arg)
{
	while(1)
	{
		float dutyCycle = (tempRegulatorCold.output + tempRegulatorHot.output)/ (tempRegulatorCold.maxOutput + tempRegulatorHot.maxOutput);
		if (dutyCycle > 0.2f)
		{
			timPwmChangeDutyCycle(FAN_PWM_TIM_MODULE, FAN_CH1_NUMBER , 1.0f);
		}
		else
		{
			timPwmChangeDutyCycle(FAN_PWM_TIM_MODULE, FAN_CH1_NUMBER , 0.0f);
		}
		vTaskDelay(10000);
	}
	vTaskDelete( NULL );
}

void taskReadVoltages(void * arg)
{
	while(1)
	{
		if (counter < 2)
		{
			counter++;
		}
		switch(selector)
		{
			case 0x00:
			{
				if(counter < 2)
				{
					float tempValue;
					adcReadResult(ADC_CHN_AIN1, &tempValue);
				}
				else
				{
					adcReadResult(ADC_CHN_AIN1, &voltagesADC[0]);
				}
				counter++;
				break;
			}
			case 0x01:
			{
				if(counter < 2)
				{
					float tempValue;
					adcReadResult(ADC_CHN_AIN2, &tempValue);
				}
				else
				{
					adcReadResult(ADC_CHN_AIN2, &voltagesADC[1]);
				}
				counter++;
				break;
			}
		}
		// Change channel
		if(counter == 5)
		{
			if (selector == 0)
				selector = 1;
			else if (selector == 1)
				selector = 0;
			counter = 0;
		}
		vTaskDelay(50);
	}
	vTaskDelete( NULL );
}


void taskUartProcessing(void * arg)
{
	while (1)
	{
		getPackage();
		checkCommandAndExecute();
		vTaskDelay(20);
	}
	vTaskDelete( NULL );
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

void setup(void)
{
	// Init board perpherial
    boardInitAll();
	
	// Init shift register
	shiftRegSetup();
	
	delayInTenthOfMs(20); // 2 ms
	
	// Init switcher of I2C bus
	initGpioI2CSwitcher();
	
	// Initialize all temperature sensors
	tempSensorsInit();
	
	delayInTenthOfMs(1000); // 100 ms
	
	// Initialization of AD7705
	adcReset();
	
	// Init channels of ADC
	if(adcInit(ADC_CHN_AIN2, ADC_UPDATE_RATE_25) == ERROR)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	};
	if (adcInit(ADC_CHN_AIN1, ADC_UPDATE_RATE_25) == ERROR)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	};
	
	// Initialization of internal DAC
	dacInit();
	
	// Temperature control init
	pidInit(&tempRegulatorHot, 10.0f, 50.0f, 0.04f, 0.0f, 2.0f, 30.0f);
	pidInit(&tempRegulatorCold, -10.0f, -50.0f, -0.04f, 0.0f, 2.0f, 30.0f);
	
	// Enable timer for temp sensors
	//timEnable(TEMP_MEASUREMENTS_TIM_MODULE);	
}

int main()
{	
	// Setup all
	setup();
	
	if (xTaskCreate(taskReadTemps, "Temperature measurements", 128, NULL, 1, NULL) != pdTRUE)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	}
	
	if (xTaskCreate(taskReadVoltages, "Voltage measurements", 128, NULL, 1, NULL) != pdTRUE)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	}
	if (xTaskCreate(taskUartProcessing, "Uart", 128, NULL, 1, NULL) != pdTRUE)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	}
	if (xTaskCreate(taskCheckFan, "Fan", 128, NULL, 1, NULL) != pdTRUE)
	{
		// Error
		timPwmChangeDutyCycle(LED_PWM_TIM_MODULE, TIM_PWM_CHANNEL_1, 0.8);
	}
	vTaskStartScheduler();
	
	while (1)
	{
		
	}
}
