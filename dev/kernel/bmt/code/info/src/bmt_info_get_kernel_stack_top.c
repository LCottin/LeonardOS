#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_kernel_stack_top(void)
{
    return g_p_bmt_ctx_table->krn_bin.memory_info.stack_top;
}
