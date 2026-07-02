#include "systick.h"

#include "stm32f030x6.h"

//this MCU uses a system clock of 8 MHz by default, so we can calculate the reload value for 1 ms ticks
#ifndef SystemCoreClock
#define SystemCoreClock 8000000
#endif


static volatile uint32_t g_tick = 0;

void Systick_Init_Default(void)
{
    //Configure SysTick for 1ms tick
    SysTick_Config(SystemCoreClock / 1000 - 1); 

    g_tick = 0;
}

void SysTick_Handler(void)
{
    g_tick++;

}

uint32_t Systick_Get_Time(void)
{
    return g_tick;
}

bool Systick_Has_Elapsed(uint32_t start, uint32_t delay)
{
    return (uint32_t)(g_tick - start) >= delay;
}


void Systick_Init_Config(Systick_Config_t *config)
{
    uint32_t ticks = (config->Clock_Hz / 1000000) * config->Delay_us;
    // Configure SysTick for 1 msecond delay
    SysTick_Config(ticks - 1);

    g_tick = 0;
}