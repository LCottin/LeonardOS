#include "bmt_ctx_prv.h"
#include "bmt_ctx.h"
#include "bmt_krn.h"
#include "memory_ops_usr.h"

void bmt_ctx_init(void)
{
    g_p_bmt_ctx_table = (bmt_ctx_table_t *)&__bmt_start;
    memory_ops_set(g_p_bmt_ctx_table, 0, sizeof(bmt_ctx_table_t));
}
