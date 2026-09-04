#include "printer_stream_prv.h"
#include "uart_krn.h"

void printer_stream_print_byte(const byte_t c, stream_t *stream)
{
    (void)stream;   /* Unused parameter */

    uart_write_byte(c);
}
