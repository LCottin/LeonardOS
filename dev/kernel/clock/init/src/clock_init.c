#include "clock_krn.h"
#include "clock_ctx.h"
#include "clock_info.h"

void clock_init()
{
    g_clock_ctx_frequency = clock_info_get_frequency();
}
