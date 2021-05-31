/*
 * nec.h
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_NEC_H_
#define INC_NEC_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "dwt_stm32_delay.h"

#define IR_Pin GPIO_PIN_13
#define IR_GPIO_Port GPIOC

void receiveIR(uint32_t* out);

#endif /* INC_NEC_H_ */
