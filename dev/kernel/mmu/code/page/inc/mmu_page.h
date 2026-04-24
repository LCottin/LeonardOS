#ifndef __MMU_PAGE_H__
#define __MMU_PAGE_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Size of one page (4KB granule, AArch64 standard)
 **********************************************************************/
#define MMU_PAGE_SIZE           0x1000U

/**********************************************************************
 * @brief Total number of physical frames in the static page pool.
 *        Pool covers 256 pages = 1MB. Adjust to fit RAM layout.
 **********************************************************************/
#define MMU_PAGE_POOL_COUNT     256U

/**********************************************************************
 * @brief Physical base address of the page pool.
 *        Placed after kernel heap: 0x45120000 + 0x10000 = 0x45130000
 **********************************************************************/
#define MMU_PAGE_POOL_BASE      0x45130000U

/**********************************************************************
 * @brief Initializes the static page frame pool.
 *        Must be called before mmu_init() or mmu_map_page().
 *
 * @return None
 **********************************************************************/
extern void mmu_page_init(void);

/**********************************************************************
 * @brief Allocates one physical page frame (4KB, zeroed).
 *
 * @return Physical address of the allocated frame, or NULL_ADDR on
 *         exhaustion.
 **********************************************************************/
extern addr_t mmu_page_alloc(void);

/**********************************************************************
 * @brief Frees a previously allocated page frame.
 *
 * @param pa Physical address returned by mmu_page_alloc().
 * @return None
 **********************************************************************/
extern void mmu_page_free(const addr_t pa);

#endif /* __MMU_PAGE_H__ */
