#ifndef MESSAGE_H
#define MESSAGE_H
#include "DataStructs.h"

class MESSAGE {

public:
	uint8_t HEAD1;
	uint8_t HEAD2;
	uint8_t DATA_SIZE;
	uint8_t* DATA;
};

#endif
