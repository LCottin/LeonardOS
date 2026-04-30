#ifndef __MMU_PAGE_H__
#define __MMU_PAGE_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Size of one page (4KB granule, AArch64 standard)
 **********************************************************************/
#define MMU_PAGE_SIZE           0x1000U


/**********************************************************************
 * @brief Initializes the static page frame pool.
 *        Must be called before mmu_init() or mmu_map_page().
 *
 * @param None.
 * @return None
 **********************************************************************/
extern void mmu_page_init(void);


/**********************************************************************
 * @brief Allocates one physical page frame (4KB, zeroed).
 *
 * @param None.
 * @return Physical address of the allocated frame, or NULL_ADDR on
 *         exhaustion.
 **********************************************************************/
extern addr_t mmu_page_alloc(void);


#endif /* __MMU_PAGE_H__ */
