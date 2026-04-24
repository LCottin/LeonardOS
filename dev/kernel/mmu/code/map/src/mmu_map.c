#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"

/**********************************************************************
 * @brief Kernel L0 page table (root, pointed to by TTBR1_EL1).
 *        512 entries × 8 bytes = 4KB — exactly one page, 4KB aligned.
 **********************************************************************/
static uint64_t _mmu_kernel_l0[K_MMU_TABLE_ENTRIES] __attribute__((aligned(MMU_PAGE_SIZE)));

/**********************************************************************
 * @brief Retrieve the physical address of the kernel L0 table.
 *        Called by mmu_init() to load TTBR1_EL1.
 **********************************************************************/
addr_t mmu_map_get_kernel_pgd(void)
{
    return (addr_t)_mmu_kernel_l0;
}

/**********************************************************************
 * @brief Get or allocate the next-level table pointed to by *entry.
 *        If the entry is invalid, a new page is allocated and linked.
 *
 * @param entry  Pointer to the descriptor slot in the current table.
 * @return Pointer to the next-level table, or NULL_PTR on OOM.
 **********************************************************************/
uint64_t *_mmu_get_or_alloc_table(uint64_t *entry)
{
    if ((*entry & 0x3ULL) == K_MMU_DESC_TABLE)
    {
        /* Already present — extract the table PA */
        return (uint64_t *)(*entry & K_MMU_PA_MASK);
    }

    /* Allocate a new zeroed page for the next-level table */
    const addr_t new_pa = mmu_page_alloc();
    if (new_pa == NULL_ADDR)
    {
        return (uint64_t *)NULL_PTR;
    }

    /* Write table descriptor: PA | TABLE | NS */
    *entry = (new_pa & K_MMU_PA_MASK) | K_MMU_DESC_TABLE | K_MMU_NS;

    return (uint64_t *)new_pa;
}

/**********************************************************************
 * @brief Build the L3 page descriptor from permission flags.
 **********************************************************************/
static uint64_t _mmu_build_l3_desc(const addr_t pa, const uint32_t perms)
{
    uint64_t desc = (pa & K_MMU_PA_MASK) | K_MMU_DESC_PAGE | K_MMU_AF;

    /* Memory type */
    if ((perms & MMU_PERM_DEVICE) != 0U)
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
    if ((perms & MMU_PERM_X) == 0U)
    {
        desc |= K_MMU_UXN | K_MMU_PXN;
    }

    /* Access permissions */
    if ((perms & MMU_PERM_USER) != 0U)
    {
        desc |= ((perms & MMU_PERM_W) != 0U) ? K_MMU_AP_RW_ALL : K_MMU_AP_RO_ALL;
    }
    else
    {
        desc |= ((perms & MMU_PERM_W) != 0U) ? K_MMU_AP_RW_EL1 : K_MMU_AP_RO_EL1;
    }

    return desc;
}

bool_t mmu_map_page(const addr_t va, const addr_t pa, const uint32_t perms)
{
    /* --- L0 --- */
    uint64_t *l1 = _mmu_get_or_alloc_table(&_mmu_kernel_l0[K_MMU_L0_IDX(va)]);
    if (l1 == (uint64_t *)NULL_PTR)
    {
        return FALSE;
    }

    /* --- L1 --- */
    uint64_t *l2 = _mmu_get_or_alloc_table(&l1[K_MMU_L1_IDX(va)]);
    if (l2 == (uint64_t *)NULL_PTR)
    {
        return FALSE;
    }

    /* --- L2 --- */
    uint64_t *l3 = _mmu_get_or_alloc_table(&l2[K_MMU_L2_IDX(va)]);
    if (l3 == (uint64_t *)NULL_PTR)
    {
        return FALSE;
    }

    /* --- L3 leaf --- */
    l3[K_MMU_L3_IDX(va)] = _mmu_build_l3_desc(pa, perms);

    return TRUE;
}


/**********************************************************************
 * @brief Round an address down to page boundary.
 **********************************************************************/
static addr_t _page_align_down(const addr_t addr)
{
    return (addr & ~(addr_t)(MMU_PAGE_SIZE - 1U));
}

/**********************************************************************
 * @brief Round an address up to next page boundary.
 **********************************************************************/
static addr_t _page_align_up(const addr_t addr)
{
    return (addr + (addr_t)(MMU_PAGE_SIZE - 1U)) & ~(addr_t)(MMU_PAGE_SIZE - 1U);
}


/**********************************************************************
 * @brief Convert ELF PF_* flags to MMU_PERM_* flags.
 *
 * ELF:  PF_X = 0x1,  PF_W = 0x2,  PF_R = 0x4
 * MMU:  PERM_R = 0x1, PERM_W = 0x2, PERM_X = 0x4
 **********************************************************************/
static uint32_t _elf_flags_to_mmu_perms(const uint32_t elf_flags)
{
    uint32_t perms = 0U;

    if ((elf_flags & K_ELF_PF_R) != 0U)
    {
        perms |= MMU_PERM_R;
    }
    if ((elf_flags & K_ELF_PF_W) != 0U)
    {
        perms |= MMU_PERM_W;
    }
    if ((elf_flags & K_ELF_PF_X) != 0U)
    {
        perms |= MMU_PERM_X;
    }

    /* Kernel segments are always EL1-only (no MMU_PERM_USER) */
    return perms;
}
