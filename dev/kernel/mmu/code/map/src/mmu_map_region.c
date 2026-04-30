#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"

static addr_t mmu_map_align_down(const addr_t addr)
{
    return (addr & ~(addr_t)(MMU_PAGE_SIZE - 1U));
}

static addr_t mmu_map_align_up(const addr_t addr)
{
    return (addr + (addr_t)(MMU_PAGE_SIZE - 1U)) & ~(addr_t)(MMU_PAGE_SIZE - 1U);
}

void mmu_map_region(const addr_t base, const size_t size, const uint32_t perms)
{
    const addr_t aligned_base = mmu_map_align_down(base);
    const addr_t aligned_end  = mmu_map_align_up(base + (addr_t)size);
    addr_t va = aligned_base;

    while (va < aligned_end)
    {
        mmu_map_page(va, va, perms);
        va += (addr_t)MMU_PAGE_SIZE;
    }
}
