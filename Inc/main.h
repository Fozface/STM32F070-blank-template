#ifndef _MAIN_H_
#define _MAIN_H_
#include "stm32f0xx.h"
#include <stdint.h>
#include <stdbool.h>

#define delay_s 1000
#define delay_ms 1
#define delay_10ms 10
#define delay_100ms 100

typedef enum
{
    LED_OFF = 0,
    LED_ON = 1
} LED_State;
LED_State LED_STATE = LED_OFF;



#endif
