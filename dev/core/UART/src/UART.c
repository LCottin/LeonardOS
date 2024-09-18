#include "UARTPrv.h"
#include "UART.h"

void UARTSendByte(const char_t c)
{
    *((volatile uint32_t *)QEMU_UART_ADDR) = c;
}
