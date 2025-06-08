#include "pcb_ctx.h"
#include "pcb_ctx_prv.h"

void pcb_ctx_app_restore(const uint32_t task_id)
{
    /* Check if the task ID is valid */
    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        /* Restore the application context */
        pcb_ctx_restore(&g_pcb_ctx_table.pcb_apps_ctx[task_id].registers);
    }
    else
    {
        /* Invalid task ID, nothing to do */
    }
}
