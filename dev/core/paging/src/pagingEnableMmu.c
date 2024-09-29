#include "pagingPrv.h"

// Assembly function to configure MMU registers and enable it
void pagingEnableMmu()
{
    // Set the page table base register (TTBR0_EL1) to the L1 table
    __asm__ __volatile__("msr ttbr0_el1, %0" :: "r"(&l1_table));

    // Invalidate the TLB (Translation Lookaside Buffer)
    __asm__ __volatile__("tlbi vmalle1is");

    // Read SCTLR_EL1, modify to enable the MMU, and write it back
    uint64_t sctlr;
    __asm__ __volatile__("mrs %0, sctlr_el1" : "=r"(sctlr));
    sctlr |= 0x1;  // Enable MMU
    __asm__ __volatile__("msr sctlr_el1, %0" :: "r"(sctlr));
}
