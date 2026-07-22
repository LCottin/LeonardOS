#include "printer_krn.h"
#include "uart_krn.h"

void printer_print_char(const char_t c)
{
    uart_write_byte(c);
}
