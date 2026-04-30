#ifndef __MMU_KRN_H__
#define __MMU_KRN_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Initializes the MMU for the kernel (EL1).
 *
 * Sequence:
 *   0. Initialize kernel l0 page table
 *   1. Initialize page frame pool
 *   2. Identity-map kernel regions via linker symbols
 *   3. Identity-map all PT_LOAD segments from BMT (kernel + user apps)
 *   4. Map UART MMIO region as Device memory
 *   5. Write MAIR_EL1, TCR_EL1, TTBR1_EL1
 *   6. ISB + enable SCTLR_EL1.M
 *
 * User app regions are discovered dynamically from the BMT — no
 * hardcoded addresses required for applications.
 *
 * @param p_bmt Pointer to the populated BMT context table.
 * @return None
 **********************************************************************/
extern void mmu_init(const bmt_ctx_table_t *p_bmt);


#endif /* __MMU_KRN_H__ */
