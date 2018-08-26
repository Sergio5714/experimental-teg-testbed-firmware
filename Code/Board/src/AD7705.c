#include "AD7705.h"

// SPI module
extern SPI_Module_With_State_Typedef SPIModule;

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//
ErrorStatus adcSetNextOperation(ADC_Reg_Typedef reg, ADC_Channel_Typedef channel, ADC_RW_Mode_Typedef rwMode)
{
	uint8_t data = reg << 4 | rwMode << 3 | channel;
	if (spiSendBytes(&SPIModule, &data, 1) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}

ErrorStatus adcWriteClockReg(ADC_Clock_mode_Typedef clockMode, ADC_Clock_Div_Typedef divider, ADC_Update_Typedef updRate)
{
	uint8_t data = clockMode << 4 | divider << 3 | updRate;
	
	// clear ClK bit
	//data &= ~ (1 << 2);
	if (spiSendBytes(&SPIModule, &data, 1) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}

ErrorStatus adcWriteSetupReg(ADC_Mode_Typedef mode, ADC_Gain_Typedef gain, ADC_Polarity_Typedef polarityMode,
                             ADC_Buffer_mode_Typedef bufferMode, ADC_Filter_mode_Typedef filterMode)
{
	uint8_t data = mode << 6 | gain << 3 | polarityMode << 2 | bufferMode << 1 | filterMode;
	if (spiSendBytes(&SPIModule, &data, 1) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}

uint8_t adcCheckDataReady(ADC_Channel_Typedef channel)
{
	if (adcSetNextOperation(ADC_REG_CMM, channel, ADC_READ) != SUCCESS)
	{
		return 0;
	}
	uint8_t data;
	if (spiReadBytes(&SPIModule, &data, 1) != SUCCESS)
	{
		return 0;
	}
	if ((data & 0x80) == 0x0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ErrorStatus adcReadResult(ADC_Channel_Typedef channel, float* outputData)
{
	uint32_t startTime = getLocalTime();
	while (!adcCheckDataReady(channel))
	{
		if (checkTimeout(startTime, ADC_TIMEOUT))
		{
			return ERROR;
		}
	}
	if (adcSetNextOperation(ADC_REG_DATA, channel, ADC_READ) != SUCCESS)
	{
		return ERROR;
	}
	uint8_t shortByte[2];
	if (spiReadBytes(&SPIModule, shortByte, 2) != SUCCESS)
	{
		return ERROR;
	}
	*outputData = (shortByte[0] << 8 | shortByte[1]) * ADC_REFERENCE_VOLTAGE / 65536;
	return SUCCESS;
}

// Init ADC
ErrorStatus adcInit(ADC_Channel_Typedef channel, ADC_Update_Typedef updRate)
{	
	if (adcSetNextOperation(ADC_REG_CLOCK, channel, ADC_WRITE) != SUCCESS)
	{
		return ERROR;
	}
	// Setup clock
	if (adcWriteClockReg(ADC_CLCK_ENABLED, ADC_CLK_DIV_2, updRate) != SUCCESS)
	{
		return ERROR;
	}
	if (adcSetNextOperation(ADC_REG_SETUP, channel, ADC_WRITE) != SUCCESS)
	{
		return ERROR;
	}
	if (adcWriteSetupReg(ADC_MODE_SELF_CAL, GAIN_1, ADC_UNIPOLAR, ADC_BUFFER_DISABLED, ADC_FILTER_SYNC_ENABLED) != SUCCESS)
	{
		return ERROR;
	}
	uint32_t startTime = getLocalTime();
	while (!adcCheckDataReady(channel))
	{
		if (checkTimeout(startTime, ADC_TIMEOUT))
		{
			return ERROR;
		}
	}
	return SUCCESS;
}

// Reset ADC
void adcReset(void)
{
	// Initialization of reset
	gpioInitPin(ADC_RESET_PORT, ADC_RESET_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	
	// Reset condition
	gpioPinSetLevel(ADC_RESET_PORT, ADC_RESET_PIN, GPIO_LEVEL_LOW);
	
	// 0.5 ms
	delayInTenthOfMs(5);
	
	// Quit reset condition
	gpioPinSetLevel(ADC_RESET_PORT, ADC_RESET_PIN, GPIO_LEVEL_HIGH);
	
	// 100 ms
	delayInTenthOfMs(1000);
	
	// CS is enabled
	gpioInitPin(ADC_CS_PORT, ADC_CS_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioPinSetLevel(ADC_CS_PORT, ADC_CS_PIN, GPIO_LEVEL_LOW);
	
	// DRDY is input
	gpioInitPin(ADC_DRDY_PORT, ADC_DRDY_PIN, GPIO_MODE_IN, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_NOPULL);
	
	delayInTenthOfMs(10); // 1 ms
	return;
}
