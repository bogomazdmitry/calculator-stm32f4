/*
 * ir_remote.h
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_IR_REMOTE_H_
#define INC_IR_REMOTE_H_

#include <stdint.h>
#include "ports.h"

#define BUTTON_1         0xffa25d
#define BUTTON_2         0xff629d
#define BUTTON_3         0xffe21d
#define BUTTON_4         0xff22dd
#define BUTTON_5         0xff02fd
#define BUTTON_6         0xffc23d
#define BUTTON_7         0xffe01f
#define BUTTON_8         0xffa857
#define BUTTON_9         0xff906f
#define BUTTON_0         0xff9867
#define BUTTON_UP        0xff18e7
#define BUTTON_DOWN      0xff4ab5
#define BUTTON_LEFT      0xff10ef
#define BUTTON_RIGHT     0xff5aa5
#define BUTTON_STAR      0xff6897
#define BUTTON_SHARP     0xffb04f
#define BUTTON_OK        0xff38c7

void ir2char(const uint32_t* const in, char* out);

char receivedChar;
uint32_t irdata;
void resiveIRChar();

#endif /* INC_IR_REMOTE_H_ */
