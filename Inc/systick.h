#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <stdint.h>
#include <stdbool.h>

#define delay_s 1000
#define delay_ms 1
#define delay_10ms 10
#define delay_100ms 100

void Systick_Init_Default(void);

uint32_t Systick_Get_Time(void);

bool Systick_Has_Elapsed(uint32_t start, uint32_t delay);

typedef struct
{
    uint32_t Delay_us;
    uint32_t Clock_Hz;
} Systick_Config_t;

void Systick_Init_Config(Systick_Config_t *config);

#endif