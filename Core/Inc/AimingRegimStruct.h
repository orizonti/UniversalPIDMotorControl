#ifndef AIMINGREGIMSTRUCT_H
#define AIMINGREGIMSTRUCT_H
#include "DataStructs.h"

class AimingRegimStruct {

private:
	uint8_t ManualControl;
	uint8_t PIDControlRegim;
	PIDParamStruct PIDParam;
};

#endif
