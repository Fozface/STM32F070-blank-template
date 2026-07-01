#include "blink.h"
#include "systick.h"

void blink_update(BLINK_T *led)
//does is the current tick count minus the last trigger time greater than the on time and the state is on
{//                         last trig time      the set on time         state is on
    if (Systick_Has_Elapsed(led->LED_last_trig, led->on_time) && led->state == LED_STATE_ON)
    {
        //set the LED pin to low
        led->port->BSRR = (1 << 16 << led->pin);

        //save the state of the LED to OFF
        led->state = LED_STATE_OFF;

        // Update the last trigger time to the current tick count
        led->LED_last_trig = led->tick_source();
    }
    else if (Systick_Has_Elapsed(led->LED_last_trig, led->off_time) && (led->state == LED_STATE_OFF))
    {
        //set the LED pin to high
        led->port->BSRR = (1 << led->pin);

        //save the state of the LED to ON
        led->state = LED_STATE_ON;

        // Update the last trigger time to the current tick count
        led->LED_last_trig = led->tick_source();
    }
}
