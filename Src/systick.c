#include "systick.h"


static volatile uint32_t g_tick = 0;

void Systick_Init_Default(void)
{
    
    //Configure SysTick for 1ms tick
    SysTick_Config(SystemCoreClock / 1000); 

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
