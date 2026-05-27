#include "mmio_io16_krn.h"

void mmio_io16_clear_bit(ptr_t addr, const uint16_t bit)
{
    if (bit < 16U)
    {
        uint16_t val = *(volatile uint16_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint16_t *)addr = val;
    }
}
