#include "Commands.h"
extern Command_Struct inputCommand;
	
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
