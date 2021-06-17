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
    int8_t minus = 1;
    operation = receivedChar;
    clearDisplay();

    for(;;)
    {
		for(int8_t i = 0; ; ++i)
		{
			resiveIRChar();

			if(i == 0)
			{
				if(receivedChar == '-')
				{
					changeMinus();
					minus = -1;
					continue;
				}
				if(receivedChar == '0')
				{
					--i;
					continue;
				}
			}
			if(receivedChar >= '0' && receivedChar <= '9')
			{
				if(i < displaySize)
				{
					inputNumber = inputNumber * 10 + receivedChar - '0';
					displayInt(inputNumber * minus);
				}
				else
				{
					--i;
				}
				continue;
			}
			if(receivedChar == 'c')
			{
				clearDisplay();
				i = -1;
				minus = 1;
				inputNumber = 0;
				continue;
			}
			if(receivedChar == 'b')
			{
				inputNumber /= 10;
				displayInt(inputNumber * minus);
				i -= 2;
				continue;
			}
			break;
		}
		inputNumber *= minus;

		if(receivedChar == '=')
		{
			if(operation != 0)
			{
				operate(operation, &outputNumber, &outputNumber, &inputNumber);
				operation = 0;
				displayInt(outputNumber);
				outputNumber = 0;
			}
			else
			{
				displayInt(outputNumber);
			}
		}
		else
		{
			if(outputNumber == 0)
			{
				outputNumber = inputNumber;
				operation = receivedChar;
			}
			else
			{
				operate(operation, &outputNumber, &outputNumber, &inputNumber);
				operation = receivedChar;
			}
			displayInt(outputNumber);
		}
		inputNumber = 0;
	    minus = 1;
    }
}
