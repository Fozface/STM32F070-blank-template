#ifndef _BLINK_H_
#define _BLINK_H_

#include "stm32f030x6.h"
#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    LED_STATE_ON = true,
    LED_STATE_OFF = false

} LED_STATE_T;

typedef enum
{
    GPIO_A,
    GPIO_B,
    GPIO_C,
    GPIO_D,
    GPIO_E,
    GPIO_F,

} GPIO_PORT_T;

typedef enum
{
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,

} GPIO_PIN_T;
typedef struct 
{
    LED_STATE_T state;
    uint16_t on_time;
    uint16_t off_time;

    uint32_t (*tick_source)(void);

    GPIO_PORT_T port;
    GPIO_PIN_T pin;

    //=====non-user=======
    int LED_last_trig;
}BLINK_T;




void blink_update(BLINK_T *);

#endif