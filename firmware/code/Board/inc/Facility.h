#ifndef FACILITY
#define FACILITY

#include "stm32f4xx.h"
#include "Si7051.h"
#include "I2C_switcher.h"
#include "Interrupts.h"

//--------------------------------------------- MACROS ----------------------------------------------------------//
#define NUMBER_OF_SENSORS                     8

#define PERIOD_OF_MEASUREMENTS_TENTH_OF_MS    1000

#define EXP_FILTER_ALPHA                      0.5f

typedef struct
{
	float pk; 
	float ik; 
	float dk; 
	float target; 
	float current; 
	float prevError; 
	float sumError; 
	float maxSumError; 
	float maxOutput;
	float minOutput;
	float output; 
	uint8_t pidOn;
	uint8_t pidFinish;
	float pidErrorEnd;
	float pidOutputEnd;
} Pid_Regulator_Struct_Typedef;

typedef enum
{
	TEMP_SENSOR_ACTIVE_MODE,
	TEMP_SENSOR_MEASURING,
	TEMP_SENSOR_ERROR
}Temp_Sensor_Error_Typedef;

typedef struct
{
	uint8_t availability[NUMBER_OF_SENSORS];
	Temp_Sensor_Error_Typedef errorFlags[NUMBER_OF_SENSORS];
	float temperatures [NUMBER_OF_SENSORS];
	float prevTemperatures [NUMBER_OF_SENSORS];
}Temp_Sensors_Typedef;

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//
void tempSensorsStartMeasurements(void);
void tempSensorsReadTemperatures(void);
void tempSensorsInit(void);
void filterTemperatures(void);

// Init pid regulator
void pidInit(Pid_Regulator_Struct_Typedef* pidRegulator, float k, float d, float i, 
             float minOutput, float maxOutput, float maxSumError);
	
// Calculate PID regulator
void pidCalc(Pid_Regulator_Struct_Typedef* pidRegulator);




#endif
