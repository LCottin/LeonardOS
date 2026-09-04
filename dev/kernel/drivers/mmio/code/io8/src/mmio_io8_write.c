#include "mmio_io8_krn.h"

void mmio_io8_write(ptr_t addr, const uint8_t value)
{
    *((volatile uint8_t *)addr) = value;
}
