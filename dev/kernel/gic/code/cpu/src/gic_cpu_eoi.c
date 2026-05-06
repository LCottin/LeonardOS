#include "gic_cpu.h"
#include "gic_krn.h"
#include "mmio_io32_krn.h"
#include "types_usr.h"

void gic_cpu_eoi(const uint32_t irq)
{
    mmio_io32_write((ptr_t)GICC_EOIR, irq);
}
