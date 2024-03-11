#include <main.h>
#include <TCPInterface.h>

#define WORK_SOCKET 0


extern char OutputBuffer[100];

TCPInterface::TCPInterface()
{

	InputBuffer = new uint8_t[InputBufferSize];
	InputDataIncommingPointer = InputBuffer;
	InputPackAvailablePointer = InputBuffer;


	EthernetInterface = new W5500InterfaceClass;
	EthernetInterface->SocketCreate();
}

TCPInterface::~TCPInterface()
{
	delete EthernetInterface;
	delete InputBuffer;

}


int TCPInterface::GetDataAvailable()
{
   return 0;
}
int TCPInterface::GetPacksAvailable()
{
   return 0;
}
void TCPInterface::SendData(uint8_t* Data, uint8_t DataSize)
{
    send(0,Data,DataSize);
}
int TCPInterface::RecData()
{

return InputWaitDataSize;
}


MESSAGE TCPInterface::TakeCurrentMessage()
{
return *InputPackAvailablePointer;
}

//==============================================================

int W5500InterfaceClass::GetDataFromEthernet(int BytesNumber)
{
       DataReceived = recv(0,(uint8_t*)InputBuffer,10);
	   return DataReceived;
}

W5500InterfaceClass::W5500InterfaceClass()
{

if(W5500InterfaceClass::SocketChannelCounter >= 8) return;

SocketNumber = W5500InterfaceClass::SocketChannelCounter;  //CAN CREATE UP TO EIGHT SOCKETS
W5500InterfaceClass::SocketChannelCounter++;

if(W5500InterfaceClass::InterfaceEstablished) return;

wiz_NetInfo NetParam = { .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0xef},
                            .ip = {192, 168, 3, 178},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 3, 1},
                            .dns = {0, 0, 0, 0},
                            .dhcp = NETINFO_STATIC };
W5500_Init();

W5500InterfaceClass::InterfaceEstablished = true;

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



void W5500InterfaceClass::SocketCreate(int NumberSocket)
{

	int Result = 0;
    Result = socket(NumberSocket, Sn_MR_TCP, PortNumber, 0);

       if(Result != 0)  printf(OutputBuffer, "SOCKET CREATE ERROR: %d \r\n", Result);

    Result = listen(NumberSocket);

	   if(Result != SOCK_OK)  printf(OutputBuffer, "SOCKET LISTEN ERROR: %d \r\n", Result); 

	while(getSn_SR(NumberSocket) == SOCK_LISTEN) { HAL_Delay(2); }


    if(getSn_SR(NumberSocket) != SOCK_ESTABLISHED) printf("ERROR SOCKET STATUS \r\n");

    uint8_t rIP[4];
    getsockopt(NumberSocket, SO_DESTIP, rIP);

		printf("CONNECTION ESTABLISHED \r\n");

		sprintf(OutputBuffer, "IP:  %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]); 
		sprintf(OutputBuffer, "CONNECTION ESTABLISHED");

    send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));

	HAL_Delay(1000);
}

bool W5500InterfaceClass::InterfaceEstablished = false;
bool W5500InterfaceClass::SocketChannelCounter = 0;

//=======================================================
