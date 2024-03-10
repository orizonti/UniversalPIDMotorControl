#ifndef MOTORCONTROLCOMMANDSTRUCT_H
#define MOTORCONTROLCOMMANDSTRUCT_H
#include "ControlDataStructs.h"

class MotorControlCommandStruct {

private:
	uint8_t MotorChannel1;
	int MotorSpeed;
	int MotorMoveDir;
	int MotorMoveStep;
};

#endif
