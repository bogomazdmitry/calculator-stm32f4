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
#include "ports.h"

#define VIEW_NULL  0b00000000
#define VIEW_MINUS 0b01000000
#define VIEW_0     0b01011111
#define VIEW_1     0b01010000
#define VIEW_2     0b00111011
#define VIEW_3     0b01111001
#define VIEW_4     0b01110100
#define VIEW_5     0b01101101
#define VIEW_6     0b01101111
#define VIEW_7     0b01011000
#define VIEW_8     0b01111111
#define VIEW_9     0b01111101

#define displaySize 8

uint8_t view[displaySize];
extern const uint8_t numbers[];
extern char charView[];

void char2seg(char in[displaySize], uint8_t out[displaySize]);
void display(char in[displaySize]);
void clearDisplay();
void i2char(uint32_t i, char out[8]);
void clearCharView();

#endif /* INC_TIC8213_H_ */
