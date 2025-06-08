#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

void scheduler_ctx_add_task(const uint32_t task_idx)
{
    g_scheduler_ctx_table.scheduler_tasks_id[g_scheduler_ctx_table.scheduler_nb_tasks] = task_idx;
    g_scheduler_ctx_table.scheduler_nb_tasks++;
}
