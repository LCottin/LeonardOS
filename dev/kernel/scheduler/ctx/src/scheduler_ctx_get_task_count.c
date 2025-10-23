#include "scheduler_krn.h"
#include "scheduler_ctx_prv.h"

uint32_t scheduler_ctx_get_task_count(void)
{
    return g_p_scheduler_ctx_table->scheduler_nb_tasks;
}
