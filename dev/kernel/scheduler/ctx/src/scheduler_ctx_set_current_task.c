#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

void scheduler_ctx_set_current_task(const uint32_t task_id)
{
    g_p_scheduler_ctx_table->scheduler_current_task_id = task_id;
}
