#include "uart_read_prv.h"
#include "uart_krn.h"
#include "mmio_io8_krn.h"

bool_t uart_is_available(void)
{
    const bool_t is_empty = (bool_t)(mmio_io8_read((cptr_t)K_UART_FR_REGISTER) & K_UART_FIFO_EMPTY_MASK);

    return (bool_t)(!is_empty);
}
