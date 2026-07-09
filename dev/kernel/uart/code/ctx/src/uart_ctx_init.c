#include "uart_krn.h"
#include "uart_ctx.h"
#include "uart_ctx_prv.h"
#include "mmio_io8_krn.h"

void uart_ctx_init(void)
{
    /* Get current value of UARTIMSC register */
    const uint8_t imsc_value = mmio_io8_read((ptr_t)K_UART_IMSC_ADDR);

    /* Enable RX and RX timeout interrupts */
    mmio_io8_write((ptr_t)K_UART_IMSC_ADDR, imsc_value | K_UART_IMSC_RXIM | K_UART_IMSC_RXTO);
}
