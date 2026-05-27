#include "mmio_io64_krn.h"

void mmio_io64_toggle_bit(ptr_t addr, const uint64_t bit)
{
    if (bit < 64ULL)
    {
        uint64_t val = *(volatile uint64_t *)addr;
        val ^= (1ULL << bit);
        *(volatile uint64_t *)addr = val;
    }
}
