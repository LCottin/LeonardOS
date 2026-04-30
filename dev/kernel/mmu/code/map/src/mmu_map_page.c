#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"
#include "elf_krn.h"

void mmu_map_page(const addr_t va, const addr_t pa, const uint32_t perms)
{
    uint64_t *l1 = NULL_PTR;
    uint64_t *l2 = NULL_PTR;
    uint64_t *l3 = NULL_PTR;

    /* --- L0 --- */
    l1 = mmu_map_get_alloc_table(&g_p_mmu_kernel_l0[K_MMU_L0_IDX(va)]);
    if (l1 != NULL_PTR)
    {
        /* --- L1 --- */
        l2 = mmu_map_get_alloc_table(&l1[K_MMU_L1_IDX(va)]);
    }

    if (l2 != NULL_PTR)
    {
        /* --- L2 --- */
        l3 = mmu_map_get_alloc_table(&l2[K_MMU_L2_IDX(va)]);
    }

    if (l3 != NULL_PTR)
    {
        /* --- L3 leaf --- */
        uint64_t desc = (pa & K_MMU_PA_MASK) | K_MMU_DESC_PAGE | K_MMU_AF;

        /* Memory type */
        if ((perms & K_MMU_MAP_PERM_DEVICE) != 0U)
        {
            desc |= ((uint64_t)K_MMU_ATTR_DEVICE << K_MMU_ATTRIDX_SHIFT);
            desc |= K_MMU_UXN | K_MMU_PXN;   /* Device is never executable */
        }
        else
        {
            desc |= ((uint64_t)K_MMU_ATTR_NORMAL << K_MMU_ATTRIDX_SHIFT);
            desc |= K_MMU_SH_INNER;
        }

        /* Execute-never */
        if ((perms & K_MMU_MAP_PERM_X) == 0U)
        {
            desc |= K_MMU_UXN | K_MMU_PXN;
        }

        /* Access permissions */
        if ((perms & K_MMU_MAP_PERM_USER) != 0U)
        {
            desc |= ((perms & K_MMU_MAP_PERM_W) != 0U) ? K_MMU_AP_RW_ALL : K_MMU_AP_RO_ALL;
        }
        else
        {
            desc |= ((perms & K_MMU_MAP_PERM_W) != 0U) ? K_MMU_AP_RW_EL1 : K_MMU_AP_RO_EL1;
        }

        l3[K_MMU_L3_IDX(va)] = desc;
    }
}
