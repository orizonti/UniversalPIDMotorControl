#ifndef DATASTORAGEENGINE_H
#define DATASTORAGEENGINE_H
#include "ControlDataStructs.h"

class DataStorageEngine {

private:
	PIDParamStruct PIDParams[10];

public:
	PIDParamStruct GetPIDParam(int Number);

	void LoadPIDParamsFromMemory();
};

#endif
