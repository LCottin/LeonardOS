#ifndef __UART_CTX_PRV_H__
#define __UART_CTX_PRV_H__

#include "uart_ctx.h"

/**********************************************************************
 * @brief Virtual address for interrupt mask set/clear register
 **********************************************************************/
#define K_UART_IMSC_ADDR (K_UART_QEMU_VIRT_ADDR + 0x38U)


/**********************************************************************
 * @brief Mask for RX interrupts in the UARTIMSC register
 **********************************************************************/
#define K_UART_IMSC_RXIM (1 << 4U)


/**********************************************************************
 * @brief Mask for RX interrupts timeout in the UARTIMSC register
 **********************************************************************/
#define K_UART_IMSC_RXTO (1 << 6U)

// kernel/uart/code/ctx/src/uart_ctx_prv.h
#define K_UART_CR_ADDR   (K_UART_QEMU_VIRT_ADDR + 0x30U)
#define K_UART_CR_UARTEN (1 << 0U)
#define K_UART_CR_TXE    (1 << 8U)
#define K_UART_CR_RXE    (1 << 9U)

#endif /* __UART_CTX_PRV_H__ */
