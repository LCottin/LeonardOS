#include "bmt_krn.h"
#include "bmt_ctx.h"

void bmt_build_add_elf(const addr_t elf_addr)
{
    g_p_bmt_ctx_table->binaries[g_p_bmt_ctx_table->binaries_count].load_address = elf_addr;
    g_p_bmt_ctx_table->binaries_count += 1U;
}
