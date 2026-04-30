#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "elf_krn.h"

/**********************************************************************
 * @brief Map all PT_LOAD segments of one ELF binary info entry.
 *
 * @param p_bin  Pointer to the ELF binary info from the BMT.
 * @param user   TRUE if the binary runs at EL0 (adds K_MMU_MAP_PERM_USER).
 **********************************************************************/
void mmu_map_binary(const ELF64_binary_info_t *p_bin, const bool_t user)
{
    for (uint32_t idx = 0U; idx < p_bin->segments_count; idx++)
    {
        const ELF64_custom_segment_t *seg = &p_bin->segments[idx];

        if (seg->type == K_ELF_PT_LOAD)
        {
            uint32_t perms = 0;

            if ((seg->flags & K_ELF_PF_R) != 0U)
            {
                perms |= K_MMU_MAP_PERM_R;
            }
            if ((seg->flags & K_ELF_PF_W) != 0U)
            {
                perms |= K_MMU_MAP_PERM_W;
            }
            if ((seg->flags & K_ELF_PF_X) != 0U)
            {
                perms |= K_MMU_MAP_PERM_X;
            }
            if (user == TRUE)
            {
                perms |= K_MMU_MAP_PERM_USER;
            }

            mmu_map_region(seg->phy_addr, (uint32_t)seg->mem_size, perms);
        }
        else
        {
            /* Non loadable segment, nothing to do */
        }
    }

    /* Also map stack and heap from memory_info (not in PT_LOAD segments) */
    if (p_bin->memory_info.stack_size > 0U)
    {
        const addr_t stack_base    = p_bin->memory_info.stack_top;
        const uint32_t stack_perms = K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W | (user == TRUE ? K_MMU_MAP_PERM_USER : 0U);
        mmu_map_region(stack_base, (uint32_t)p_bin->memory_info.stack_size, stack_perms);
    }

    if (p_bin->memory_info.heap_size > 0U)
    {
        const addr_t heap_base    = p_bin->memory_info.heap_start;
        const uint32_t heap_perms = K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W | (user == TRUE ? K_MMU_MAP_PERM_USER : 0U);
        mmu_map_region(heap_base, (uint32_t)p_bin->memory_info.heap_size, heap_perms);
    }
}
