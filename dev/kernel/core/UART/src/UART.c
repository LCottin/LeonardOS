#include "UART_prv.h"
#include "UART.h"

void UART_write_byte(const char_t c)
{
    *((volatile uint32_t *)K_UART_QEMU_VIRT_ADDR) = c;
}
