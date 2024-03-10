/*
 * W5500ReadWriteInterface.c
 *
 *  Created on: Feb 21, 2024
 *      Author: broms
 */
#include "main.h"
#include "W5500ReadWriteInterface.h"

//#include "DebugSerialInterface.h"

extern char OutputBuffer[128];
extern char InputBuffer[128];
//
extern SPI_HandleTypeDef hspi1;
extern UART_HandleTypeDef huart1;

void W5500_Select(void)
{
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);

}

void W5500_Unselect(void)
{
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Receive(&hspi1, buff, len, HAL_MAX_DELAY);
}

void W5500_WriteBuff(uint8_t* buff, uint16_t len)
{
    HAL_SPI_Transmit(&hspi1, buff, len, HAL_MAX_DELAY);
}

uint8_t W5500_ReadByte(void)
{
    uint8_t byte;
    W5500_ReadBuff(&byte, sizeof(byte));
    return byte;
}

void W5500_WriteByte(uint8_t byte)
{
    W5500_WriteBuff(&byte, sizeof(byte));
}

#define WORK_SOCKET 0
void W5500_Init(wiz_NetInfo NetParam)
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


void W5500_SocketCreate()
{
    int result = 0;
	printf("CREATING SOCKET \r\n");
    result = socket(WORK_SOCKET, Sn_MR_TCP, 2323, 0);

       if(result != WORK_SOCKET) { printf(OutputBuffer, "SOCKET() ERROR: %d \r\n", result); }
	   else printf("SOCKET CREATED, CONNECTING \r\n");

    result = listen(WORK_SOCKET);

	   if(result != SOCK_OK) { printf(OutputBuffer, "LISTEN() ERROR: %d \r\n", result); }
       else printf("LISTEN() OK\r\n");

	while(getSn_SR(WORK_SOCKET) == SOCK_LISTEN)
    {
			HAL_Delay(2);
    }

    printf("INPUT CONNECTION \r\n");
    if(getSn_SR(WORK_SOCKET) != SOCK_ESTABLISHED) printf("ERROR SOCKET resultUS \r\n");

    uint8_t rIP[4];
    getsockopt(WORK_SOCKET, SO_DESTIP, rIP);

	printf("CONNECTION ESTABLISHED");
	printf(OutputBuffer, "IP:  %d.%d.%d.%d\r\n", rIP[0], rIP[1], rIP[2], rIP[3]); 

	sprintf(OutputBuffer, "CONNECTION ESTABLISHED");
    send(0, (uint8_t*)OutputBuffer, strlen(OutputBuffer));



	HAL_Delay(1000);
}


