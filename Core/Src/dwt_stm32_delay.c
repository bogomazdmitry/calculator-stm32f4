#include "dwt_stm32_delay.h"

void DWT_Delay_us(uint32_t nus)
{
    htim4.Instance->CNT = 0;
    while (htim4.Instance->CNT < nus);
}
