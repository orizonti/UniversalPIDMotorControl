#ifndef CONTROL_DATA_STRUCTS_H
#define CONTROL_DATA_STRUCTS_H
#include <utility>
#include  <cstdint>


class MESSAGE {

public:
	uint8_t HEAD1;
	uint8_t HEAD2;
	uint8_t DATA_SIZE;
	uint8_t* DATA;
};

class AimingSignalStruct {

private:
	uint8_t* StartSignal;
	uint8_t* EndSignal;
};

class MotorControlCommandStruct {

private:
	uint8_t MotorChannel1;
	int MotorSpeed;
	int MotorMoveDir;
	int MotorMoveStep;
};


class PIDParamStruct {

private:
	float PROP;
	float INT;
	float DIFF;
};

class AimingMonitoringStruct {

private:
	PIDParamStruct PIDParam;
	MotorControlCommandStruct MotorMoveParam;
};

class AimingRegimStruct {

private:
	uint8_t ManualControl;
	uint8_t PIDControlRegim;
	PIDParamStruct PIDParam;
};

#endif
