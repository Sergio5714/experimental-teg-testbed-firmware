#ifndef ROBOT_COMMANDS
#define ROBOT_COMMANDS

#include "Communication.h"

extern uint32_t timeOfStart;

enum
{
	ECHO                          = 0x01
};

void checkCommandAndExecute(void);
#endif
