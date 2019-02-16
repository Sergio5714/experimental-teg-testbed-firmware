#include "I2C_switcher.h"

// I2C module
extern I2C_Module_With_State_Typedef I2CModule;

//--------------------------------------------- FUNCTIONS ------------------------------------------------------//

// Initialization
void initGpioI2CSwitcher()
{
	// Initialization of A0 A1 A2
	gpioInitPin(I2C_SWITCHER_A_0_PORT, I2C_SWITCHER_A_0_PIN , GPIO_MODE_OUT, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_UP);
	gpioInitPin(I2C_SWITCHER_A_1_PORT, I2C_SWITCHER_A_1_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_UP);
	gpioInitPin(I2C_SWITCHER_A_2_PORT, I2C_SWITCHER_A_2_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_UP);
	
	// Reset pin pulled up ( IC enabled)
	gpioInitPin(I2C_SWITCHER_RESET_PORT, I2C_SWITCHER_RESET_PIN , GPIO_MODE_OUT, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_UP);
	gpioPinSetLevel(I2C_SWITCHER_RESET_PORT, I2C_SWITCHER_RESET_PIN , GPIO_LEVEL_HIGH);
	return;
}

// Switch to particular bus
ErrorStatus switchToBus(uint8_t bus)
{
	uint8_t buf = 0x01 << bus;
	if (I2CSendBytes(&I2CModule, &buf, 0x01, I2C_SWITCHER_SLAVE_ADDRESS) != SUCCESS)
	{
		return ERROR;
	}
	return SUCCESS;
}
