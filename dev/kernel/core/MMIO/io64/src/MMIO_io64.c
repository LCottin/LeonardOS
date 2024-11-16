#include "MMIO_io64.h"

void mmio_io64_write(cptr_t addr, const uint64_t value)
{
    *((volatile uint64_t *)addr) = value;
}

uint64_t mmio_io64_read(cptr_t addr)
{
    return *((volatile uint64_t *)addr);
}

void mmio_io64_set_bit(cptr_t addr, const uint64_t bit)
{
    if (bit < 64ULL)
    {
        uint64_t val = *(volatile uint64_t *)addr;
        val |= (1 << bit);
        *(volatile uint64_t *)addr = val;
    }
}

void mmio_io64_clear_bit(cptr_t addr, const uint64_t bit)
{
    if (bit < 64ULL)
    {
        uint64_t val = *(volatile uint64_t *)addr;
        val &= ~(1 << bit);
        *(volatile uint64_t *)addr = val;
    }
}

void mmio_io64_toggle_bit(cptr_t addr, const uint64_t bit)
{
    if (bit < 64ULL)
    {
        uint64_t val = *(volatile uint64_t *)addr;
        val ^= (1 << bit);
        *(volatile uint64_t *)addr = val;
    }
}
