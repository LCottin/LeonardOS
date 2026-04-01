#include "pcb_krn.h"
#include "pcb_ctx.h"
#include "pcb_state.h"

void pcb_state_set_apps_ready(void)
{
    /* Set the PCB apps state to READY */
    for (uint32_t i = 0; i < g_pcb_ctx_table.pcb_apps_count; i++)
    {
        g_pcb_ctx_table.pcb_apps_ctx[i].state = PCB_STATE_READY;
    }
}
