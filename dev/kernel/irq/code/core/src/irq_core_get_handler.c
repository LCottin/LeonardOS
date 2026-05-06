#include "irq_core.h"
#include "irq_krn.h"
#include "irq_core_prv.h"
#include "types_usr.h"

irq_handler_t irq_core_get_handler(const uint32_t id)
{
    irq_handler_t handler = (id < K_IRQ_CORE_MAX_IRQ) ? g_irq_handlers[id] : NULL_PTR;

    return handler;
}
