#include "Board.h"

// I2C module for rangefinders
extern I2C_Module_With_State_Typedef I2CModule;

// SPI module
extern SPI_Module_With_State_Typedef SPIModule;
					   
// Initialize all necessary peripheral devices
void boardInitAll()
{
	// Structures for initialization of USART modules
	USART_Init_Typedef usartSettings = usartGetInitStruct();
	TIM_Init_Typedef timSettings = timGetInitStruct();
	
	//--------------------------------------------- Clock System -------------------------------------------------// 
	
	// Initialization of Clock system 
	// System Core clock frequency = 168 MHZ, AHB frequency = 168 MHz, APB1 frequency = 42 MHz, APB2 frequency = 84 MHz)
	SystemClockInitHse168Mhz();
	SystemCoreClockUpdate();
	
	//--------------------------------------------- I2C module  --------------------------------------------------//
	// Initialization
	I2CModule.module = I2C_MODULE;
	I2CModule.status = I2C_ACTIVE_MODE;
	I2CInit(&I2CModule);
	
	// Initialization for SDA and SCL pins
	gpioInitPin(I2C_MODULE_SCL_PIN_PORT, I2C_MODULE_SCL_PIN_NUMBER, GPIO_MODE_AF, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_NOPULL);
	gpioInitPinAf(I2C_MODULE_SCL_PIN_PORT, I2C_MODULE_SCL_PIN_NUMBER, I2C_MODULE_PIN_AF);
	gpioInitPin(I2C_MODULE_SDA_PIN_PORT, I2C_MODULE_SDA_PIN_NUMBER, GPIO_MODE_AF, GPIO_OUTPUT_MODE_OD, GPIO_PUPD_NOPULL);
	gpioInitPinAf(I2C_MODULE_SDA_PIN_PORT, I2C_MODULE_SDA_PIN_NUMBER, I2C_MODULE_PIN_AF);
	
	//--------------------------------------------- Usart module for communication ------------------------------//
	// Init usart module
	usartSettings.USART_Baudrate = COM_USART_BAUDRATE;
	usartInit(COM_USART_MODULE, &usartSettings);
	
	// Settings for pins
	// Base Init
	gpioInitPin(COM_USART_TX_PIN_PORT, COM_USART_TX_PIN_NUMBER, GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_UP);
	gpioInitPin(COM_USART_RX_PIN_PORT, COM_USART_RX_PIN_NUMBER, GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_UP);
	
	// Set alternatife function
	gpioInitPinAf(COM_USART_TX_PIN_PORT, COM_USART_TX_PIN_NUMBER, COM_USART_PIN_AF);
	gpioInitPinAf(COM_USART_RX_PIN_PORT, COM_USART_RX_PIN_NUMBER, COM_USART_PIN_AF);
	
	//--------------------------------------------- Usart module for communication ------------------------------//
	// Initialization
	SPIModule.module = SPI_MODULE;
	SPIModule.status = SPI_ACTIVE_MODE;
	spiInit(&SPIModule);
	
	// Settings for pins
	// SCLK, MISO, MOSI initialization
	gpioInitPin(SPI_SCLK_PORT, SPI_SCLK_PIN, GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SPI_MISO_PORT, SPI_MISO_PIN, GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(SPI_MOSI_PORT, SPI_MOSI_PIN, GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	
	gpioInitPinAf(SPI_SCLK_PORT, SPI_SCLK_PIN, GPIO_AF_SPI2);
	gpioInitPinAf(SPI_MISO_PORT, SPI_MISO_PIN, GPIO_AF_SPI2);
	gpioInitPinAf(SPI_MOSI_PORT, SPI_MOSI_PIN, GPIO_AF_SPI2);
	
	//--------------------------------------------- Initialization of PWM channels for LED control --------------//
	
	// Settings for pins
	// Base initialization of PWM pins
	gpioInitPin(LED_CH_PWM_PORT, LED_CH1_PWM_PIN,GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(LED_CH_PWM_PORT, LED_CH2_PWM_PIN,GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(LED_CH_PWM_PORT, LED_CH3_PWM_PIN,GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	gpioInitPin(LED_CH_PWM_PORT, LED_CH4_PWM_PIN,GPIO_MODE_AF, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	
	// Set alternative function for PWM pins
	gpioInitPinAf(LED_CH_PWM_PORT, LED_CH1_PWM_PIN, LED_PWM_PIN_AF);
	gpioInitPinAf(LED_CH_PWM_PORT, LED_CH2_PWM_PIN, LED_PWM_PIN_AF);
	gpioInitPinAf(LED_CH_PWM_PORT, LED_CH3_PWM_PIN, LED_PWM_PIN_AF);
	gpioInitPinAf(LED_CH_PWM_PORT, LED_CH4_PWM_PIN, LED_PWM_PIN_AF);

	// Initialize timer module for PWM
	timSettings.TIM_Period = LED_PWM_TIM_ARR;
	timSettings.TIM_Prescaler = LED_PWM_TIM_PSC;
	timInitBase(LED_PWM_TIM_MODULE, &timSettings);
	timInitPwm(LED_PWM_TIM_MODULE, &timSettings, (float[4]){0.0, 0.0, 0.0, 0.0}, (uint8_t[4]){0x01, 0x01, 0x01, 0x01});

	//--------------------------------------------- GPIO  LED ----------------------------------------------------//
	gpioInitPin(COLL_AVOID_LED_PORT, COLL_AVOID_LED_PIN, GPIO_MODE_OUT, GPIO_OUTPUT_MODE_PP, GPIO_PUPD_NOPULL);
	
	// Indicate error
	showNoError();
	
	//--------------------------------------------- Local time timer initialization ------------------------------//
	timSettings.TIM_Period = LOCAL_TIME_TIM_ARR;
	timSettings.TIM_Prescaler = LOCAL_TIME_TIM_PSC;
	timInitBase(LOCAL_TIME_TIM_MODULE, &timSettings);
	
	// Update interrupt enable
	timInterruptEnable(LOCAL_TIME_TIM_MODULE, TIM_DIER_UIE);

	//--------------------------------------------- Enable modules -----------------------------------------------//
	
	// Enable USART modules
	usartEnable(COM_USART_MODULE);
	
	// Enable I2C module
	I2CEnable(I2C_MODULE);
	
	// Enable SPI
	spiEnable(&SPIModule);
	
	// Enable timers
	timEnable(LED_PWM_TIM_MODULE);
	
	// Enable Local time timer
	timEnable(LOCAL_TIME_TIM_MODULE);

	// Global enable
	__enable_irq();
	
	
	//--------------------------------------------- Enable interrupts -------------------------------------------//
	// Enable
	__NVIC_EnableIRQ(COM_USART_IRQN);
	__NVIC_EnableIRQ(LOCAL_TIME_IRQN);
	__NVIC_EnableIRQ(I2C_MODULE_ERROR_IRQN);
	
	
	//--------------------------------------------- Set prority -------------------------------------------------//
	// Priority
	__NVIC_SetPriority(COM_USART_IRQN, 0X01);
	__NVIC_SetPriority(LOCAL_TIME_IRQN, 0X02);
	__NVIC_SetPriority(I2C_MODULE_ERROR_IRQN, 0X03);
	
	// Global enable
	__enable_irq();
	return;
}

// Indicate error
void showError(void)
{
	gpioPinSetLevel(COLL_AVOID_LED_PORT, COLL_AVOID_LED_PIN, GPIO_LEVEL_HIGH);
	return;
}

// Indicate error
void showNoError(void)
{
	gpioPinSetLevel(COLL_AVOID_LED_PORT, COLL_AVOID_LED_PIN, GPIO_LEVEL_LOW);
	return;
}
