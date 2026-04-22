#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "elf_krn.h"
#include "memory_ops_usr.h"

void bmt_build_table()
{
    /* Initialize the kernel binary */
    const addr_t krn_addr = g_p_bmt_ctx_table->krn_bin.load_address;

    /* Make sure kernel is compatible */
    g_p_bmt_ctx_table->krn_bin.is_compatible = elf_check_is_compatible(krn_addr);

    if (g_p_bmt_ctx_table->krn_bin.is_compatible == TRUE)
    {
        /* Get kernel entry point */
        g_p_bmt_ctx_table->krn_bin.entry_point = elf_info_get_entry_point(krn_addr);

        /* Fill segment information */
        elf_build_segment_info(krn_addr, &g_p_bmt_ctx_table->krn_bin);
    }
    else
    {
        /* Kernel binary is not compatible, nothing is filled */
    }

    /* Initialize the application binaries */
    for (uint32_t app_idx = 0; app_idx < g_p_bmt_ctx_table->apps_count; app_idx++)
    {
        const addr_t app_addr = g_p_bmt_ctx_table->apps_bin[app_idx].load_address;

        /* Make sure application is compatible */
        g_p_bmt_ctx_table->apps_bin[app_idx].is_compatible = elf_check_is_compatible(app_addr);

        if (g_p_bmt_ctx_table->apps_bin[app_idx].is_compatible == TRUE)
        {
            /* Get binary entry point */
            g_p_bmt_ctx_table->apps_bin[app_idx].entry_point = elf_info_get_entry_point(app_addr);

            /* Fill segment information */
            elf_build_segment_info(app_addr, &g_p_bmt_ctx_table->apps_bin[app_idx]);
        }
        else
        {
            /* Application binary is not compatible, nothing is filled */
        }
    }
}
