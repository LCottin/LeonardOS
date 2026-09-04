#include "scheduler_krn.h"
#include "scheduler_ctx.h"
#include "pcb_krn.h"
#include "memory_ops_usr.h"

void scheduler_init(const addr_t sch_start_addr)
{
    scheduler_ctx_init(sch_start_addr);

    const uint32_t nb_task = pcb_ctx_get_count();

    /* Initialize the scheduler context */
    for (uint32_t idx = 0; idx < nb_task; idx++)
    {
        const pcb_states_t state = pcb_state_get_state(idx);

        if (state == PCB_STATE_NEW)
        {
            scheduler_ctx_add_task(idx);
        }
        else
        {
            /* Task is not new, not added to context */
        }
    }
}
