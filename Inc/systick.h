#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "stm32f0xx.h"
#include <stdint.h>
#include <stdbool.h>

void Systick_Init_Default(void);

uint32_t Systick_Get_Time(void);

bool Systick_Has_Elapsed(uint32_t start, uint32_t delay);









#endif