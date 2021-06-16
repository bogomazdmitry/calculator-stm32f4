/*
 * calc.c
 *
 *  Created on: Jun 4, 2021
 *      Author: d.bogomaz
 */

#include "calc.h"

void operate(char operation, int32_t* result, int32_t* number1, int32_t* number2)
{
    switch(operation)
    {
        case '+':
            *result = *number1 + *number2;
            break;
        case '-':
            *result = *number1 - *number2;
            break;
        case '*':
            *result = *number1 * *number2;
            break;
        case '/':
            *result = *number1 / *number2;
            break;
        default:
            // idk
            break;
    }
}

// add number to buffer (charView) immediately and display it
void calcTask()
{
    int32_t outputNumber = 0;
    int32_t inputNumber = 0;
    char operation;

    operation = receivedChar;
    clearDisplay();

    for(;;)
    {
		for(int8_t i = 0; ; ++i)
		{
			resiveIRChar();

			  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			if(receivedChar == '-' && i == 0)
			{
				changeMinus();
			}
			else if(receivedChar >= '0' && receivedChar <= '9')
			{
				if(i < displaySize)
				{
					inputNumber = inputNumber * 10 + receivedChar - '0';
					clearDisplay();
					displayInt(&inputNumber);
					continue;
				}
				else
				{
					--i;
				}
			}
			else if(receivedChar == 'c')
			{
				clearDisplay();
				return;
			}
			else if(receivedChar == 'b')
			{
				inputNumber /= 10;
				clearDisplay();
				displayInt(&inputNumber);
				--i;
			}
		}

		if(receivedChar == '=')
		{
			if(operation != 0)
			{
				operate(operation, &outputNumber, &outputNumber, &inputNumber);
				operation = 0;
			}
		}
		else
		{
			if(outputNumber == 0)
			{
				outputNumber = inputNumber;
			}
			else
			{
				operate(operation, &outputNumber, &outputNumber, &inputNumber);
				operation = receivedChar;
			}
		}
		displayInt(&outputNumber);
		inputNumber = 0;
    }
}
