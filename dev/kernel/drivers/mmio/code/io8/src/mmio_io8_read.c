#include "mmio_io8_krn.h"

uint8_t mmio_io8_read(cptr_t addr)
{
    return *((volatile const uint8_t *)addr);
}
