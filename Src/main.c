
#include "stm32f0xx.h"
#include <stdint.h>
#include "systick.h"

int now = 0;
#define delay_s 1000

int main(void)
{

    Systick_Init_Default();
    // Enable GPIOB clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // PB1 as output
    GPIOB->MODER &= ~(3 << (1 * 2));
    GPIOB->MODER |=  (1 << (1 * 2));



    GPIOB->ODR ^= (1 << 1);
    



    while (1)
    {
        
        if (Systick_Has_Elapsed(now, delay_s))
        {
            now = Systick_Get_Time();
            
            GPIOB->ODR ^= (1 << 1);
        }
    }
}