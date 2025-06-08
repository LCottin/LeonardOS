#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

uint32_t scheduler_ctx_get_next_task(void)
{
    // TODO: Implement a more sophisticated algorithm to select the next task based on priority and readiness.
    // For now, we simply return the next task in the round-robin fashion.
    uint32_t current_task_id = scheduler_ctx_get_current_task();
    uint32_t next_task_id    = (current_task_id + 1) % g_scheduler_ctx_table.scheduler_nb_tasks;

    return g_scheduler_ctx_table.scheduler_tasks_id[next_task_id];
}
