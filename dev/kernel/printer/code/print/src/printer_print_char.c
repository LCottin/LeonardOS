#include "printer_krn.h"
#include "uart_krn.h"

void printer_print_char(const char_t c, const stream_t *stream)
{
    (void)stream;   /* Unused parameter */

    uart_write_byte(c);
}
