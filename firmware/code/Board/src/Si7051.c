#include "Si7051.h"

// I2C module for temperature sensor
extern I2C_Module_With_State_Typedef I2CModule;

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//
ErrorStatus beginTempSensor()
{
	 if (setResolutionTempSensor(SI7051_RESOLUTION) != SUCCESS)
	 {
		 return ERROR;
	 }
	 return SUCCESS;
}
 
ErrorStatus setResolutionTempSensor(uint8_t resolution)
{
	uint8_t buf[2]; 
	buf[0] = SI7051_WRITE_USER_REG_1_COMMAND;
	buf[1] = resolution;
	if (I2CSendBytes(&I2CModule, &buf[0], 0x02, SI7051_ADDRESS) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}
ErrorStatus startMeasurementsTempSensor(void)
{
	uint8_t buf = SI7051_MEASURE_TEMP_COMMAND;
	if (I2CSendBytes(&I2CModule, &buf, 0x01, SI7051_ADDRESS) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}

ErrorStatus resetTempSensor(void)
{
	uint8_t buf = SI7051_RESET_COMMAND;
	if (I2CSendBytes(&I2CModule, &buf, 0x01, SI7051_ADDRESS) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}
ErrorStatus readTemperatureFromSensor(float* temperature)
{
	uint8_t buf[2];
	if (I2CReadBytes(&I2CModule, &buf[0], 0x02, SI7051_ADDRESS) != SUCCESS)
	{
		return ERROR;
	}
	uint16_t tempCode = buf[0]*255 + buf[1];
	*temperature = ((175.72f)*tempCode)/65536 - 46.85f;
	return SUCCESS;
}
