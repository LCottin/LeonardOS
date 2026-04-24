#include "mmu_page.h"
#include "memory_ops_usr.h"

/**********************************************************************
 * @brief Bitmap tracking free (0) / used (1) frames.
 *        One bit per frame; 256 frames -> 32 bytes.
 **********************************************************************/
static uint8_t _mmu_page_bitmap[MMU_PAGE_POOL_COUNT / 8U];

/**********************************************************************
 * @brief Mark a frame index as used.
 **********************************************************************/
static void _mmu_page_bitmap_set(const uint32_t index)
{
    _mmu_page_bitmap[index / 8U] |= (uint8_t)(1U << (index % 8U));
}

/**********************************************************************
 * @brief Mark a frame index as free.
 **********************************************************************/
static void _mmu_page_bitmap_clear(const uint32_t index)
{
    _mmu_page_bitmap[index / 8U] &= (uint8_t)(~(1U << (index % 8U)));
}

/**********************************************************************
 * @brief Test whether a frame index is used.
 **********************************************************************/
static bool_t _mmu_page_bitmap_test(const uint32_t index)
{
    return ((_mmu_page_bitmap[index / 8U] & (uint8_t)(1U << (index % 8U))) != 0U) ? TRUE : FALSE;
}

void mmu_page_init(void)
{
    memory_ops_set(_mmu_page_bitmap, 0, sizeof(_mmu_page_bitmap));
}

addr_t mmu_page_alloc(void)
{
    uint32_t i;

    for (i = 0U; i < MMU_PAGE_POOL_COUNT; i++)
    {
        if (_mmu_page_bitmap_test(i) == FALSE)
        {
            _mmu_page_bitmap_set(i);

            /* Zero the frame before returning it */
            const addr_t pa = (addr_t)(MMU_PAGE_POOL_BASE + (i * MMU_PAGE_SIZE));
            memory_ops_set((ptr_t)pa, 0, MMU_PAGE_SIZE);
            return pa;
        }
    }

    /* Pool exhausted */
    return NULL_ADDR;
}

void mmu_page_free(const addr_t pa)
{
    if ((pa < (addr_t)MMU_PAGE_POOL_BASE) ||
        (pa >= (addr_t)(MMU_PAGE_POOL_BASE + (MMU_PAGE_POOL_COUNT * MMU_PAGE_SIZE))))
    {
        return; /* Out of pool range — ignore */
    }

    const uint32_t index = (uint32_t)((pa - (addr_t)MMU_PAGE_POOL_BASE) / MMU_PAGE_SIZE);
    _mmu_page_bitmap_clear(index);
}
