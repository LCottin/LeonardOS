#include "mmio_io32_krn.h"

void mmio_io32_write(ptr_t addr, const uint32_t value)
{
    *((volatile uint32_t *)addr) = value;
}
