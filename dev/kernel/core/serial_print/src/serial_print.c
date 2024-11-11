#include "serial_print.h"
#include "UART.h"

void serial_print_string(const char_t *str)
{
    /* Loop until end of string */
    while (*str)
    {
        UART_write_byte(*str++);
    }
}
