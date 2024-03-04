#ifndef TCPINTERFACE_H
#define TCPINTERFACE_H

class TCPInterface {

private:
	uint8_t InputBuffer[InputBufferSize];
	uint8_t InputBufferSize;
	uint8_t InputWaitDataSize;
	uint8_t InputPackAvailableCount;
	MessageIterator InputPackAvailablePointer;
	uint8_t* InputDataIncommingPointer;

public:
	int GetDataAvailable();

	int GetPacksAvailable();

	void SendData(uint8_t Data, uint8_t DataSize);

	int RecData();

	Message* TakeCurrentMessage();
};

#endif
