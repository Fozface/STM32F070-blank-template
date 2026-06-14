#include "systick.h"


static volatile uint32_t g_tick = 0;





void time_init(void)
{
    
    //Configure SysTick for 1ms tick
    SysTick_Config(SystemCoreClock / 1000); 

    g_tick = 0;
}
