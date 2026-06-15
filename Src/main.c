
#include "stm32f0xx.h"
#include "systick.h"

#include "main.h"

int led_tick = 0;
int next_led_tick_count = 0;

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
        led_tick = Systick_Get_Time();

        if ((led_tick >= next_led_tick_count) && LED_STATE == LED_ON)
        {

            GPIOB->ODR = (0 << 1);
            LED_STATE = LED_OFF;
            next_led_tick_count = Systick_Get_Time() + (delay_s + (delay_100ms * 5));
        }
        else if ((led_tick >= next_led_tick_count) && (LED_STATE == LED_OFF))
        {
            GPIOB->ODR = (1 << 1);
            LED_STATE = LED_ON;
            next_led_tick_count = Systick_Get_Time() + (delay_100ms * 1);
        }
    }
}