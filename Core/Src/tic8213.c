/*
 * tic8213.c
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */
#include "tic8213.h"

extern SPI_HandleTypeDef hspi1;

const uint8_t numbers[] = {VIEW_0, VIEW_1, VIEW_2, VIEW_3, VIEW_4, VIEW_5, VIEW_6, VIEW_7, VIEW_8, VIEW_9};

void char2seg(char in[8], uint8_t out[8])
{
	for(int8_t i = 0, k = 7; i < 8; --k, ++i)
	{
		if(in[i] >= '0' && in[i] <= '9')
		{
			out[k] = numbers[in[i] - '0'];
		}
		else if(out[i] == ' ')
		{
			out[k] = VIEW_NULL;
		}
		else if(out[i] == '-')
		{
			out[k] = VIEW_MINUS;
		}
		else
		{
			out[k] = VIEW_NULL;
		}
	}
}

void display(char in[8])
{
	char2seg(in, view);
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, view, 8, 100);
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
}
