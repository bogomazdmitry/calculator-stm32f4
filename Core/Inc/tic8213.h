/*
 * tic8213.h
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_TIC8213_H_
#define INC_TIC8213_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA


#define VIEW_NULL  0b00000000
#define VIEW_MINUS 0b10000000
#define VIEW_0     0b00111111
#define VIEW_1     0b00000110
#define VIEW_2     0b01011011
#define VIEW_3     0b01001111
#define VIEW_4     0b01100110
#define VIEW_5     0b01101101
#define VIEW_6     0b01111101
#define VIEW_7     0b00000111
#define VIEW_8     0b01111111
#define VIEW_9     0b01101111

uint8_t view[8];
extern const uint8_t numbers[];

void char2seg(char in[8], uint8_t out[8]);

void display(char in[8]);

#endif /* INC_TIC8213_H_ */
