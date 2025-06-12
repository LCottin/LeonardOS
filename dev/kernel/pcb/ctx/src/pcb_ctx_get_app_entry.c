#include "pcb_ctx.h"
#include "pcb_krn.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"

addr_t pcb_ctx_get_app_entry(const uint32_t task_id)
{
    addr_t app_entry;

    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        app_entry = g_pcb_ctx_table.pcb_apps_ctx[task_id].registers.pc;
    }
    else
    {
        app_entry =  NULL_ADDR;
    }

    return app_entry;
}
