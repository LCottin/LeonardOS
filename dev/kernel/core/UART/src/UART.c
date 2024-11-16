#include "UART_prv.h"
#include "UART.h"
#include "MMIO_io8.h"

void UART_write_byte(const char_t c)
{
    mmio_io8_write((cptr_t)K_UART_QEMU_VIRT_ADDR, c);
}
