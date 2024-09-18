#include "kernelPrint.h"
#include "UART.h"

void kernelPrint(const char_t *str)
{
    /* Loop until end of string */
    while (*str)
    {
        UARTSendByte(*str++);
    }
}
