#include "BMT.h"

void BMT_add_elf(const addr_t elf_addr)
{
    g_p_bmt_table->binaries[g_p_bmt_table->binaries_count].load_address = elf_addr;
    g_p_bmt_table->binaries_count += 1U;
}
