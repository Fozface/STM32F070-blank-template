
#include "stm32f0xx.h"
#include <stdint.h>

int main(void)
{
    // Enable GPIOB clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // PB1 as output
    GPIOB->MODER &= ~(3 << (1 * 2));
    GPIOB->MODER |=  (1 << (1 * 2));

        // Enable GPIOA clock
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

    // PA1 as output
    GPIOA->MODER &= ~(3 << (1 * 2));
    GPIOA->MODER |=  (1 << (1 * 2));

    GPIOA->AFR[0] &= ~(0xF << (1 * 4));





    while (1)
    {
        // Toggle PB1
        GPIOB->ODR ^= (1 << 1);
        GPIOA->ODR ^= (1 << 1);
        
        // Simple delay
        for (volatile int i = 0; i < 1000000; i++);
    }
}