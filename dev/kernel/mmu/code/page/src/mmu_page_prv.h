#ifndef __MMU_PAGE_PRV_H__
#define __MMU_PAGE_PRV_H__

#include "types_usr.h"

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
 * @brief Bitmap to track allocated/free pages in the pool.
 *        1 bit per page: 0 = free, 1 = allocated.
 **********************************************************************/
extern uint8_t g_mmu_page_bitmap[MMU_PAGE_POOL_COUNT / sizeof(addr_t)];


#endif /* __MMU_PAGE_PRV_H__ */
