#ifndef GENERICSIGNALCONTROL_H
#define GENERICSIGNALCONTROL_H

class GenericSignalControl {

private:
	int OutputValue;

public:
	void SetOutput(int OutputValue);

	GenericSignalControl& operator >>(int OutputValue);

	void reset();
};

#endif
