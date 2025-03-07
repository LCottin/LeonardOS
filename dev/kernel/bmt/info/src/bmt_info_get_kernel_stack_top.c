#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_kernel_stack_top(void)
{
    addr_t stack_top = NULL_ADDR;

    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_ctx_table->binaries[idx];

        if (p_binary->type == ELF64_FILE_KERNEL)
        {
            stack_top = p_binary->memory_info.stack_top;
        }
    }

    return stack_top;
}
