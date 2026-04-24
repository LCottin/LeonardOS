#ifndef __MMU_MAP_PRV_H__
#define __MMU_MAP_PRV_H__

#include "types_usr.h"

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

#define K_MMU_TABLE_ENTRIES     512U
#define K_MMU_PAGE_SHIFT        12U
#define K_MMU_L3_SHIFT          12U
#define K_MMU_L2_SHIFT          21U
#define K_MMU_L1_SHIFT          30U
#define K_MMU_L0_SHIFT          39U
#define K_MMU_INDEX_MASK        0x1FFU   /* 9-bit index mask */
#define K_MMU_PA_MASK           0x0000FFFFFFFFF000ULL  /* Output address bits [47:12] */

/* Descriptor type bits [1:0] */
#define K_MMU_DESC_INVALID      0x0ULL
#define K_MMU_DESC_BLOCK        0x1ULL   /* L1/L2 block entry        */
#define K_MMU_DESC_TABLE        0x3ULL   /* L0/L1/L2 table entry     */
#define K_MMU_DESC_PAGE         0x3ULL   /* L3 page entry            */

/* Attribute index in MAIR_EL1 */
#define K_MMU_ATTR_NORMAL       0U       /* MAIR index 0 -> Normal   */
#define K_MMU_ATTR_DEVICE       1U       /* MAIR index 1 -> Device   */
#define K_MMU_ATTRIDX_SHIFT     2U

/* Access permissions AP[2:1] */
#define K_MMU_AP_RW_EL1        (0x0ULL << 6U)   /* RW EL1, none EL0 */
#define K_MMU_AP_RW_ALL        (0x1ULL << 6U)   /* RW EL1 and EL0   */
#define K_MMU_AP_RO_EL1        (0x2ULL << 6U)   /* RO EL1, none EL0 */
#define K_MMU_AP_RO_ALL        (0x3ULL << 6U)   /* RO EL1 and EL0   */

/* Execute-never bits */
#define K_MMU_UXN               (1ULL << 54U)   /* EL0 execute-never */
#define K_MMU_PXN               (1ULL << 53U)   /* EL1 execute-never */

/* Access flag — must be set or HW will fault on first access */
#define K_MMU_AF                (1ULL << 10U)

/* Shareability */
#define K_MMU_SH_INNER          (3ULL << 8U)

/* Non-secure bit */
#define K_MMU_NS                (1ULL << 5U)

/**********************************************************************
 * MAIR_EL1 encoding:
 *   Index 0 (Normal):  0xFF  (Inner/Outer Write-Back, Read/Write Alloc)
 *   Index 1 (Device):  0x00  (Device-nGnRnE)
 **********************************************************************/
#define K_MMU_MAIR_NORMAL       0xFFULL
#define K_MMU_MAIR_DEVICE       0x00ULL
#define K_MMU_MAIR_VALUE        ((K_MMU_MAIR_DEVICE << 8U) | K_MMU_MAIR_NORMAL)

/**********************************************************************
 * TCR_EL1 configuration:
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
#define K_MMU_TCR_VALUE         (K_MMU_TCR_T0SZ  | K_MMU_TCR_T1SZ  | \
                                 K_MMU_TCR_IRGN0 | K_MMU_TCR_ORGN0 | \
                                 K_MMU_TCR_SH0   | K_MMU_TCR_TG0_4K | \
                                 K_MMU_TCR_IRGN1 | K_MMU_TCR_ORGN1 | \
                                 K_MMU_TCR_SH1   | K_MMU_TCR_TG1_4K | \
                                 K_MMU_TCR_IPS_40BIT)

/* Helper: extract level index from VA */
#define K_MMU_L0_IDX(va)   (((va) >> K_MMU_L0_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L1_IDX(va)   (((va) >> K_MMU_L1_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L2_IDX(va)   (((va) >> K_MMU_L2_SHIFT) & K_MMU_INDEX_MASK)
#define K_MMU_L3_IDX(va)   (((va) >> K_MMU_L3_SHIFT) & K_MMU_INDEX_MASK)

/**********************************************************************
 * @brief Return a pointer to or allocate a next-level table.
 *
 * @param entry  Pointer to the descriptor entry in the current table.
 * @return Pointer to the next-level table, or NULL_PTR on failure.
 **********************************************************************/
extern uint64_t *_mmu_get_or_alloc_table(uint64_t *entry);

#endif /* __MMU_MAP_PRV_H__ */
