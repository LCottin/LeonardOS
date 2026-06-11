#include "gic_dist.h"
#include "mmio_io8_krn.h"
#include "types_usr.h"

void gic_dist_route_to_cpu(const uint32_t id, const uint8_t cpu_mask)
{
    mmio_io8_write((ptr_t)GICD_ITARGETSR(id), cpu_mask);
}
