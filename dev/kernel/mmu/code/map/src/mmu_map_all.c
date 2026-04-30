#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Map all kernel regions using linker symbols, then walk the
 *        BMT to map every loaded binary dynamically.
 * *
 * @param p_bmt  Pointer to the BMT context table.
 **********************************************************************/
void mmu_map_all(const bmt_ctx_table_t *p_bmt)
{
    /* ----------------------------------------------------------------
     * 1. Boot regions — derived from linker symbols, no hardcoding
     * ---------------------------------------------------------------- */
    mmu_map_boot();

    /* ----------------------------------------------------------------
     * 2. BMT — kernel binary segments (EL1, no K_MMU_MAP_PERM_USER)
     * ---------------------------------------------------------------- */
    if (p_bmt != (const bmt_ctx_table_t *)NULL_PTR)
    {
        mmu_map_binary(&p_bmt->krn_bin, FALSE);

        /* ----------------------------------------------------------------
         * 3. BMT — user app segments (EL0, with K_MMU_MAP_PERM_USER)
         * ---------------------------------------------------------------- */
        for (uint32_t idx = 0U; idx < p_bmt->apps_count; idx++)
        {
            mmu_map_binary(&p_bmt->apps_bin[idx], TRUE);
        }
    }
}
