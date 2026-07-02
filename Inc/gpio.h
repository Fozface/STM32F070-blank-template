#ifndef _GPIO_H_
#define _GPIO_H_

#include "stm32f030x6.h"
#include <stdint.h>

typedef enum
{
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT = 1,
    GPIO_MODE_AF = 2,
    GPIO_MODE_ANALOG = 3
} GPIO_Mode_t;

typedef struct
{
    GPIO_TypeDef *port;
    uint8_t pin;
    GPIO_Mode_t mode;
    uint8_t pull;
    uint8_t otype;
    uint8_t speed;
    uint8_t alternate;
} GPIO_Config_t;



void GPIO_Init(GPIO_Config_t *config);
#endif
