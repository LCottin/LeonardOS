#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"

uint32_t scheduler_ctx_get_current_task(void)
{
    return g_scheduler_ctx_table.scheduler_current_task_id;
}
