#include "gic_cpu.h"
#include "gic_dist.h"
#include "gic_krn.h"
#include "mmio_io32_krn.h"
#include "types_usr.h"

void gic_init(void)
{
    /* Disable the GIC */
    mmio_io32_write((ptr_t)GICD_CTRL, FALSE);
    mmio_io32_write((ptr_t)GICC_CTRL, FALSE);

    /* Set the priority mask */
    mmio_io32_write((ptr_t)GICC_PMR, 0xFFU);

    /* Enable the GIC */
    mmio_io32_write((ptr_t)GICC_CTRL, TRUE);
    mmio_io32_write((ptr_t)GICD_CTRL, TRUE);
}
