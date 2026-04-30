#ifndef __MMU_MAP_H__
#define __MMU_MAP_H__

#include "types_usr.h"
#include "bmt_krn.h"

/**********************************************************************
 * @brief Retrieve kernel L0 page table physical address.
 *
 * @param None.
 * @return Physical address of the kernel L0 page table (PGD).
 **********************************************************************/
extern addr_t mmu_map_get_kernel_l0(void);


/**********************************************************************
 * @brief Maps all required kernel and user app regions based on the
 * provided BMT context table.
 *
 * @param p_bmt Pointer to the populated BMT context table.
 * @return None
 **********************************************************************/
extern void mmu_map_all(const bmt_ctx_table_t *p_bmt);


/**********************************************************************
 * @brief Initializes the kernel L0 page table with identity mappings
 * for all required boot regions derived from linker symbols.
 *
 * This function is called early during MMU initialization to set up
 * the initial page tables before mapping the BMT binary segments.
 *
 * @param None.
 * @return None
 **********************************************************************/
extern void mmu_map_init_kernel_l0(void);


#endif /* __MMU_MAP_H__ */
