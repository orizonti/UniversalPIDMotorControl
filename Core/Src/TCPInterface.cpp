#include <main.h>
#include <TCPInterface.h>

#define WORK_SOCKET 0


extern char OutputBuffer[100];



int TCPInterface::GetDataAvailable()
{
   return 0;
}
int TCPInterface::GetPacksAvailable()
{
   return 0;
}
void TCPInterface::SendData(uint8_t Data, uint8_t DataSize)
{

}
int TCPInterface::RecData()
{
       InputWaitDataSize = recv(0,(uint8_t*)InputBuffer,10);

return InputWaitDataSize;
}


MESSAGE* TCPInterface::TakeCurrentMessage()
{
return CurrentMessage;
}

//==============================================================
W5500InterfaceClass::W5500InterfaceClass()
{

if(!this->InterfaceEstablished) 
{
wiz_NetInfo NetParam = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 3, 178},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 3, 1},
                            .dns = {0, 0, 0, 0},
                            .dhcp = NETINFO_STATIC };
W5500_Init();
}


}

void W5500InterfaceClass::W5500_Init()
{
	    printf("W5500 START INIT \r\n");
	    HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin, GPIO_PIN_RESET);
		HAL_Delay(1);
		HAL_GPIO_WritePin(Reset_GPIO_Port, Reset_Pin, GPIO_PIN_SET);
		HAL_Delay(1000);
	    printf("W5500 reset \r\n");

		reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
	    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
	    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);

		uint8_t rx_tx_buff_sizes[] = {2, 2, 2, 2, 2, 2, 2, 2};

	    wizchip_init(rx_tx_buff_sizes, rx_tx_buff_sizes);

	    wizchip_setnetinfo(&NetParam);

		ctlnetwork(CN_SET_NETINFO, (void*) &NetParam);
	    printf("W5500 END INIT \r\n");
		HAL_Delay(1000);
}



void W5500InterfaceClass::W5500_SocketCreate()
{
	int STAT = 0;
	printf("CREATING SOCKET \r\n");
    STAT = socket(WORK_SOCKET, Sn_MR_TCP, 2323, 0);

       if(STAT != WORK_SOCKET) { printf(OutputBuffer, "SOCKET() ERROR: %d \r\n", STAT);}
	   else printf("SOCKET CREATED, CONNECTING \r\n");

    STAT = listen(WORK_SOCKET);

	   if(STAT != SOCK_OK) { printf(OutputBuffer, "LISTEN() ERROR: %d \r\n", STAT); }
       else printf("listen() OK\r\n");

	while(getSn_SR(WORK_SOCKET) == SOCK_LISTEN)
    {
			HAL_Delay(2);
    }

    printf("INPUT CONNECTION \r\n");
    if(getSn_SR(WORK_SOCKET) != SOCK_ESTABLISHED) printf("ERROR SOCKET STATUS \r\n");

    uint8_t rIP[4];
    getsockopt(WORK_SOCKET, SO_DESTIP, rIP);

	printf("CONNECTION ESTABLISHED \r\n");
	printf(OutputBuffer, "IP:  %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]); 

	printf(OutputBuffer, "CONNECTION ESTABLISHED");
    send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));

	HAL_Delay(1000);
}


//=======================================================
