#include "Commands.h"
extern Command_Struct inputCommand;
extern Pid_Regulator_Struct_Typedef tempRegulatorHot;
extern Pid_Regulator_Struct_Typedef tempRegulatorCold;
	
void checkCommandAndExecute()
{
	if (inputCommand.status == 0x00)
	{
		// No command
		return;
	}
	switch (inputCommand.command)
	{
		case ECHO:
		{
			if (inputCommand.numberOfreceivedParams != 0x04)
				break;
			if (!((inputCommand.params[0] == 'E') && (inputCommand.params[1] == 'C') 
				&& (inputCommand.params[2] == 'H') && (inputCommand.params[3] == 'O')))
				break;
			uint8_t* answer = (uint8_t*)&"ECHO";
			sendAnswer(inputCommand.command, answer, 0x04);
			break;
		}
		case GET_TEMP:
		{
			if (inputCommand.numberOfreceivedParams != 0x01)
				break;
			uint8_t numberOfSensor = inputCommand.params[0];
			if (numberOfSensor > 7)
				break;
			float answer = tempSensors.temperatures[numberOfSensor];
			sendAnswer(inputCommand.command, (__packed uint8_t*)&answer, 0x04);
			break;
		}
		case GET_VOLTAGE:
		{
			if (inputCommand.numberOfreceivedParams != 0x01)
				break;
			uint8_t numberOfSensor = inputCommand.params[0];
			if (numberOfSensor > 1)
				break;
			float answer = voltagesADC[numberOfSensor];
			sendAnswer(inputCommand.command, (__packed uint8_t*)&answer, 0x04);
			break;
		}
		case SET_HOT_TARGET_TEMP:
		{
			if (inputCommand.numberOfreceivedParams != 0x04)
				break;
			tempRegulatorHot.target = *(__packed float*)(inputCommand.params);
			tempRegulatorHot.pidOn = 0x01;
			uint8_t* answer = (uint8_t*)&"OK";
			sendAnswer(inputCommand.command, answer, 0x02);
			break;
		}
		case SET_COLD_TARGET_TEMP:
		{
			if (inputCommand.numberOfreceivedParams != 0x04)
				break;
			tempRegulatorCold.target = *(__packed float*)(inputCommand.params);
			tempRegulatorCold.pidOn = 0x01;
			uint8_t* answer = (uint8_t*)&"OK";
			sendAnswer(inputCommand.command, answer, 0x02);
			break;
		}
		case SET_VAlUE_OF_SHIFT_REG:
		{
			if (inputCommand.numberOfreceivedParams != 0x02)
				break;
			uint16_t value = *(uint16_t*)inputCommand.params;
			shiftRegShiftOut(value);
			uint8_t* answer = (uint8_t*)&"OK";
			sendAnswer(inputCommand.command, answer, 0x02);
			break;
		}
//		case SET_PWM:
//		{
//			if (inputCommand.numberOfreceivedParams != 0x05)
//				break;
//			uint8_t* answer = (uint8_t*)&"OK";
//			sendAnswer(inputCommand.command, answer, 0x02);
//			
//			// Get motor Number and shift it
//			uint8_t  motorNumber = inputCommand.params[0];
//			motorNumber = motorNumber - 1;
//			
//			// Set pwm
//			timPwmChangeDutyCycle(motorPwmCh[motorNumber].timModule,motorPwmCh[motorNumber].channel, *(__packed float*)(inputCommand.params +1));
//			break;
//		}

	}
	// Command is already executed
	inputCommand.status = 0x00;
	return;
}
