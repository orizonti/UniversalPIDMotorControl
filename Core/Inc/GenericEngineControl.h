#ifndef GENERICENGINECONTROL_H
#define GENERICENGINECONTROL_H
#include "GenericSignalControl.h"

class GenericEngineControl {

private:
	GenericSignalControl ControlInterface;

public:
	void PerfromCommand(MotorControlCommandStruct Command);

	void MoveWithVelocity(int Velocity, uint8_t Dir);

	void MoveStep(int StepAmplitude, uint8_t Dir);

	void MotorStop();
};

#endif
