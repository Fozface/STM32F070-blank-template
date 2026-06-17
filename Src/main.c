
#include "systick.h"

#include "main.h"
#include "blink.h"

// int LED_last_trig = 0;
// int LED_delay = 0;

int main(void)
{

    Systick_Init_Default();
    // Enable GPIOB clock
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

    // PB1 as output
    GPIOB->MODER &= ~(3 << (1 * 2));
    GPIOB->MODER |= (1 << (1 * 2));

    GPIOB->ODR ^= (1 << 1);

    BLINK_T heartbeat =
        {
            .state = LED_STATE_OFF,
            .on_time = delay_100ms,
            .off_time = (delay_s * 3),
            .tick_source = Systick_Get_Time,
            .port = GPIOB,
            .pin = PIN_1,
        };

    while (1)
    {
        blink_update(&heartbeat);
    }
}
