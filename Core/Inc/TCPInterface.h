#ifndef TCPINTERFACE_H
#define TCPINTERFACE_H
#include "ControlDataStructs.h"
#include "MessageIterator.h"


#include "W5500ReadWriteInterface.h"

class W5500InterfaceClass
{
public:
W5500InterfaceClass();

wiz_NetInfo NetParam;
bool InterfaceEstablished = false;
int  SocketNumber = 0;

void W5500_Init();
void W5500_SocketCreate();
};

class TCPInterface {

private:
	uint8_t InputBufferSize;
	uint8_t InputWaitDataSize;
	uint8_t InputPackAvailableCount;
	MessageIterator InputPackAvailablePointer;
	uint8_t* InputDataIncommingPointer;
	uint8_t* InputBuffer;

	MESSAGE* CurrentMessage ;

public:
	int GetDataAvailable();

	int GetPacksAvailable();

	void SendData(uint8_t Data, uint8_t DataSize);

	int RecData();

	MESSAGE* TakeCurrentMessage();
};





#endif
