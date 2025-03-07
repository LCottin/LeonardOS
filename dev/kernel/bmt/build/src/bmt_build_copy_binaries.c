#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "memory_ops_usr.h"

void bmt_build_copy_binaries(void)
{
    /* Loop through all the binaries in the bmt table */
    for (uint32_t bin_idx = 0; bin_idx < g_p_bmt_ctx_table->binaries_count; bin_idx++)
    {
        const ELF64_binary_info_t *p_binary = &g_p_bmt_ctx_table->binaries[bin_idx];

        /* Loop through all the segments in the binary */
        for (uint32_t seg_idx = 0; seg_idx < p_binary->segments_count; seg_idx++)
        {
            const ELF64_custom_segment_t *p_segment = &p_binary->segments[seg_idx];

            /* Copy the segment to the correct memory location if it is a loadable segment */
            if (p_segment->type == K_ELF_PT_LOAD)
            {
                const addr_t src_addr = p_binary->load_address + p_segment->file_offset;
                addr_t dst_addr       = p_segment->virt_addr;

                /* Copy the segment to the correct memory location */
                if ((p_segment->file_size > 0)  && (src_addr != dst_addr))
                {
                    memory_ops_copy((ptr_t)dst_addr, (cptr_t)src_addr, p_segment->file_size);
                }

                /* Zero out the remaining memory if the memory size is larger than the file size */
                if (p_segment->mem_size > p_segment->file_size)
                {
                    memory_ops_set((ptr_t)(dst_addr + p_segment->file_size), 0, p_segment->mem_size - p_segment->file_size);
                }
            }
        }
    }
}
