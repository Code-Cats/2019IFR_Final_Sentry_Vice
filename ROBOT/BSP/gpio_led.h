#ifndef __GPIO_LED_H
#define __GPIO_LED_H
#include "sys.h"

void LED_Init(void);

#define LED1 PBout(6)
#define LED2 PBout(7)

#endif
