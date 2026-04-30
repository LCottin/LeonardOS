#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "memory_ops_usr.h"

void mmu_map_init_kernel_l0(void)
{
    g_p_mmu_kernel_l0 = (uint64_t *)&__page_pool_start;
    memory_ops_utils_set(g_p_mmu_kernel_l0, 0, K_MMU_TABLE_ENTRIES * sizeof(uint64_t));
}
