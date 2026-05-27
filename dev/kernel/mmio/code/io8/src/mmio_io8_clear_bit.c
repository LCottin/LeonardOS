#include "mmio_io8_krn.h"

void mmio_io8_clear_bit(ptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}
