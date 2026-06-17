#include "blink.h"
#include "systick.h"

void blink_update(BLINK_T *led)
{
    if (Systick_Has_Elapsed(led->LED_last_trig, led->on_time) && led->state == LED_STATE_ON)
    {
        led->port->BSRR = (1 << 16 << led->pin);
        led->state = LED_STATE_OFF;
        led->LED_last_trig = led->tick_source();
    }
    else if (Systick_Has_Elapsed(led->LED_last_trig, led->off_time) && (led->state == LED_STATE_OFF))
    {
        led->port->BSRR = (1 << led->pin);
        led->state = LED_STATE_ON;
        led->LED_last_trig = led->tick_source();
    }
}
