#include "mmu_map.h"
#include "mmu_map_prv.h"

addr_t mmu_map_get_kernel_l0(void)
{
    return (addr_t)g_p_mmu_kernel_l0;
}
