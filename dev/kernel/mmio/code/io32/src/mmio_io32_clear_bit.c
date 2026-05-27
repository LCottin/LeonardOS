#include "mmio_io32_krn.h"

void mmio_io32_clear_bit(ptr_t addr, const uint32_t bit)
{
    if (bit < 32U)
    {
        uint32_t val = *(volatile uint32_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint32_t *)addr = val;
    }
}
