#ifndef ROBOT_COMMANDS
#define ROBOT_COMMANDS

#include "Communication.h"
#include "Shift_reg.h"

extern uint32_t timeOfStart;

extern Temp_Sensors_Typedef tempSensors;

extern float voltagesADC[2];

enum
{
	ECHO                          = 0x01,
	GET_TEMP                      = 0x02,
	GET_VOLTAGE                   = 0x03,
	SET_HOT_TARGET_TEMP           = 0x04,
	SET_COLD_TARGET_TEMP          = 0x05,
	SET_VAlUE_OF_SHIFT_REG        = 0x06
};

void checkCommandAndExecute(void);
#endif
