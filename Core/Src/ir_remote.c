/*
 * ir_remote.c
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */
#include "ir_remote.h"

void ir2char(const uint32_t* const in, char* out)
{
	switch (*in) {
		case BUTTON_1:
			*out = '1';
			break;
		case BUTTON_2:
			*out = '2';
			break;
		case BUTTON_3:
			*out = '3';
			break;
		case BUTTON_4:
			*out = '4';
			break;
		case BUTTON_5:
			*out = '5';
			break;
		case BUTTON_6:
			*out = '6';
			break;
		case BUTTON_7:
			*out = '7';
			break;
		case BUTTON_8:
			*out = '8';
			break;
		case BUTTON_9:
			*out = '9';
			break;
		case BUTTON_0:
			*out = '0';
			break;
		case BUTTON_UP:
			*out = '*';
			break;
		case BUTTON_DOWN:
			*out = '/';
			break;
		case BUTTON_LEFT:
			*out = '+';
			break;
		case BUTTON_RIGHT:
			*out = '-';
			break;
		case BUTTON_STAR:
			*out = 'c';
			break;
		case BUTTON_SHARP:
			*out = 'b';
			break;
		case BUTTON_OK:
			*out = '=';
			break;
		default:
			*out = 0;
	}
}

void resiveIRChar()
{
	do {

	  while (HAL_GPIO_ReadPin(IR_GPIO_Port, IR_Pin)); // wait for the pin to go low
	  receiveIR(&irdata);
	  ir2char(&irdata, &receivedChar);
	  osDelay(100);
	} while(receivedChar == 0);
}
