#include "blink.h"


void blink_update(BLINK_CONFIG_T *led)
{
    if (Systick_Has_Elapsed(led->LED_last_trig, led->on_time) && led->state == LED_STATE_ON)
    {
        GPIOB->ODR = (0 << 1);
        led->state = LED_STATE_OFF;
        led->LED_last_trig = led->tick_source();
    }
    else if (Systick_Has_Elapsed(led->LED_last_trig, led->off_time) && (led->state == LED_STATE_OFF))
    {
        GPIOB->ODR = (1 << 1);
        led->state = LED_STATE_ON;
        led->LED_last_trig = led->tick_source();
    }
}
