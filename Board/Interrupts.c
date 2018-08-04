#include "Interrupts.h"
extern I2C_Module_With_State_Typedef I2CModule;

// Local time of Robot's operation in ms
uint32_t timeInOneTenthOfMillisecond = 0x00;

// Interrupt handler for I2C errors
void I2C3_ER_IRQHandler()
{
	// Arbitration lost error
	if (READ_BIT(I2C_MODULE->SR1, I2C_SR1_ARLO))
	{
		// Clear bit
		CLEAR_BIT(I2C_MODULE->SR1, I2C_SR1_ARLO);
		I2CModule.status = I2C_ARBITRATION_LOST_ERROR;
		return;
	}	
	// Acknowledge error
	if (READ_BIT(I2C_MODULE->SR1, I2C_SR1_AF))
	{
		// Clear bit
		CLEAR_BIT(I2C_MODULE->SR1, I2C_SR1_AF);
		I2CModule.status = I2C_ACKNOWLEDGE_ERROR;
		return;
	}
	// Bus error(misplaced stop or start condition)
	if (READ_BIT(I2C_MODULE->SR1, I2C_SR1_BERR))
	{
		// Clear bit
		CLEAR_BIT(I2C_MODULE->SR1, I2C_SR1_BERR);
		I2CModule.status = I2C_BUS_ERROR;
		return;
	}
	return;
}

// Interrupt for Local time timer (that counts in ms)
void TIM7_IRQHandler()
{
	if (LOCAL_TIME_TIM_MODULE->SR & TIM_SR_UIF)
	{
		timClearStatusRegisterFlag(LOCAL_TIME_TIM_MODULE, TIM_SR_UIF);
		
		// Increase absolute time by one tenth of a millisecond
		timeInOneTenthOfMillisecond ++;
	}
	 return;
}

//--------------------------------------------- Some funtions for local time calculations --------------------------------------//
uint32_t getLocalTime()
{
	return timeInOneTenthOfMillisecond;
}
uint32_t getTimeDifference(uint32_t startTime)
{
	uint32_t diff;
	// turn off IRQN
	__NVIC_DisableIRQ(LOCAL_TIME_IRQN);
	if (timeInOneTenthOfMillisecond >= startTime)
	{
		diff = (timeInOneTenthOfMillisecond - startTime);
	}
	else
	{
		diff =(0xFFFF - startTime) + timeInOneTenthOfMillisecond;

	}
	// turn IRQN back on
	__NVIC_EnableIRQ(LOCAL_TIME_IRQN);
	return diff;
}
uint8_t checkTimeout(uint32_t startTime, uint32_t timeout)
{
	uint32_t diff = getTimeDifference(startTime);
	if(diff >= timeout)
	{
		// Timeout is exceeded
		return 0x01;
	}
	else
	{
		// Timeout is not exceeded
		return 0x00;	
	}
}
void delayInTenthOfMs(uint16_t delay)
{
	uint32_t startTime = getLocalTime();
	while(!checkTimeout(startTime, delay))
	{
		
	}
	return;
}
