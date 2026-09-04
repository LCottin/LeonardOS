#include "mmio_io64_krn.h"

void mmio_io64_write(ptr_t addr, const uint64_t value)
{
    *((volatile uint64_t *)addr) = value;
}
