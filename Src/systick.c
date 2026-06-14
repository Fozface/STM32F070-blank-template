#include "systick.h"


static volatile uint32_t g_tick = 0;

void systick_init(void)
{
    
    //Configure SysTick for 1ms tick
    SysTick_Config(SystemCoreClock / 1000); 

    g_tick = 0;
}

void SysTick_Handler(void)
{
    g_tick++;

}

uint32_t systick_get_time(void)
{
    return g_tick;
}

bool systick_has_elapsed(uint32_t start, uint32_t delay)
{
    return (uint32_t)(g_tick - start) >= delay;
}
