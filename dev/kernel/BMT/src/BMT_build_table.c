#include "BMT.h"
#include "ELF.h"
#include "memory_ops.h"

void BMT_build_table()
{
    for (uint32_t elf_idx = 0; elf_idx < g_p_bmt_table->binaries_count; elf_idx++)
    {
        const addr_t elf_addr = g_p_bmt_table->binaries[elf_idx].load_address;

        /* Make sure all data are correct */
        g_p_bmt_table->binaries[elf_idx].is_compatible = elf_is_compatible(elf_addr);

        if (g_p_bmt_table->binaries[elf_idx].is_compatible == TRUE)
        {
            /* Get binary entry point */
            g_p_bmt_table->binaries[elf_idx].entry_point = elf_get_entry_point(elf_addr);



            /* Get number of segments */
            g_p_bmt_table->binaries[elf_idx].segments_count = elf_get_nb_segments(elf_addr);

            /* Fill segment information */
            elf_fill_segment_info(elf_addr, &g_p_bmt_table->binaries[elf_idx]);
        }
        else
        {
            /* Binary is not compatible, nothing is filled */
        }
    }
}
