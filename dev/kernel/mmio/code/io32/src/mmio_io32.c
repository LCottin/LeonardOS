#include "mmio_io32_krn.h"

void mmio_io32_write(ptr_t addr, const uint32_t value)
{
    *((volatile uint32_t *)addr) = value;
}

uint32_t mmio_io32_read(cptr_t addr)
{
    return *((volatile const uint32_t *)addr);
}

void mmio_io32_set_bit(ptr_t addr, const uint32_t bit)
{
    if (bit < 32U)
    {
        uint32_t val = *(volatile uint32_t *)addr;
        val |= (1 << bit);
        *(volatile uint32_t *)addr = val;
    }
}

void mmio_io32_clear_bit(ptr_t addr, const uint32_t bit)
{
    if (bit < 32U)
    {
        uint32_t val = *(volatile uint32_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint32_t *)addr = val;
    }
}

void mmio_io32_toggle_bit(ptr_t addr, const uint32_t bit)
{
    if (bit < 32U)
    {
        uint32_t val = *(volatile uint32_t *)addr;
        val ^= (1 << bit);
        *(volatile uint32_t *)addr = val;
    }
}
