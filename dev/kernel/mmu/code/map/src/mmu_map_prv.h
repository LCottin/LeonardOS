#ifndef __MMU_MAP_PRV_H__
#define __MMU_MAP_PRV_H__

#include "types_usr.h"
#include "mmu_page.h"
#include "elf_krn.h"

/**********************************************************************
 * AArch64 page table descriptor bits (4KB granule, 48-bit VA)
 *
 * Level structure: L0 -> L1 -> L2 -> L3 (leaf)
 * Each table holds 512 entries (9 VA bits per level).
 *
 * VA bit layout:
 *   [47:39] L0 index
 *   [38:30] L1 index
 *   [29:21] L2 index
 *   [20:12] L3 index
 *   [11: 0] Page offset
 **********************************************************************/

/**********************************************************************
 * @brief Symbol addresses in the linker script.
 **********************************************************************/
extern addr_t __text_start;
extern addr_t __text_end;
extern addr_t __rodata_start;
extern addr_t __rodata_end;
extern addr_t __data_start;
extern addr_t __data_end;
extern addr_t __bss_start;
extern addr_t __bss_end;
extern addr_t __stack_start;
extern addr_t __stack_end;
extern addr_t __page_pool_start;
extern addr_t __page_pool_end;


/**********************************************************************
 * @brief Page permission flags passed to mmu_map_page().
 *        Combine with bitwise OR.
 **********************************************************************/
#define K_MMU_MAP_PERM_R      (1U << 0U)   /* Readable                  */
#define K_MMU_MAP_PERM_W      (1U << 1U)   /* Writable                  */
#define K_MMU_MAP_PERM_X      (1U << 2U)   /* Executable                */
#define K_MMU_MAP_PERM_USER   (1U << 3U)   /* Accessible from EL0       */
#define K_MMU_MAP_PERM_DEVICE (1U << 4U)   /* Device / MMIO memory      */


/**********************************************************************
 * @brief UART MMIO region — the only hardcoded address in the kernel.
 **********************************************************************/
#define K_MMU_REGION_UART_BASE      0x09000000U
#define K_MMU_REGION_UART_SIZE      0x1000U


/**********************************************************************
 * @brief MMU level shifts.
 **********************************************************************/
#define K_MMU_TABLE_ENTRIES     512U
#define K_MMU_L3_SHIFT          12U
#define K_MMU_L2_SHIFT          21U
#define K_MMU_L1_SHIFT          30U
#define K_MMU_L0_SHIFT          39U
#define K_MMU_INDEX_MASK        0x1FFU   /* 9-bit index mask */
#define K_MMU_PA_MASK           0x0000FFFFFFFFF000ULL  /* Output address bits [47:12] */


/**********************************************************************
 * @brief Page table descriptor bits and helper macros.
 **********************************************************************/
#define K_MMU_DESC_TABLE        0x3ULL   /* L0/L1/L2 table entry     */
#define K_MMU_DESC_PAGE         0x3ULL   /* L3 page entry            */


/**********************************************************************
 * @brief MMU attributes
 **********************************************************************/
#define K_MMU_ATTR_NORMAL       0U       /* MAIR index 0 -> Normal   */
#define K_MMU_ATTR_DEVICE       1U       /* MAIR index 1 -> Device   */
#define K_MMU_ATTRIDX_SHIFT     2U


/**********************************************************************
 * @brief AP bits for page descriptors (L3)
 **********************************************************************/
#define K_MMU_AP_RW_EL1        (0x0ULL << 6U)   /* RW EL1, none EL0 */
#define K_MMU_AP_RW_ALL        (0x1ULL << 6U)   /* RW EL1 and EL0   */
#define K_MMU_AP_RO_EL1        (0x2ULL << 6U)   /* RO EL1, none EL0 */
#define K_MMU_AP_RO_ALL        (0x3ULL << 6U)   /* RO EL1 and EL0   */


/**********************************************************************
 * @brief Execute-never for page descriptors.
 **********************************************************************/
#define K_MMU_UXN               (1ULL << 54U)   /* EL0 execute-never */
#define K_MMU_PXN               (1ULL << 53U)   /* EL1 execute-never */



/**********************************************************************
 * @brief Access flag (set on access, used for page replacement).
 **********************************************************************/
#define K_MMU_AF                (1ULL << 10U)

/**********************************************************************
 * @brief Sharing attribute bits for page descriptors (L3) and TCR.
 **********************************************************************/
#define K_MMU_SH_INNER          (3ULL << 8U)


/**********************************************************************
 * @brief Non-secure bit for table descriptors (L0/L1/L2) to allow EL0 access.
 **********************************************************************/
#define K_MMU_NS                (1ULL << 5U)


/**********************************************************************
 * @brief MAIR_EL1 encoding:
 *   Index 0 (Normal):  0xFF  (Inner/Outer Write-Back, Read/Write Alloc)
 *   Index 1 (Device):  0x00  (Device-nGnRnE)
 **********************************************************************/
#define K_MMU_MAIR_NORMAL       0xFFULL
#define K_MMU_MAIR_DEVICE       0x00ULL
#define K_MMU_MAIR_VALUE        ((K_MMU_MAIR_DEVICE << 8U) | K_MMU_MAIR_NORMAL)


/**********************************************************************
 * @brief TCR_EL1 configuration:
 *   T0SZ=16  -> 48-bit VA for TTBR0 (user)
 *   T1SZ=16  -> 48-bit VA for TTBR1 (kernel)
 *   TG0=00   -> 4KB granule TTBR0
 *   TG1=10   -> 4KB granule TTBR1
 *   SH0/SH1  -> Inner shareable
 *   ORGN/IRGN -> Write-back cacheable
 *   EPD1=0   -> TTBR1 enabled
 **********************************************************************/
#define K_MMU_TCR_T0SZ          (16ULL <<  0U)
#define K_MMU_TCR_T1SZ          (16ULL << 16U)
#define K_MMU_TCR_IRGN0         (1ULL  <<  8U)
#define K_MMU_TCR_ORGN0         (1ULL  << 10U)
#define K_MMU_TCR_SH0           (3ULL  << 12U)
#define K_MMU_TCR_TG0_4K        (0ULL  << 14U)
#define K_MMU_TCR_IRGN1         (1ULL  << 24U)
#define K_MMU_TCR_ORGN1         (1ULL  << 26U)
#define K_MMU_TCR_SH1           (3ULL  << 28U)
#define K_MMU_TCR_TG1_4K        (2ULL  << 30U)
#define K_MMU_TCR_IPS_40BIT     (2ULL  << 32U)   /* 40-bit PA (1TB) */
#define K_MMU_TCR_VALUE         (K_MMU_TCR_T0SZ  | K_MMU_TCR_T1SZ   | \
                                 K_MMU_TCR_IRGN0 | K_MMU_TCR_ORGN0  | \
                                 K_MMU_TCR_SH0   | K_MMU_TCR_TG0_4K | \
                                 K_MMU_TCR_IRGN1 | K_MMU_TCR_ORGN1  | \
                                 K_MMU_TCR_SH1   | K_MMU_TCR_TG1_4K | \
                                 K_MMU_TCR_IPS_40BIT)


/**********************************************************************
 * @brief Extract the L0/L1/L2/L3 index from a virtual address.
 **********************************************************************/
#define K_MMU_L0_IDX(va)   (((va) >> K_MMU_L0_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L1_IDX(va)   (((va) >> K_MMU_L1_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L2_IDX(va)   (((va) >> K_MMU_L2_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L3_IDX(va)   (((va) >> K_MMU_L3_SHIFT) & K_MMU_INDEX_MASK)


/**********************************************************************
 * @brief Global pointer to the kernel L0 page table (PGD)
 **********************************************************************/
extern uint64_t *g_p_mmu_kernel_l0;


/**********************************************************************
 * @brief Return a pointer to or allocate a next-level table.
 *
 * @param entry  Pointer to the descriptor entry in the current table.
 * @return Pointer to the next-level table, or NULL_PTR on failure.
 **********************************************************************/
extern uint64_t *mmu_map_get_alloc_table(uint64_t *entry);


/**********************************************************************
 * @brief Maps one 4KB virtual page to one physical frame in the
 *        kernel page tables (TTBR1 / EL1).
 *
 * Allocates intermediate table levels as needed from the page pool.
 * An identity mapping (va == pa) is used for the kernel during Phase 1.
 *
 * @param va    Virtual address (4KB aligned).
 * @param pa    Physical address (4KB aligned).
 * @param perms Permission flags (K_MMU_MAP_PERM_*).
 * @return None.
 **********************************************************************/
extern void mmu_map_page(const addr_t va, const addr_t pa, const uint32_t perms);


/**********************************************************************
 * @brief Maps regions associated to boot
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void mmu_map_boot(void);

/**********************************************************************
 * @brief Maps all PT_LOAD segments of one ELF binary info entry.
 *
 * @param p_bin  Pointer to the ELF binary info from the BMT.
 * @param user   TRUE if the binary runs at EL0 (adds K_MMU_MAP_PERM_USER).
 **********************************************************************/
extern void mmu_map_binary(const ELF64_binary_info_t *p_bin, const bool_t user);


/**********************************************************************
 * @brief Maps a virtual region to a physical region with given permissions.
 *
 * The region is mapped page by page (4KB) using mmu_map_page().
 *
 * @param base  Base virtual address of the region (4KB aligned).
 * @param size  Size of the region in bytes (must be multiple of 4KB).
 * @param perms Permission flags (K_MMU_MAP_PERM_*).
 * @return None.
 **********************************************************************/
extern void mmu_map_region(const addr_t base, const size_t size, const uint32_t perms);


#endif /* __MMU_MAP_PRV_H__ */
