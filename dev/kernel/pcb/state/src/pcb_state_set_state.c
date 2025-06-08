#include "pcb_ctx.h"
#include "pcb_state.h"

void pcb_state_set_state(const uint32_t task_id, const pcb_states_t new_state)
{
    /* Set the state of the PCB context for the given task ID */
    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        g_pcb_ctx_table.pcb_apps_ctx[task_id].state = new_state;
    }
    else
    {
        /* Invalid task id, nothing to do */
    }
}
