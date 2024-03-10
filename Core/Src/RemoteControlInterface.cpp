#include "RemoteControlInterface.h"

extern "C"
{
#include "W5500ReadWriteInterface.h"
}

extern osMessageQueueId_t QueueMotorControlHandle;
extern osMessageQueueId_t QueueRegimCtrlHandle;
extern osMessageQueueId_t QueueAimingSignalHandle;
extern osMessageQueueId_t QueueMonitoringStateHandle;
uint8_t InputBuffer[100];
extern uint8_t OutputBuffer;

wiz_NetInfo NetParam = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 3, 178},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 3, 1},
                            .dns = {0, 0, 0, 0},
                            .dhcp = NETINFO_STATIC };

void RemoteControlInterface::INIT_INTERFACE() 
{
    W5500_Init(NetParam);
    W5500_SocketCreate();

}

void RemoteControlInterface::RUN_INTERFACE() 
{
	printf("REMOTE CONTROL WORK \r\n");

	int bytes_rec = 0;
    while(1)
    {
          bytes_rec = recv(0,(uint8_t*)InputBuffer,10);

          if(bytes_rec > 0)
          {
          	  sprintf((char*)OutputBuffer, "BYTES REC: %d \r\n", bytes_rec); 
              send(0, (uint8_t*)InputBuffer, bytes_rec);
              HAL_Delay(2);
          }

       //send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));

       //if(SOME_ERROR)
       //{
       //     disconnect(WORK_SOCKET);
       //     close(WORK_SOCKET);
       //     printf("CLOSING SOCKET \r\n");
       //}
    }

}
