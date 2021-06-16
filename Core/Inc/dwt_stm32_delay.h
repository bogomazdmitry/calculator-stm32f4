#ifndef DWT_STM32_DELAY_H
#define DWT_STM32_DELAY_H

#ifdef __cplusplus
extern "C" {
#endif


#include "stm32f4xx_hal.h"
#include "ports.h"

extern TIM_HandleTypeDef htim4;

void DWT_Delay_us(uint32_t nus);


#ifdef __cplusplus
}
#endif

#endif
