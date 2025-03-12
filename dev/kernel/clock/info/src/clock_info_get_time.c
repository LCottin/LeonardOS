#include "clock_krn.h"
#include "clock_ctx.h"
#include "clock_info.h"

time_t clock_info_get_time()
{
    uint64_t current_cycle = clock_info_get_cycle_count();
    time_t   current_time = (time_t)((float64_t)current_cycle * (float64_t)1000000000.0F / (float64_t)g_clock_ctx_frequency);

    return current_time;
}
