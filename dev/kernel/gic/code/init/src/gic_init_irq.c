#include "gic_krn.h"
#include "gic_dist.h"
#include "types_usr.h"

void gic_init_irq(const uint32_t id)
{
    gic_dist_route_to_cpu(id, 0x1);
    gic_dist_enable_irq(id);
}
