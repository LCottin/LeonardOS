#include "console_ctx.h"
#include "console_irq.h"
#include "console_ctx_prv.h"
#include "console_krn.h"
#include "irq_krn.h"

void console_ctx_init(void)
{
    containers_ring_buffer_init(
        &console_ring_buffer,
        console_buffer,
        CONSOLE_BUFFER_SIZE,
        sizeof(console_buffer[0]));

    /* Register RX interruption callback */
    irq_core_register(K_CONSOLE_IRQ_RX_NB, &console_irq_rx);
}
