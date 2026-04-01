#include "scheduler_ctx.h"
#include "scheduler_ctx_prv.h"
#include "memory_ops_usr.h"
#include "pcb_krn.h"

void scheduler_ctx_init(const addr_t sch_start_addr)
{
    g_p_scheduler_ctx_table = (scheduler_ctx_table_t *)sch_start_addr;
    memory_ops_set(g_p_scheduler_ctx_table, 0, sizeof(*g_p_scheduler_ctx_table));

    g_p_scheduler_ctx_table->scheduler_krn_ctx = pcb_ctx_get_krn_ctx();

    scheduler_ctx_save_address(sch_start_addr);
}
