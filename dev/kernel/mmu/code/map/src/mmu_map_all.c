#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"


/**********************************************************************
 * @brief Map all kernel regions using linker symbols, then walk the
 *        BMT to map every loaded binary dynamically.
 * *
 * @param p_bmt  Pointer to the BMT context table.
 **********************************************************************/
void mmu_map_all(const bmt_ctx_table_t *p_bmt)
{
    uint32_t idx;

    /* ----------------------------------------------------------------
     * 1. Boot regions — derived from linker symbols, no hardcoding
     * ---------------------------------------------------------------- */

    /* .text — rx */
    mmu_map_region((addr_t)__text_start,
                    (uint32_t)((addr_t)__text_end - (addr_t)__text_start),
                    MMU_PERM_R | MMU_PERM_X);

    /* .rodata — r */
    if (__rodata_end > __rodata_start)
    {
        mmu_map_region((addr_t)__rodata_start,
                        (uint32_t)((addr_t)__rodata_end - (addr_t)__rodata_start),
                        MMU_PERM_R);
    }

    /* .data — rw */
    mmu_map_region((addr_t)__data_start,
                    (uint32_t)((addr_t)__data_end - (addr_t)__data_start),
                    MMU_PERM_R | MMU_PERM_W);

    /* .bss — rw */
    mmu_map_region((addr_t)__bss_start,
                    (uint32_t)((addr_t)__bss_end - (addr_t)__bss_start),
                    MMU_PERM_R | MMU_PERM_W);

    /* stack — rw */
    mmu_map_region((addr_t)__stack_start,
                    (uint32_t)((addr_t)__stack_end - (addr_t)__stack_start),
                    MMU_PERM_R | MMU_PERM_W);

    /* heap — rw */
    mmu_map_region((addr_t)__heap_start,
                    (uint32_t)((addr_t)__heap_end - (addr_t)__heap_start),
                    MMU_PERM_R | MMU_PERM_W);

    /* page pool — rw */
    mmu_map_region((addr_t)__page_pool_start,
                    (uint32_t)((addr_t)__page_pool_end - (addr_t)__page_pool_start),
                    MMU_PERM_R | MMU_PERM_W);

    /* UART MMIO — device rw */
    mmu_map_region((addr_t)K_MMU_REGION_UART_BASE,
                    K_MMU_REGION_UART_SIZE,
                    MMU_PERM_R | MMU_PERM_W | MMU_PERM_DEVICE);

    /* ----------------------------------------------------------------
     * 2. BMT — kernel binary segments (EL1, no MMU_PERM_USER)
     * ---------------------------------------------------------------- */
    if (p_bmt != (const bmt_ctx_table_t *)NULL_PTR)
    {
        mmu_map_binary(&p_bmt->krn_bin, FALSE);

        /* ----------------------------------------------------------------
         * 3. BMT — user app segments (EL0, with MMU_PERM_USER)
         * ---------------------------------------------------------------- */
        for (idx = 0U; idx < p_bmt->apps_count; idx++)
        {
            mmu_map_binary(&p_bmt->apps_bin[idx], TRUE);
        }
    }
}
