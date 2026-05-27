#include "mmio_io64_krn.h"

uint64_t mmio_io64_read(cptr_t addr)
{
    return *((volatile const uint64_t *)addr);
}
