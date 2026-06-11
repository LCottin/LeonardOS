#include "gic_cpu.h"
#include "gic_krn.h"
#include "mmio_io32_krn.h"
#include "types_usr.h"

uint32_t gic_cpu_ack(void)
{
    const uint32_t irq = mmio_io32_read((cptr_t)GICC_IAR);

    return irq;
}
