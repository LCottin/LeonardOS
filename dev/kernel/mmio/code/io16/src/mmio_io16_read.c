#include "mmio_io16_krn.h"

uint16_t mmio_io16_read(cptr_t addr)
{
    return *((volatile const uint16_t *)addr);
}
