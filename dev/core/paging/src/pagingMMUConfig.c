#include "paging.h"
#include "pagingPrv.h"

// Function to set up page tables and enable the MMU
void pagingMMUConfig() {
    // Map some pages for testing purposes
    pagingMapPage((uint64_t*)&l1_table, 0x00000000, 0x00000000, PTE_RW); // Map virtual 0x0000 to physical 0x0000
    pagingMapPage((uint64_t*)&l1_table, 0x10000000, 0x10000000, PTE_RW); // Map virtual 0x10000000 to physical 0x10000000

    // Enable the MMU
    pagingEnableMmu();
}
