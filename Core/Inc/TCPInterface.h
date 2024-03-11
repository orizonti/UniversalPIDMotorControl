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
static bool InterfaceEstablished;
static int SocketChannelCounter;

 uint8_t SocketNumber = 0;
uint16_t PortNumber   = 2323;

uint8_t DataReceived = 0;

void W5500_Init();
void SocketCreate(int NumberSocket);
int GetDataFromEthernet(int BytesNumber);
};

class TCPInterface {

private:
	uint8_t  InputBufferSize = 200;
	uint8_t  InputWaitDataSize = 0;

	uint8_t* InputDataIncommingPointer;
	uint8_t* InputBuffer;

	uint8_t InputPackAvailableCount = 0;
	MessageIterator InputPackAvailablePointer;

	W5500InterfaceClass* EthernetInterface;

public:
    TCPInterface();
    ~TCPInterface();
	int  GetDataAvailable();
	int  GetPacksAvailable();
	int  RecData();
	void SendData(uint8_t* Data, uint8_t DataSize);

	MESSAGE TakeCurrentMessage();
};





#endif
