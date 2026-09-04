#include "gic_krn.h"
#include "gic_dist.h"
#include "mmio_io8_krn.h"
#include "types_usr.h"

void gic_cpu_set_priority(const uint32_t id, const uint8_t prio)
{
    mmio_io8_write((ptr_t)GICD_IPRIORITYR(id), prio);
}
