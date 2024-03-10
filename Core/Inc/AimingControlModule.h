#ifndef AIMINGCONTROLMODULE_H
#define AIMINGCONTROLMODULE_H


#include "ControlDataStructs.h"

#include "DataStorageEngine.h"
#include "DebugSerialInterface.h"
#include "GenericSignalControl.h"
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
	AimingMonitoringStruct AimingMonitoringData;
	MotorControlCommandStruct MotorControlCommand;
	AimingSignalStruct AimingSignal;

public:
	void RUN_AIMING_CONTROL();
};

#endif
