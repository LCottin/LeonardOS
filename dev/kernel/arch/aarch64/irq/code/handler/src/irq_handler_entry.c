#include "irq_krn.h"
#include "irq_handler_prv.h"

void irq_handler_entry(void)
{
    irq_handler();
}
