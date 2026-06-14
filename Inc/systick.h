#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "stm32f0xx.h"
#include <stdint.h>

#include <stdbool.h>


uint32_t time_now_ms(void);
bool time_elapsed(uint32_t start, uint32_t delay);


void systick_init(void);


void systick_delay(uint32_t ms);






#endif