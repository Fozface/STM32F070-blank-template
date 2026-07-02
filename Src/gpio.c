#include "gpio.h"

void GPIO_Init(GPIO_Config_t *config)
{
    // Enable the correct peripheral clock
    if (config->port == GPIOA)
        RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    else if (config->port == GPIOB)
        RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
    else if (config->port == GPIOC)
        RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    else if (config->port == GPIOD)
        RCC->AHBENR |= RCC_AHBENR_GPIODEN;
    else if (config->port == GPIOF)
        RCC->AHBENR |= RCC_AHBENR_GPIOFEN;

    // Clear previous mode
    config->port->MODER &= ~(3U << (config->pin * 2));

    // Set new mode
    config->port->MODER |= ((uint32_t)config->mode << (config->pin * 2));
}
