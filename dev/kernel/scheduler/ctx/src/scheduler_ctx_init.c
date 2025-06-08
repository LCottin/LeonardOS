#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"
#include "memory_ops_usr.h"

void scheduler_ctx_init(void)
{
    memory_ops_set(&g_scheduler_ctx_table, 0, sizeof(g_scheduler_ctx_table));
}
