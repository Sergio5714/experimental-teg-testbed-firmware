#ifndef AD7705_ADC
 #define AD7705_ADC
#include "stm32f4xx.h"
#include "STM32F4_SPI.h"
#include "STM32F4_GPIO.h"
 
//--------------------------------------------- MACROS ----------------------------------------------------------//
#define ADC_REFERENCE_VOLTAGE   2.5f
#define ADC_TIMEOUT             0x7D0 // 200 ms timeout

// Data ready pin (if low then ready)
#define ADC_DRDY_PORT               GPIOB
#define ADC_DRDY_PIN                GPIO_Pin_12

// Reset pin

#define ADC_RESET_PORT              GPIOE
#define ADC_RESET_PIN               GPIO_Pin_15

// SPI pins
#define ADC_CS_PORT                 GPIOB
#define ADC_CS_PIN                  GPIO_Pin_11
#define ADC_CLK_PORT                
#define ADC_CLK_PIN
#define ADC_MOSI_PORT
#define ADC_MOSI_PIN
#define ADC_MISO_PORT
#define ADC_MISO_PIN


// Registers
// RS2 RS1 RS0
typedef enum
{
	ADC_REG_CMM    = 0x0,  //communication register 8 bit
	ADC_REG_SETUP  = 0x1,  //setup register 8 bit
	ADC_REG_CLOCK  = 0x2,  //clock register 8 bit
	ADC_REG_DATA   = 0x3,  //data register 16 bit, contains conversion result
	ADC_REG_TEST   = 0x4,  //test register 8 bit, POR 0x0
	ADC_REG_NOP    = 0x5,  //no operation
	ADC_REG_OFFSET = 0x6,  //offset register 24 bit
	ADC_REG_GAIN   = 0x7  // gain register 24 bit
}ADC_Reg_Typedef;

// Channel selection
// Ch1 Ch0
typedef enum
{
	ADC_CHN_AIN1   = 0x0,  //AIN1; calibration register pair 0
	ADC_CHN_AIN2   = 0x1  //AIN2; calibration register pair 1	
}ADC_Channel_Typedef;

// Output update rate
// CLK FS1 FS0
typedef enum
{
	ADC_UPDATE_RATE_20  = 0x0, // 20 Hz
	ADC_UPDATE_RATE_25  = 0x1, // 25 Hz
	ADC_UPDATE_RATE_100 = 0x2, // 100 Hz
	ADC_UPDATE_RATE_200 = 0x3, // 200 Hz
	ADC_UPDATE_RATE_50  = 0x4, // 50 Hz
	ADC_UPDATE_RATE_60  = 0x5, // 60 Hz
	ADC_UPDATE_RATE_250 = 0x6, // 250 Hz
	ADC_UPDATE_RATE_500 = 0x7  // 500 Hz
}ADC_Update_Typedef;

// Operating mode options
// MD1 MD0
typedef enum
{
	ADC_MODE_NORMAL         = 0x0, //normal mode
	ADC_MODE_SELF_CAL       = 0x1, //self-calibration
	ADC_MODE_ZERO_SCALE_CAL = 0x2, //zero-scale system calibration, POR 0x1F4000, set FSYNC high before calibration, FSYNC low after calibration
	ADC_MODE_FULL_SCALE_CAL = 0x3  //full-scale system calibration, POR 0x5761AB, set FSYNC high before calibration, FSYNC low after calibration
}ADC_Mode_Typedef;

// Gain setting
typedef enum
{
	GAIN_1 = 0x0,
	GAIN_2 = 0x1,
	GAIN_4 = 0x2,
	GAIN_8 = 0x3,
	GAIN_16 = 0x4,
	GAIN_32 = 0x5,
	GAIN_64 = 0x6,
	GAIN_128 = 0x7
}ADC_Gain_Typedef;

// Polarity
typedef enum
{
	ADC_BIPOLAR  = 0x0,
	ADC_UNIPOLAR = 0x1
}ADC_Polarity_Typedef;

typedef enum
{
	ADC_CLK_DIV_1 = 0x0,
	ADC_CLK_DIV_2 = 0x1
}ADC_Clock_Div_Typedef;

typedef enum
{
	ADC_WRITE = 0x00,
	ADC_READ  = 0x01
}ADC_RW_Mode_Typedef;

typedef enum
{
	ADC_CLCK_ENABLED  = 0x00,
	ADC_CLCK_DISABLED = 0x01
}ADC_Clock_mode_Typedef;

typedef enum
{
	ADC_BUFFER_DISABLED = 0x00,
	ADC_BUFFER_ENABLED  = 0x01
}ADC_Buffer_mode_Typedef;

typedef enum
{
	ADC_FILTER_SYNC_ENABLED  = 0x00,
	ADC_FILTER_SYNC_DISABLED = 0x01
}ADC_Filter_mode_Typedef;

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//
// Set next operation for ADC
ErrorStatus adcSetNextOperation(ADC_Reg_Typedef reg, ADC_Channel_Typedef channel, ADC_RW_Mode_Typedef mode);

// Write to clok register
ErrorStatus adcWriteClockReg(ADC_Clock_mode_Typedef clockMode, ADC_Clock_Div_Typedef divider, ADC_Update_Typedef updRate);

// Write to setup register
ErrorStatus adcWriteSetupReg(ADC_Mode_Typedef mode, ADC_Gain_Typedef gain, ADC_Polarity_Typedef polarityMode,
                             ADC_Buffer_mode_Typedef bufferMode, ADC_Filter_mode_Typedef filterMode);

// Check DRDY flag 
uint8_t adcCheckDataReady(ADC_Channel_Typedef channel);

// Read result of conversion
ErrorStatus adcReadResult(ADC_Channel_Typedef channel, float* outputData);

// Init ADC
ErrorStatus adcInit(ADC_Channel_Typedef channel, ADC_Update_Typedef updRate);

// Reset ADC
void adcReset(void);

#endif

