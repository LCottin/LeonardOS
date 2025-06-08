#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "bmt_build_prv.h"

bool_t bmt_build_add_app_elf(const addr_t elf_addr)
{
    bool_t elf_added;

    if (g_p_bmt_ctx_table->apps_count < K_BMT_MAX_APP_BINARIES)
    {
        g_p_bmt_ctx_table->apps_bin[g_p_bmt_ctx_table->apps_count].load_address = elf_addr;
        g_p_bmt_ctx_table->apps_count++;
        elf_added = TRUE;
    }
    else
    {
        /* Maximum number of applications reached */
        elf_added = FALSE;
    }

    return elf_added;
}
