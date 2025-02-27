#include "BMT.h"

addr_t BMT_get_kernel_entry(void)
{
    addr_t entry_point = NULL_ADDR;

    for (uint32_t idx = 0; idx < g_p_bmt_table->binaries_count; idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_table->binaries[idx];

        if (p_binary->type == ELF64_FILE_KERNEL)
        {
            entry_point = p_binary->entry_point;
        }
    }

    return entry_point;
}
