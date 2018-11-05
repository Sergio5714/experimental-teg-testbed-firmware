 #include "Shift_reg.h"
 
 //--------------------------------------------- High level functions -------------------------------------------//

// Shift out data
void shiftRegShiftOut(uint16_t value)
{
	uint8_t i;
	//shiftRegClear();
	// Set the latch LOW
	gpioPinSetLevel(SHIFT_REG_LATCH_PORT, SHIFT_REG_LATCH_PIN, GPIO_LEVEL_LOW);
	
	for (i = 0x00; i < SHIFT_REG_NUMBER_OF_OUTPUTS; i++)
	{
		// Set data to serial pin
		if (value & (1 << (SHIFT_REG_NUMBER_OF_OUTPUTS - 1 - i)))
		{
			gpioPinSetLevel(SHIFT_REG_SER_PORT, SHIFT_REG_SER_PIN, GPIO_LEVEL_HIGH);
		}
		else
		{
			gpioPinSetLevel(SHIFT_REG_SER_PORT, SHIFT_REG_SER_PIN, GPIO_LEVEL_LOW);
		}
		// Generate clock impulse
		shiftRegGenClock();
		
	}
	
	// Latch the data
	gpioPinSetLevel(SHIFT_REG_LATCH_PORT, SHIFT_REG_LATCH_PIN, GPIO_LEVEL_HIGH);
	delayInTenthOfMs(2);
	gpioPinSetLevel(SHIFT_REG_LATCH_PORT, SHIFT_REG_LATCH_PIN, GPIO_LEVEL_LOW);
	return;
}

// Generate a clock impulse
static void shiftRegGenClock(void)
{
	delayInTenthOfMs(2);
	gpioPinSetLevel(SHIFT_REG_CLOCK_PORT, SHIFT_REG_CLOCK_PIN, GPIO_LEVEL_HIGH);
	delayInTenthOfMs(2);
	gpioPinSetLevel(SHIFT_REG_CLOCK_PORT, SHIFT_REG_CLOCK_PIN, GPIO_LEVEL_LOW);
	delayInTenthOfMs(2);
	return;
}

// Clear reg
static void shiftRegClear(void)
{
	gpioPinSetLevel(SHIFT_REG_CLR_PORT, SHIFT_REG_CLR_PIN, GPIO_LEVEL_HIGH);
	delayInTenthOfMs(2);
	gpioPinSetLevel(SHIFT_REG_CLR_PORT, SHIFT_REG_CLR_PIN, GPIO_LEVEL_LOW);
	return;
}


// Setup shift register
void shiftRegSetup(void)
{
	// All pins share the same port. Init it
	gpioInitClock(SHIFT_REG_CLOCK_PORT);
	
	// Init pins on open drain pull up mode
	gpioInitPin(SHIFT_REG_CLOCK_PORT, SHIFT_REG_CLOCK_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SHIFT_REG_LATCH_PORT, SHIFT_REG_LATCH_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SHIFT_REG_OE_PORT, SHIFT_REG_OE_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SHIFT_REG_CLR_PORT, SHIFT_REG_CLR_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SHIFT_REG_SER_PORT, SHIFT_REG_SER_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	
	// Turn OE on
	gpioPinSetLevel(SHIFT_REG_OE_PORT, SHIFT_REG_OE_PIN, GPIO_LEVEL_LOW);
	
	// Turn off CLR
	gpioPinSetLevel(SHIFT_REG_CLR_PORT, SHIFT_REG_CLR_PIN, GPIO_LEVEL_HIGH);
	return;

}
