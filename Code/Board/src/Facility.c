#include "Facility.h"

Temp_Sensors_Typedef tempSensors;

void tempSensorsStartMeasurements()
{
	uint8_t i;
	for ( i = 0; i < NUMBER_OF_SENSORS; i++)
	{
		if (tempSensors.availability[i] == 1)
		{
			// Switch to appropriate bus
			switchToBus(i);
			
			// Wait for 1 ms
			delayInTenthOfMs(10);
			
			// Start measuremnts
			if (startMeasurementsTempSensor() == ERROR)
			{
				tempSensors.errorFlags[i] = TEMP_SENSOR_ERROR;
			}
			else
			{
				tempSensors.errorFlags[i] = TEMP_SENSOR_MEASURING;
			}
		}
	}
	return;
}
void tempSensorsReadTemperatures()
{
	uint8_t i;
	for ( i = 0; i < NUMBER_OF_SENSORS; i++)
	{
		if (tempSensors.availability[i] == 1)
		{
			// Switch to appropriate bus
			switchToBus(i);
			
			if(readTemperatureFromSensor(&tempSensors.temperatures[i]) == ERROR)
			{
				tempSensors.errorFlags[i] = TEMP_SENSOR_ERROR;
			}
		}
	}
	return;
}

void tempSensorsInit()
{
	tempSensors.availability[5] = 1;
	tempSensors.availability[6] = 1;
	tempSensors.availability[7] = 1;
	
	uint8_t i;
	for ( i = 0; i < NUMBER_OF_SENSORS; i++)
	{
		if (tempSensors.availability[i] == 1)
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
	return;
}

// Init pid regulator
void pidInit(Pid_Regulator_Struct_Typedef* pidRegulator)
{
	pidRegulator->pk = 10.0f;
	pidRegulator->dk = 50.0f;
	pidRegulator->ik = 0.04f;
	pidRegulator->maxOutput = 2.0;
	pidRegulator->minOutput = 0.0;
	pidRegulator->maxSumError = 30;
	pidRegulator->pidErrorEnd = 0.1;
	return;
}
// Calculate PID regulator
void pidCalc(Pid_Regulator_Struct_Typedef* pidRegulator)
{
	float error, difError;
	
	// Calculate error, differential error and sum error
	error = pidRegulator->target - pidRegulator->current;
	difError = error - pidRegulator->prevError;
	pidRegulator->prevError = error;
	pidRegulator->sumError += error;

	// Check sum error for saturation
	if (pidRegulator->sumError > pidRegulator->maxSumError)
		pidRegulator->sumError = pidRegulator->maxSumError;
	if (pidRegulator->sumError < -pidRegulator->maxSumError)
		pidRegulator->sumError = -pidRegulator->maxSumError;
	
	// If regulation is on
	if (pidRegulator->pidOn)
	{
		// Calculate output value
		pidRegulator->output = ((float)(pidRegulator->pk * error)+(pidRegulator->ik * pidRegulator->sumError)+(pidRegulator->dk * difError));

		// Check if value exceeds maximum value
		if (pidRegulator->output > pidRegulator->maxOutput)
		{
		  pidRegulator->output = pidRegulator->maxOutput;
		}
		// Check if value exceeds minimum value
		if (pidRegulator->output < pidRegulator->minOutput)
		{
		  pidRegulator->output = 0;
		}

		// If we reached accuracy of regulation that we need
		if ((pidRegulator->output <= pidRegulator->pidOutputEnd) 
			&&(pidRegulator->output >= -pidRegulator->pidOutputEnd) 
			&&(error <= pidRegulator->pidErrorEnd) && (error >= -pidRegulator->pidErrorEnd))
		{
		  pidRegulator->pidFinish = 0x01;
		}
		else
		{
		  pidRegulator->pidFinish = 0x00;
		}
	}
	else
	{
		pidRegulator->output = 0x00;
		pidRegulator->pidFinish = 0x00;
	}
	return;
}
