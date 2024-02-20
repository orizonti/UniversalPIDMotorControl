#ifndef MY_CLASS
#define MY_CLASS

#include "W5500ReadWriteInterface.h"


class TCPServerW5500Class
{
public:

char InputBuffer[128];
void W5500_Init();
void W5500_SocketCreate();
void W5500_ServerWork();
};


#endif //MY_CLASS
