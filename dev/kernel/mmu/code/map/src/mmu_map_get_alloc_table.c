#include "mmu_map.h"
#include "mmu_map_prv.h"

uint64_t *mmu_map_get_alloc_table(uint64_t *entry)
{
    uint64_t *new_pa;

    if ((*entry & K_MMU_DESC_TABLE) == K_MMU_DESC_TABLE)
    {
        /* Already present — extract the table PA */
        new_pa = (uint64_t *)(*entry & K_MMU_PA_MASK);
    }

    else
    {
        /* Allocate a new zeroed page for the next-level table */
        new_pa = (uint64_t *)mmu_page_alloc();
        if (new_pa != NULL_ADDR)
        {
            *entry = ((addr_t)new_pa & (K_MMU_PA_MASK | K_MMU_DESC_TABLE | K_MMU_NS));
        }
    }

    return new_pa;
}
