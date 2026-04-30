#include "mmu_page.h"
#include "mmu_page_prv.h"
#include "memory_ops_usr.h"

void mmu_page_init(void)
{
    memory_ops_utils_set(g_mmu_page_bitmap, 0, sizeof(g_mmu_page_bitmap));
}
