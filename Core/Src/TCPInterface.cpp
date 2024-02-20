#include <main.h>
#include <TCPInterface.hpp>

#define WORK_SOCKET 0


extern char OutputBuffer[100];

wiz_NetInfo gWIZNETINFO = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 3, 178},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 3, 1},
                            .dns = {0, 0, 0, 0},
                            .dhcp = NETINFO_STATIC };

void TCPServerW5500Class::W5500_Init()
{
	    DebugMessage("W5500 START INIT \r\n");
	    HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
	    DebugMessage("W5500 reset \r\n");

		reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
	    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
	    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);

		uint8_t rx_tx_buff_sizes[] = {2, 2, 2, 2, 2, 2, 2, 2};

	    wizchip_init(rx_tx_buff_sizes, rx_tx_buff_sizes);

	    wizchip_setnetinfo(&gWIZNETINFO);

		ctlnetwork(CN_SET_NETINFO, (void*) &gWIZNETINFO);
	    DebugMessage("W5500 END INIT \r\n");
		HAL_Delay(1000);
}



void TCPServerW5500Class::W5500_SocketCreate()
{
	int STAT = 0;
	DebugMessage("CREATING SOCKET \r\n");
    STAT = socket(WORK_SOCKET, Sn_MR_TCP, 2323, 0);

       if(STAT != WORK_SOCKET) { sprintf(OutputBuffer, "SOCKET() ERROR: %d \r\n", STAT); DebugMessageBuff(); }
	   else DebugMessage("SOCKET CREATED, CONNECTING \r\n");

    STAT = listen(WORK_SOCKET);

	   if(STAT != SOCK_OK) { sprintf(OutputBuffer, "LISTEN() ERROR: %d \r\n", STAT); DebugMessageBuff(); }
       else DebugMessage("listen() OK\r\n");

	while(getSn_SR(WORK_SOCKET) == SOCK_LISTEN)
    {
			HAL_Delay(2);
    }

    DebugMessage("INPUT CONNECTION \r\n");
    if(getSn_SR(WORK_SOCKET) != SOCK_ESTABLISHED) printf("ERROR SOCKET STATUS \r\n");

    uint8_t rIP[4];
    getsockopt(WORK_SOCKET, SO_DESTIP, rIP);

	DebugMessage("CONNECTION ESTABLISHED \r\n");
	sprintf(OutputBuffer, "IP:  %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]); DebugMessageBuff();

	sprintf(OutputBuffer, "CONNECTION ESTABLISHED");
    send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));

	HAL_Delay(1000);
}

void TCPServerW5500Class::W5500_ServerWork()
{
	int bytes_rec = 0;

	DebugMessage("START TCP MESSAGE SERVER \r\n");

    while(1)
    {
          bytes_rec = recv(0,(uint8_t*)InputBuffer,10);

          if(bytes_rec > 0)
          {
          	  sprintf(OutputBuffer, "BYTES REC: %d \r\n", bytes_rec); DebugMessageBuff(); HAL_Delay(10);
          	  DebugMessage(InputBuffer);
              send(0, (uint8_t*)InputBuffer, bytes_rec);
              HAL_Delay(10);
          }

       //send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));
       //HAL_Delay(1000);
    }

	disconnect(WORK_SOCKET);
    close(WORK_SOCKET);
	printf("CLOSING SOCKET \r\n");
}

//=======================================================
