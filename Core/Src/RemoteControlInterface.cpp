#include "RemoteControlInterface.h"

extern "C"
{
#include "W5500ReadWriteInterface.h"
}

extern osMessageQueueId_t QueueMotorControlHandle;
extern osMessageQueueId_t QueueRegimCtrlHandle;
extern osMessageQueueId_t QueueAimingSignalHandle;
extern osMessageQueueId_t QueueMonitoringStateHandle;
extern uint8_t OutputBuffer;


void RemoteControlInterface::INIT_INTERFACE() 
{

}

void RemoteControlInterface::RUN_INTERFACE() 
{
	printf("REMOTE CONTROL WORK \r\n");

	int bytes_rec = 0;
    while(1)
    {
    }

}
