/*
 * W5500ReadWriteInterface.c
 *
 *  Created on: Feb 21, 2024
 *      Author: broms
 */
#include "main.h"
#include "W5500ReadWriteInterface.h"

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



