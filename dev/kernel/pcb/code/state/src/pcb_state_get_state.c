#include "pcb_krn.h"
#include "pcb_ctx.h"
#include "pcb_state.h"

pcb_states_t pcb_state_get_state(const uint32_t task_id)
{
    pcb_states_t state;
    if (task_id < g_pcb_ctx_table.pcb_apps_count)
    {
        state = g_pcb_ctx_table.pcb_apps_ctx[task_id].state;
    }
    else
    {
        state = PCB_STATE_UNKNOWN;
    }

    return state;
}
