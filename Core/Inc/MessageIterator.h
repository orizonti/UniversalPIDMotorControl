#ifndef MESSAGEITERATOR_H
#define MESSAGEITERATOR_H
#include "MESSAGE.h"

class MessageIterator {

private:
	uint8_t* RawDataMessagePointer;

public:
	MessageIterator operator++();

	MESSAGE operator*();
};

#endif
