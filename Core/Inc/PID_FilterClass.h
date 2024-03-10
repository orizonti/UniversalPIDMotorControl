#ifndef PID_FILTERCLASS_H
#define PID_FILTERCLASS_H
#include "ControlDataStructs.h"
#include <utility>

class PID_FilterClass {

private:
	PIDParamStruct PIDParam;
	std::pair<uint16_t, uint16_t> OutputCoord;

public:
	void SetCoord(std::pair<uint16_t, uint16_t>& Coord);

	void GetCoord(std::pair<uint16_t, uint16_t>& Coord);

	void SetParam(PIDParamStruct PIDParam);
};

#endif
