#include "mmu_page_prv.h"

uint8_t g_mmu_page_bitmap[MMU_PAGE_POOL_COUNT / sizeof(addr_t)];
