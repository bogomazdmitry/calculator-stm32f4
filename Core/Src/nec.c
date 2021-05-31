/*
 * nec.c
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */
#include "nec.h"

void receiveIR(uint32_t* out)
{
	uint32_t code = 0;

	/* The START Sequence begin here
	   * there will be a pulse of 9ms LOW and
	   * than 4.5 ms space (HIGH)
	   */
	while (!(HAL_GPIO_ReadPin(IR_GPIO_Port, IR_Pin))); // wait for the pin to go high.. 9ms LOW
	while ((HAL_GPIO_ReadPin(IR_GPIO_Port, IR_Pin))); // wait for the pin to go low.. 4.5ms HIGH
	/* START of FRAME ends here*/

	/* DATA Reception
	   * We are only going to check the SPACE after 562.5us pulse
	   * if the space is 562.5us, the bit indicates '0'
	   * if the space is around 1.6ms, the bit is '1'
	   */
	uint8_t count;
	for (int i = 0; i < 32; i++)
	{
		count = 0;
		while (!(HAL_GPIO_ReadPin(IR_GPIO_Port, IR_Pin)))
			;										  // wait for pin to go high.. this is 562.5us LOW
		while ((HAL_GPIO_ReadPin(IR_GPIO_Port, IR_Pin))) // count the space length while the pin is high
		{
			count++;
			DWT_Delay_us(100);
		}
		if (count > 12) // if the space is more than 1.2 ms
		{
			code |= (1UL << (31 - i)); // write 1
		}
		else
		{
			code &= ~(1UL << (31 - i)); // write 0
		}
	}
	*out = code;
}
