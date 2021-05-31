/*
 * ir_remote.h
 *
 *  Created on: Jun 1, 2021
 *      Author: d.bogomaz
 */

#ifndef INC_IR_REMOTE_H_
#define INC_IR_REMOTE_H_

#include <stdint.h>

#define BUTTON_1         0xffa25d
#define BUTTON_2         0xff629d
#define BUTTON_3         0xffe21d
#define BUTTON_4         0x807f916
#define BUTTON_5         0xff02fd
#define BUTTON_6         0x807fe1
#define BUTTON_7         0x807ff00f
#define BUTTON_8         0xffa857
#define BUTTON_9         0xff906f
#define BUTTON_0         0xe619f007
#define BUTTON_UP        0xff18e7
#define BUTTON_DOWN      0x807fa55a
#define BUTTON_LEFT      0xff10ef
#define BUTTON_RIGHT     0x807fad52
#define BUTTON_STAR      0x201fed12
#define BUTTON_SHARP     0xffb04f
#define BUTTON_OK        0x3fce31f

void ir2char(const uint32_t* const in, char* out);

#endif /* INC_IR_REMOTE_H_ */
