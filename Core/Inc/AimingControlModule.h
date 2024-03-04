#ifndef AIMINGCONTROLMODULE_H
#define AIMINGCONTROLMODULE_H


#include "DataStructs.h"

#include "DataStorageEngine.h"
#include "DebugSerialInterface.h"
#include "GenereicSignalControl.h"
#include "GenericEngineControl.h"
#include "GenericSignalControl.h"
#include "MessageIterator.h"
#include "PID_FilterClass.h"
#include "PWMControlInterface.h"
#include "RemoteControlInterface.h"
#include "VoltageControlInterface.h"

class AimingControlModule {

private:
	PID_FilterClass PIDFilter;
	GenericEngineControl Engine1;
	GenericEngineControl Engine2;
	//xQueueHandle MotorDirectControlQueue;
	AimingMonitoringStruct AimingMonitoringData;
	MotorControlCommandStruct MotorControlCommand;

public:
	void RUN_AIMING_CONTROL();
};

#endif
