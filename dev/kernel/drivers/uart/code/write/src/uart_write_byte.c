#include "uart_ctx.h"
#include "uart_krn.h"
#include "mmio_io8_krn.h"

void uart_write_byte(const char_t c)
{
    mmio_io8_write((ptr_t)K_UART_QEMU_VIRT_ADDR, c);
}
