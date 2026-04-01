#include "bmt_ctx_prv.h"
#include "bmt_ctx.h"
#include "bmt_krn.h"

void bmt_ctx_init_kernel(const addr_t bmt_start_addr)
{
    g_p_bmt_ctx_table = (bmt_ctx_table_t *)bmt_start_addr;
}
