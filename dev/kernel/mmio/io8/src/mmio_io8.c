#include "mmio_io8_krn.h"

void mmio_io8_write(ptr_t addr, const uint8_t value)
{
    *((volatile uint8_t *)addr) = value;
}

uint8_t mmio_io8_read(cptr_t addr)
{
    return *((volatile const uint8_t *)addr);
}

void mmio_io8_set_bit(ptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val |= (1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}

void mmio_io8_clear_bit(ptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}

void mmio_io8_toggle_bit(ptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val ^= (1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}
