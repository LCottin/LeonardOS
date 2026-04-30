#include "mmu_page.h"
#include "mmu_page_prv.h"
#include "memory_ops_usr.h"

/**********************************************************************
 * @brief Mark a frame index as used.
 **********************************************************************/
static void mmu_page_bitmap_set(const uint32_t index)
{
    g_mmu_page_bitmap[index / 8U] |= (uint8_t)(1U << (index % 8U));
}


/**********************************************************************
 * @brief Test whether a frame index is used.
 **********************************************************************/
static bool_t mmu_page_bitmap_test(const uint32_t index)
{
    return ((g_mmu_page_bitmap[index / 8U] & (uint8_t)(1U << (index % 8U))) != 0U) ? TRUE : FALSE;
}


addr_t mmu_page_alloc(void)
{
    uint32_t idx;
    addr_t   physical_addr;

    idx           = 0;
    physical_addr = NULL_ADDR;

    while ((idx < MMU_PAGE_POOL_COUNT) && (physical_addr == NULL_ADDR))
    {
        if (mmu_page_bitmap_test(idx) == FALSE)
        {
            mmu_page_bitmap_set(idx);

            /* Zero the frame before returning it */
            physical_addr = (addr_t)(MMU_PAGE_POOL_BASE + (idx * MMU_PAGE_SIZE));
            memory_ops_utils_set((ptr_t)physical_addr, 0, MMU_PAGE_SIZE);
        }

        idx += 1U;
    }

    return physical_addr;
}
