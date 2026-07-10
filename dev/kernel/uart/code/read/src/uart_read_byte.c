#include "uart_read_prv.h"
#include "uart_krn.h"
#include "mmio_io8_krn.h"

char_t uart_read_byte(void)
{
    return (char_t)mmio_io8_read((cptr_t)K_UART_DR_REGISTER);
}
