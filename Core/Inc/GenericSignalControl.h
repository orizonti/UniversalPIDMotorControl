#ifndef GENERICSIGNALCONTROL   _H
#define GENERICSIGNALCONTROL   _H
#include "GenericSignalControl.h"

class GenericSignalControl {

private:
	int OutputValue;

public:
	void SetOutput(int OutputValue);

	GenericSignalControl& operator >>(int OutputValue);

	void reset();
};

#endif
