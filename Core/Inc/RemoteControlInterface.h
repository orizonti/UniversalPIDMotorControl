#ifndef REMOTECONTROLINTERFACE_H
#define REMOTECONTROLINTERFACE_H
#include "DataStructs.h"

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
