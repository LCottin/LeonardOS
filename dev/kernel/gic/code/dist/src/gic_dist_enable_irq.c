#include "gic_dist.h"
#include "mmio_io32_krn.h"
#include "types_usr.h"

void gic_dist_enable_irq(const uint32_t id)
{
    const uint32_t reg_index  = id >> 5U;
    const uint32_t reg_offset = id & 0x1FU;

    mmio_io32_write((ptr_t)GICD_ISENABLER(reg_index), (1U << reg_offset));
}
