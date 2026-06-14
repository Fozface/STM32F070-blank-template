#include "systick.h"

#ifndef SystemCoreClock
#define SystemCoreClock 8000000
#endif


static volatile uint32_t g_tick = 0;

void Systick_Init_Default(void)
{
    // Configure SysTick for 1 msecond delay
    SysTick->LOAD = (SystemCoreClock/1000 - 1); // Assuming 8 MHz clock
    SysTick->VAL = 0;         // Clear current value
    NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
    SysTick->CTRL =
        SysTick_CTRL_ENABLE_Msk |
        SysTick_CTRL_TICKINT_Msk |
        SysTick_CTRL_CLKSOURCE_Msk;

    
    //Configure SysTick for 1ms tick
    //SysTick_Config(SystemCoreClock / 1000); 

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
