#include "UARTPrv.h"
#include "UART.h"

void UARTSendByte(const char c)
{
    *((volatile unsigned int *)QEMU_UART_ADDR) = c;
}
