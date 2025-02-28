#include "MMIO_io16.h"

void mmio_io16_write(ptr_t addr, const uint16_t value)
{
    *((volatile uint16_t *)addr) = value;
}

uint16_t mmio_io16_read(cptr_t addr)
{
    return *((volatile const uint16_t *)addr);
}

void mmio_io16_set_bit(ptr_t addr, const uint16_t bit)
{
    if (bit < 16U)
    {
        uint16_t val = *(volatile uint16_t *)addr;
        val |= (1 << bit);
        *(volatile uint16_t *)addr = val;
    }
}

void mmio_io16_clear_bit(ptr_t addr, const uint16_t bit)
{
    if (bit < 16U)
    {
        uint16_t val = *(volatile uint16_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint16_t *)addr = val;
    }
}

void mmio_io16_toggle_bit(ptr_t addr, const uint16_t bit)
{
    if (bit < 16U)
    {
        uint16_t val = *(volatile uint16_t *)addr;
        val ^= (1 << bit);
        *(volatile uint16_t *)addr = val;
    }
}
