#include "irq_core.h"
#include "irq_krn.h"
#include "irq_handler_prv.h"
#include "gic_krn.h"
#include "types_usr.h"
#include "printer_krn.h"

void irq_handler(void)
{
    const uint32_t id     = gic_cpu_ack() & 0x3FFU;
    irq_handler_t handler = irq_core_get_handler(id);

    if (handler != NULL_PTR)
    {
        handler();
    }
    else
    {
        printer_print_formatted("Handler for IRQ %d not found\r\n", id);
    }

    gic_cpu_eoi(id);
}
