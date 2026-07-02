
#include "systick.h"

#include "main.h"
#include "blink.h"
#include "gpio.h"

#define hearbeat_pin PIN_1
#define hearbeat_port GPIOB
#define Systick_Clock 8000000

GPIO_Config_t heartbeat_gpio =
    {
        .port = hearbeat_port,
        .pin = hearbeat_pin,
        .mode = GPIO_MODE_OUTPUT,
        .pull = 0,
        .otype = 0,
        .speed = 0,
        .alternate = 0,};

BLINK_T heartbeat_blink =
    {
        .state = LED_STATE_OFF,
        .on_time = delay_100ms,
        .off_time = (delay_s * 2),
        .tick_source = Systick_Get_Time,
        .port = GPIOB,
        .pin = PIN_1,
};

Systick_Config_t systick_config =
    {
        .Delay_us = 1000,
        .Clock_Hz = Systick_Clock,
};

int main(void)
{

    Systick_Init_Config(&systick_config);

    GPIO_Init(&heartbeat_gpio);

    while (1)
    {
        blink_update(&heartbeat_blink);
    }
}
