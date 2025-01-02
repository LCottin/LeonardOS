#include "clock.h"
#include "clock_prv.h"

time_t clock_get_time()
{
    uint64_t current_cycle = clock_get_cycle_count();
    time_t   current_time = (time_t)((float64_t)current_cycle * (float64_t)1000000000 / (float64_t)g_clock_frequency);

    return current_time;
}
