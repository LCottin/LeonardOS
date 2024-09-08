#include "kernelPrint.h"
#include "UART.h"

void kernelPrint(const char *str)
{
    /* Loop until end of string */
    while (*str)
    {
        UARTSendByte(*str++);
    }
}