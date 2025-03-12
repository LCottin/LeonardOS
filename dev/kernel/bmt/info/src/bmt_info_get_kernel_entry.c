#include "bmt_krn.h"
#include "bmt_ctx.h"

addr_t bmt_info_get_kernel_entry(void)
{
    addr_t entry_point = NULL_ADDR;

    for (uint32_t idx = 0; idx < g_p_bmt_ctx_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_ctx_table->binaries[idx];

        if (p_binary->type == ELF64_FILE_KERNEL)
        {
            entry_point = p_binary->entry_point;
        }
    }

    return entry_point;
}
