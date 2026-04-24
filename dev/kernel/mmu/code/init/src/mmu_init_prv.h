#ifndef __MMU_INIT_PRV_H__
#define __MMU_INIT_PRV_H__

#include "types_usr.h"
#include "bmt_krn.h"
#include "elf_krn.h"

/**********************************************************************
 * @brief Symbol addresses in the linker script.
 **********************************************************************/
extern addr_t __text_start[];
extern addr_t __text_end[];
extern addr_t __rodata_start[];
extern addr_t __rodata_end[];
extern addr_t __data_start[];
extern addr_t __data_end[];
extern addr_t __bss_start[];
extern addr_t __bss_end[];
extern addr_t __stack_start[];
extern addr_t __stack_end[];
extern addr_t __heap_start[];
extern addr_t __heap_end[];
extern addr_t __page_pool_start[];
extern addr_t __page_pool_end[];


/**********************************************************************
 * @brief UART MMIO region — the only hardcoded address in the kernel.
 **********************************************************************/
#define K_MMU_REGION_UART_BASE      0x09000000U
#define K_MMU_REGION_UART_SIZE      0x1000U


/**********************************************************************
 * @brief Map a contiguous physical region (identity: VA == PA).
 *
 * @param base   Physical base address.
 * @param size   Size in bytes.
 * @param perms  MMU_PERM_* flags.
 * @return None.
 **********************************************************************/
extern void mmu_init_map_region(const addr_t base, const uint32_t size, const uint32_t perms);


/**********************************************************************
 * @brief Map all regions: kernel via linker symbols, apps via BMT.
 *
 * @param p_bmt  Pointer to the BMT context table.
 * @return None.
 **********************************************************************/
extern void mmu_init_identity_map(const bmt_ctx_table_t *p_bmt);


/**********************************************************************
 * @brief Retrieve kernel L0 page table physical address.
 *
 * @param None.
 * @return Physical address of the kernel L0 page table (PGD).
 **********************************************************************/
extern addr_t mmu_init_get_kernel_pgd(void);


#endif /* __MMU_INIT_PRV_H__ */
