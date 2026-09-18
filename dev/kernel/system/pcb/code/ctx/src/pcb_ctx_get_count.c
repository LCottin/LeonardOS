#include "pcb_ctx.h"
#include "pcb_krn.h"

uint32_t pcb_ctx_get_count(void)
{
    return g_pcb_ctx_table.pcb_apps_count;
}
