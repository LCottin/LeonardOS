#include "pcb_ctx.h"
#include "pcb_krn.h"

addr_t pcb_ctx_get_app_ctx(const uint32_t task_id)
{
    addr_t app_ctx;

    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        app_ctx = (addr_t)&g_pcb_ctx_table.pcb_apps_ctx[task_id];
    }
    else
    {
        app_ctx =  NULL_ADDR;
    }

    return app_ctx;
}
