
#include "stm32f0xx.h"
#include "systick.h"

#include "main.h"

int LED_last_trig = 0;
int LED_delay = 0;

int main(void)
{

    Systick_Init_Default();
    // Enable GPIOB clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // PB1 as output
    GPIOB->MODER &= ~(3 << (1 * 2));
    GPIOB->MODER |= (1 << (1 * 2));

    GPIOB->ODR ^= (1 << 1);

    while (1)
    {

        if (Systick_Has_Elapsed(LED_last_trig, LED_delay) && LED_STATE == LED_ON)
        {
            GPIOB->ODR = (0 << 1);
            LED_STATE = LED_OFF;
            LED_delay = (delay_s + (delay_100ms * 5));
            LED_last_trig = Systick_Get_Time();
        }
        else if (Systick_Has_Elapsed(LED_last_trig, LED_delay) && (LED_STATE == LED_OFF))
        {
            GPIOB->ODR = (1 << 1);
            LED_STATE = LED_ON;
            LED_delay = (delay_100ms);
            LED_last_trig = Systick_Get_Time();   
        }
    }
}

