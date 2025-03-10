#include "serial_krn.h"
#include "uart_krn.h"

void serial_print_string(const char_t *str)
{
    /* Loop until end of string */
    while (*str)
    {
        uart_write_byte(*str++);
    }
}
