#include "pagingPrv.h"


// Function to map a virtual address to a physical address with specific permissions
void pagingMapPage(uint64_t *table, uint64_t virtual_addr, uint64_t physical_addr, uint64_t flags)
{
    // Extract indices for each level of page tables from the virtual address
    uint64_t l1_index = (virtual_addr >> 39) & 0x1FF;  // Top 9 bits
    uint64_t l2_index = (virtual_addr >> 30) & 0x1FF;  // Next 9 bits
    uint64_t l3_index = (virtual_addr >> 21) & 0x1FF;  // Next 9 bits

    // Level 1 table entry points to the Level 2 table
    if (!(l1_table[l1_index] & PTE_VALID))
    {
        l1_table[l1_index] = (uint64_t)&l2_table | PTE_VALID | PTE_RW;
    }

    // Level 2 table entry points to the Level 3 table
    if (!(l2_table[l2_index] & PTE_VALID))
    {
        l2_table[l2_index] = (uint64_t)&l3_table | PTE_VALID | PTE_RW;
    }

    // Level 3 table maps the virtual address to the physical address
    l3_table[l3_index] = physical_addr | flags | PTE_VALID;
}
