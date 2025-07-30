#include "delay.h"

void delay_us(unsigned long us_num)
{
    delay_cycles(80*us_num);
}

void delay_ms(unsigned long ms_num)
{
    for (uint32_t i = 0; i < ms_num; i++)
        delay_us(1000);
}
