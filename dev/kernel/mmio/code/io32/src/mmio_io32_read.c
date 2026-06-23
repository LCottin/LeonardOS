#include "mmio_io32_krn.h"

uint32_t mmio_io32_read(cptr_t addr)
{
    return *((volatile const uint32_t *)addr);
}
