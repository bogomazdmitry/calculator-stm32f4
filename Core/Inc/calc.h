/*
 * calc.h
 *
 *  Created on: Jun 4, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_CALC_H_
#define INC_CALC_H_

#include <stdint.h>
#include "ir_remote.h"
#include "tic8213.h"

void operate(char operation, int32_t* result, int32_t* number1, int32_t* number2);

void calcTask();

#endif /* INC_CALC_H_ */
