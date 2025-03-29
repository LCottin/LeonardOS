#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_kernel_entry(void)
{
    return g_p_bmt_ctx_table->krn_bin.entry_point;
}
