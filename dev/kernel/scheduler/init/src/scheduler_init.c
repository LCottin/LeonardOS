#include "scheduler_krn.h"
#include "scheduler_ctx.h"
#include "pcb_krn.h"
#include "memory_ops_usr.h"

void scheduler_init(void)
{
    memory_ops_set(&g_scheduler_ctx_table, 0, sizeof(g_scheduler_ctx_table));

    const uint32_t nb_task = pcb_ctx_get_count();

    /* Initialize the scheduler context */
    for (uint32_t idx = 0; idx < nb_task; idx++)
    {
        const pcb_states_t state = pcb_state_get_state(idx);

        if (state == PCB_STATE_NEW)
        {
            // faire un accesseur
            g_scheduler_ctx_table.scheduler_tasks_id[g_scheduler_ctx_table.scheduler_nb_tasks] = idx;
            g_scheduler_ctx_table.scheduler_nb_tasks++;
        }
    }
}
