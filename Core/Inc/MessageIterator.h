#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H
#include "ControlDataStructs.h"

class MessageIterator {

private:
	uint8_t* RawDataMessagePointer;

public:
	MessageIterator operator++();

	MESSAGE operator*();
};

#endif
