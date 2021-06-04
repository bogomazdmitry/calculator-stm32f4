/*
 * ports.h
 *
 *  Created on: Jun 4, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_PORTS_H_
#define INC_PORTS_H_

#include "stm32f4xx_hal.h"

/* Private defines -----------------------------------------------------------*/
#define IR_Pin GPIO_PIN_13
#define IR_GPIO_Port GPIOC
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA

#endif /* INC_PORTS_H_ */
