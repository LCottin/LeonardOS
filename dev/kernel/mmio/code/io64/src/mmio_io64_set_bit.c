#include "mmio_io64_krn.h"

void mmio_io64_set_bit(ptr_t addr, const uint64_t bit)
{
    if (bit < 64ULL)
    {
        uint64_t val = *(volatile uint64_t *)addr;
        val |= (1 << bit);
        *(volatile uint64_t *)addr = val;
    }
}
