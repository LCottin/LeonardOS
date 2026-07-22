#include "uart_krn.h"
#include "uart_ctx.h"
#include "uart_ctx_prv.h"
#include "uart_irq.h"
#include "mmio_io8_krn.h"
#include "mmio_io32_krn.h"
#include "irq_krn.h"

void uart_ctx_init(void)
{
    /* Enable the UART itself for TX and RX before touching interrupts */
    const uint32_t cr_value = mmio_io32_read((ptr_t)K_UART_CR_ADDR);
    mmio_io32_write((ptr_t)K_UART_CR_ADDR,
                    cr_value | K_UART_CR_UARTEN | K_UART_CR_TXE | K_UART_CR_RXE);

    /* Get current value of UARTIMSC register */
    const uint8_t imsc_value = mmio_io8_read((ptr_t)K_UART_IMSC_ADDR);

    /* Enable RX and RX timeout interrupts */
    mmio_io8_write((ptr_t)K_UART_IMSC_ADDR, imsc_value | K_UART_IMSC_RXIM | K_UART_IMSC_RXTO);

    /* Register RX interruption callback */
    irq_core_register(K_UART_IRQ_RX_NB, &uart_irq_rx);
}
