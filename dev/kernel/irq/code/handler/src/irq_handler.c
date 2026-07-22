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

    printer_print_formatted("Handler for id %d:", id);
    if (handler != NULL_PTR)
    {
        printer_print_formatted("found\r\n");
        handler();
    }
    else
    {
        printer_print_formatted("not found\r\n");
    }

    gic_cpu_eoi(id);
}
