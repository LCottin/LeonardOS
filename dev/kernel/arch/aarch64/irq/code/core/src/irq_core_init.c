#include "irq_krn.h"
#include "irq_core_prv.h"
#include "gic_krn.h"
#include "types_usr.h"

void irq_core_init(void)
{
    for (size_t idx = 0; idx < K_IRQ_CORE_MAX_IRQ; idx++)
    {
        g_irq_handlers[idx] = NULL_PTR;
    }

    gic_init();
}
