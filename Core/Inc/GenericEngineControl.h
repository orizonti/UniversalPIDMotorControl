#ifndef GENERICENGINECONTROL_H
#define GENERICENGINECONTROL_H

class GenericEngineControl {

private:
	GenericSignalControl___ ControlInterface;

public:
	void PerfromCommand(MotorControlCommandStruct Command);

	void MoveWithVelocity(int Velocity, uint8_t Dir);

	void MoveStep(int StepAmplitude, uint8_t Dir);

	void MotorStop();
};

#endif
