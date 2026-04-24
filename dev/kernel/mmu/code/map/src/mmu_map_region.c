#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"

/**********************************************************************
 * @brief Map a contiguous physical region with given permissions.
 *        Identity mapping: VA == PA.
 *
 * @param base   Physical base address (will be page-aligned down).
 * @param end    Physical end address (will be page-aligned up).
 * @param perms  MMU_PERM_* flags.
 **********************************************************************/
void mmu_map_region(const addr_t base, const uint32_t size, const uint32_t perms)
{
    const addr_t aligned_base = _page_align_down(base);
    const addr_t aligned_end  = _page_align_up(base + (addr_t)size);
    addr_t va = aligned_base;

    while (va < aligned_end)
    {
        (void)mmu_map_page(va, va, perms);
        va += (addr_t)MMU_PAGE_SIZE;
    }
}
