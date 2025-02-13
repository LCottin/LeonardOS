#include "BMT.h"
#include "ELF.h"
#include "memory_ops.h"

void BMT_build_table()
{
    for (uint32_t idx = 0U; idx < g_p_bmt_table->binaries_count; idx++)
    {
        const addr_t elf_addr = g_p_bmt_table->binaries[idx].load_address;

        /* Make sure all data are correct */
        g_p_bmt_table->binaries[idx].is_compatible = elf_is_compatible(elf_addr);

        if (g_p_bmt_table->binaries[idx].is_compatible == TRUE)
        {
            /* Get binary entry point */
            g_p_bmt_table->binaries[idx].entry_point = elf_get_entry_point(elf_addr);

            /* Get binary type */
            g_p_bmt_table->binaries[idx].type = elf_get_type(elf_addr);

            /* Get binary size */
            g_p_bmt_table->binaries[idx].binary_size = elf_get_size(elf_addr);

            /* Get number of segments */
            g_p_bmt_table->binaries[idx].segments_count = elf_get_nb_segments(elf_addr);

            /* Fill segments information */
            for (uint32_t j = 0U; j < g_p_bmt_table->binaries[idx].segments_count; j++)
            {
                elf_fill_segment_info(elf_addr, &g_p_bmt_table->binaries[idx].segments[j], j);
            }
        }
        else
        {
            /* Binary is not compatible, nothing is filled */
        }
    }
}
