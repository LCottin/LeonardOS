#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"
#include "pcb_krn.h"

void scheduler_ctx_add_task(const uint32_t task_idx)
{
    g_p_scheduler_ctx_table->scheduler_tasks_id[g_p_scheduler_ctx_table->scheduler_nb_tasks] = task_idx;
    g_p_scheduler_ctx_table->scheduler_apps_ctx[g_p_scheduler_ctx_table->scheduler_nb_tasks] = pcb_ctx_get_app_ctx(task_idx);
    g_p_scheduler_ctx_table->scheduler_nb_tasks++;
}
