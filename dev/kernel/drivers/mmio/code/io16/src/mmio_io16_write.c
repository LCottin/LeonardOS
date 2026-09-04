#include "mmio_io16_krn.h"

void mmio_io16_write(ptr_t addr, const uint16_t value)
{
    *((volatile uint16_t *)addr) = value;
}
