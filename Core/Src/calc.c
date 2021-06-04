/*
 * calc.c
 *
 *  Created on: Jun 4, 2021
 *      Author: d.bogomaz
 */

#include "calc.h"

void operate(char operation, uint32_t* result, uint32_t* number1, uint32_t* number2)
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
    uint32_t number1 = 0;
    uint32_t number2 = 0;

    for(int8_t i = 0; i < 8; ++i)
    {
    	resiveIRChar();
        if(receivedChar - '0' >= 0 && receivedChar - '0' <= 9)
        {
            number1 = number1 * 10 + receivedChar - '0';
            clearDisplay();
            display(&number1);
            continue;
        }
        if(receivedChar == 'c')
        {
            clearCharView();
            display(charView);
            return;
        }
        if(receivedChar == 'b')
        {
            number1 /= 10;
            clearDisplay();
            display(&number1);
            --i;
            continue;
        }

        // if reached user entered an operation

        break;
    }

    char operation = receivedChar;
    clearDisplay();

    for(int8_t i = 0; i < 8; ++i)
    {
    	resiveIRChar();

        if(receivedChar - '0' >= 0 && receivedChar - '0' <= 9)
        {
            number2 = number2 * 10 + receivedChar - '0';
            clearDisplay();
            display(&result);
            continue;
        }
        if(receivedChar == 'c')
        {
        	clearDisplay();
            return;
        }
        if(receivedChar == 'b')
        {
            number2 /= 10;
            clearDisplay();
            display(&result);
            --i;
            continue;
        }
        if(receivedChar == '=')
        {
            break;
        }
//        operate(operation, &number1, &number1, &number2);
//        clearCharView();
//		display(charView);
//		i2char(number1, charView);
//		display(charView);
//		number2 = 0;
//        i = -1;
        continue;
    }

    uint32_t result;

    operate(operation, &result, &number1, &number2);

    clearDisplay();
    display(&result);
}
