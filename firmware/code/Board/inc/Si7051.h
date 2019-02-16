#ifndef Si7051_TEMP_SENSOR
 #define Si7051_TEMP_SENSOR
#include "stm32f4xx.h"
#include "STM32F4_I2C.h"
 
//--------------------------------------------- MACROS ----------------------------------------------------------//
#define SI7051_RESOLUTION                14
#define SI7051_ADDRESS                   0x40
#define SI7051_WRITE_USER_REG_1_COMMAND  0xE6
#define SI7051_READ_USER_REG_1_COMMAND   0xE7
#define SI7051_RESET_COMMAND             0xFE
#define SI7051_MEASURE_TEMP_COMMAND      0xF3 // No hold master mode

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//
ErrorStatus beginTempSensor(void);
ErrorStatus setResolutionTempSensor(uint8_t resolution);
ErrorStatus startMeasurementsTempSensor(void);
ErrorStatus resetTempSensor(void);
ErrorStatus readTemperatureFromSensor(float* temperature);

#endif

