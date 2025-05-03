#include "printer_krn.h"
#include "uart_krn.h"

void printer_print_string(const char_t *str)
{
    while (*str)
    {
        uart_write_byte(*str++);
    }
}
