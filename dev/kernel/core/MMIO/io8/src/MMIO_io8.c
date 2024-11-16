#include "MMIO_io8.h"

void mmio_io8_write(cptr_t addr, const uint8_t value)
{
    *((volatile uint8_t *)addr) = value;
}

uint8_t mmio_io8_read(cptr_t addr)
{
    return *((volatile uint8_t *)addr);
}

void mmio_io8_set_bit(cptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val |= (1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}

void mmio_io8_clear_bit(cptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}

void mmio_io8_toggle_bit(cptr_t addr, const uint8_t bit)
{
    if (bit < 8U)
    {
        uint8_t val = *(volatile uint8_t *)addr;
        val ^= (1 << bit);
        *(volatile uint8_t *)addr = val;
    }
}
