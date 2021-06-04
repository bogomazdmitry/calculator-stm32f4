/*
 * tic8213.c
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */
#include "tic8213.h"

extern SPI_HandleTypeDef hspi1;

const uint8_t numbers[] = {VIEW_0, VIEW_1, VIEW_2, VIEW_3, VIEW_4, VIEW_5, VIEW_6, VIEW_7, VIEW_8, VIEW_9};
char charView[displaySize] = "        ";


void clearCharView()
{
	for(uint8_t i = 0; i < displaySize; ++i)
	{
		charView[i] = ' ';
	}
}

void char2seg(char in[displaySize], uint8_t out[displaySize])
{
	for(int8_t i = 0, k = displaySize - 1; i < displaySize; --k, ++i)
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

void changeMinus()
{
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

void addMinus()
{
	if(HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin))
	{
	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}

void clearMinus()
{
	if(!HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin))
	{
	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}


void displayInt(int32_t* number)
{
    i2char(*number, charView);
    if(*number < 0)
    {
  	  addMinus();
    }
    displayString(charView);
}

void displayString(char in[displaySize])
{
	char2seg(in, view);
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, view, displaySize, 100);
	HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, GPIO_PIN_SET);
}

// we gotta rename the thing or (even better) make so display takes uint8_t[8] and not char[8]
void i2char(int32_t i, char out[8])
{
    for(int8_t k = 7; k >= 0 && i > 0; --k)
    {
        uint8_t x = i % 10;
        i /= 10;

        out[k] = x + '0';
    }
}

void clearDisplay()
{
	clearMinus();
    clearCharView();
    displayString(charView);
}
