#include "mmu_map.h"
#include "mmu_map_prv.h"
#include "mmu_page.h"

void mmu_map_boot(void)
{
    /* .text — rx */
    mmu_map_region(
        (addr_t)&__text_start,
        (uint32_t)((addr_t)&__text_end - (addr_t)&__text_start),
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_X);

    /* .rodata — r */
    mmu_map_region(
        (addr_t)&__rodata_start,
        (uint32_t)((addr_t)&__rodata_end - (addr_t)&__rodata_start),
        K_MMU_MAP_PERM_R);

    /* .data — rw */
    mmu_map_region(
        (addr_t)&__data_start,
        (uint32_t)((addr_t)&__data_end - (addr_t)&__data_start),
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W);

    /* .bss — rw */
    mmu_map_region(
        (addr_t)&__bss_start,
        (uint32_t)((addr_t)&__bss_end - (addr_t)&__bss_start),
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W);

    /* stack — rw */
    mmu_map_region(
        (addr_t)&__stack_start,
        (uint32_t)((addr_t)&__stack_end - (addr_t)&__stack_start),
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W);

    /* page pool — rw */
    mmu_map_region(
        (addr_t)&__page_pool_start,
        (uint32_t)((addr_t)&__page_pool_end - (addr_t)&__page_pool_start),
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W);

    /* UART MMIO — device rw */
    mmu_map_region(
        (addr_t)K_MMU_REGION_UART_BASE,
        K_MMU_REGION_UART_SIZE,
        K_MMU_MAP_PERM_R | K_MMU_MAP_PERM_W | K_MMU_MAP_PERM_DEVICE);
}
