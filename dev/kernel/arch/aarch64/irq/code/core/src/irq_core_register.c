#include "irq_krn.h"
#include "irq_core_prv.h"
#include "gic_krn.h"
#include "types_usr.h"

void irq_core_register(const uint32_t id, const irq_handler_t handler)
{
    g_irq_handlers[id] = handler;

    gic_cpu_set_priority(id, 0x80U);
    gic_init_irq(id);
}
