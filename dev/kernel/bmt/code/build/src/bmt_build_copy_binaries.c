#include "bmt_krn.h"
#include "bmt_ctx.h"
#include "bmt_build_prv.h"
#include "memory_ops_usr.h"

void bmt_build_copy_binaries(void)
{
    /* Copy the kernel */
    const ELF64_binary_info_t *p_krn_bin = &g_p_bmt_ctx_table->krn_bin;

    /* Loop through all the segments in the kernel */
    for (uint32_t seg_idx = 0; seg_idx < p_krn_bin->segments_count; seg_idx++)
    {
        const ELF64_custom_segment_t *p_segment = &p_krn_bin->segments[seg_idx];

        /* Copy the segment to the correct memory location if it is a loadable segment */
        if (p_segment->type == K_ELF_PT_LOAD)
        {
            bmt_build_load_segment(p_krn_bin->load_address, p_segment);
        }
        else
        {
            /* Segment not loadable, ignore it */
        }
    }

    /* Loop through all the binaries application in the bmt table */
    for (uint32_t bin_idx = 0; bin_idx < g_p_bmt_ctx_table->apps_count; bin_idx++)
    {
        const ELF64_binary_info_t *p_app_bin = &g_p_bmt_ctx_table->apps_bin[bin_idx];

        /* Loop through all the segments in the binary */
        for (uint32_t seg_idx = 0; seg_idx < p_app_bin->segments_count; seg_idx++)
        {
            const ELF64_custom_segment_t *p_segment = &p_app_bin->segments[seg_idx];

            /* Copy the segment to the correct memory location if it is a loadable segment */
            if (p_segment->type == K_ELF_PT_LOAD)
            {
                bmt_build_load_segment(p_app_bin->load_address, p_segment);
            }
            else
            {
                /* Segment not loadable, ignore it */
            }
        }
    }
}
