#include "clock.h"
#include "clock_prv.h"

void clock_init()
{
    g_clock_frequency = clock_get_frequency();
}
