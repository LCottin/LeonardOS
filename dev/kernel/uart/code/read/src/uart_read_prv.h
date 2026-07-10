#ifndef __UART_READ_PRV_H__
#define __UART_READ_PRV_H__

#include "types_usr.h"
#include "uart_ctx.h"

/**********************************************************************
 * @brief UART Data Register (DR) and Flag Register (FR) addresses.
 **********************************************************************/
#define K_UART_DR_REGISTER  K_UART_QEMU_VIRT_ADDR
#define K_UART_FR_REGISTER  (K_UART_QEMU_VIRT_ADDR + 0x18U)


/**********************************************************************
 * @brief Mask to check if the UART FIFO is empty.
 **********************************************************************/
#define K_UART_FIFO_EMPTY_MASK (1 << 4U)


#endif /* __UART_READ_PRV_H__ */
