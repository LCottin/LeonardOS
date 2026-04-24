#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"

/**********************************************************************
 * @brief Map all PT_LOAD segments of one ELF binary info entry.
 *
 * @param p_bin  Pointer to the ELF binary info from the BMT.
 * @param user   TRUE if the binary runs at EL0 (adds MMU_PERM_USER).
 **********************************************************************/
void mmu_map_binary(const ELF64_binary_info_t *p_bin, const bool_t user)
{
    uint32_t i;

    for (i = 0U; i < p_bin->segments_count; i++)
    {
        const ELF64_custom_segment_t *seg = &p_bin->segments[i];

        if (seg->type != K_ELF_PT_LOAD)
        {
            continue;   /* Skip non-loadable segments (metadata etc.) */
        }

        uint32_t perms = _elf_flags_to_mmu_perms(seg->flags);

        if (user == TRUE)
        {
            perms |= MMU_PERM_USER;
        }

        mmu_map_region(seg->phy_addr, (uint32_t)seg->mem_size, perms);
    }

    /* Also map stack and heap from memory_info (not in PT_LOAD segments) */
    if (p_bin->memory_info.stack_size > 0U)
    {
        const addr_t stack_base = p_bin->memory_info.stack_top;
        const uint32_t stack_perms = MMU_PERM_R | MMU_PERM_W | (user == TRUE ? MMU_PERM_USER : 0U);
        mmu_map_region(stack_base, (uint32_t)p_bin->memory_info.stack_size, stack_perms);
    }

    if (p_bin->memory_info.heap_size > 0U)
    {
        const addr_t heap_base = p_bin->memory_info.heap_start;
        const uint32_t heap_perms = MMU_PERM_R | MMU_PERM_W | (user == TRUE ? MMU_PERM_USER : 0U);
        mmu_map_region(heap_base, (uint32_t)p_bin->memory_info.heap_size, heap_perms);
    }
}

