#ifndef REMOTECONTROLINTERFACE_H
#define REMOTECONTROLINTERFACE_H
#include "ControlDataStructs.h"
#include "cmsis_os.h"
#include "stm32g4xx_hal.h"

class RemoteControlInterface {

private:
	AimingSignalStruct AimingSignal;
	AimingRegimStruct* AimingRegim;
	MotorControlCommandStruct* MotorDirectControl;

public:
	void INIT_INTERFACE();

	void RUN_INTERFACE();
};

#endif
