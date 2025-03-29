#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "bmt_build_prv.h"

void bmt_build_add_krn_elf(const addr_t elf_addr)
{
    g_p_bmt_ctx_table->krn_bin.load_address = elf_addr;
}
