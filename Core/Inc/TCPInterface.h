#ifndef TCPINTERFACE_H
#define TCPINTERFACE_H
#include "DataStructs.h"
#include "MessageIterator.h"


#include "W5500ReadWriteInterface.h"

class TCPInterface {

private:
	uint8_t InputBufferSize;
	uint8_t InputWaitDataSize;
	uint8_t InputPackAvailableCount;
	MessageIterator InputPackAvailablePointer;
	uint8_t* InputDataIncommingPointer;
	uint8_t* InputBuffer;

public:
	int GetDataAvailable();

	int GetPacksAvailable();

	void SendData(uint8_t Data, uint8_t DataSize);

	int RecData();

	MESSAGE* TakeCurrentMessage();
};



class TCPServerW5500Class
{
public:

char InputBuffer[128];
void W5500_Init();
void W5500_SocketCreate();
void W5500_ServerWork();
};


#endif
