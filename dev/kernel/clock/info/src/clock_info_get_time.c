#include "clock_krn.h"
#include "clock_info.h"

time_t clock_info_get_time()
{
    uint64_t current_cycles = clock_info_get_cycle_count();
    uint64_t frequency      = clock_info_get_frequency();

    uint64_t elapsed_time_ns  = (current_cycles / frequency) * 1000000000LL;
    elapsed_time_ns          += ((current_cycles % frequency) * 1000000000LL) / frequency;

    return (time_t)elapsed_time_ns;
}
