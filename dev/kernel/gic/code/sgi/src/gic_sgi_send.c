#include "gic_krn.h"
#include "gic_cpu.h"
#include "gic_dist.h"
#include "mmio_io32_krn.h"
#include "types_usr.h"

void gic_sgi_send(const uint32_t id)
{
    /* Target CPU: self (bit 16), SGI ID: id (bits [3:0]) */
    const uint32_t value = (1U << 16U) | (id & 0xFU);
    mmio_io32_write((ptr_t)GICD_SGIR, value);
}
