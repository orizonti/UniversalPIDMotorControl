#ifndef DEBUGSERIALINTERFACE_H
#define DEBUGSERIALINTERFACE_H

class DebugSerialInterface {

private:
	char OutputBuffer[100];

public:
	void PrintDebug(char* Str);

	void PrintDebug(char* Str, int T_params);
};

#endif
