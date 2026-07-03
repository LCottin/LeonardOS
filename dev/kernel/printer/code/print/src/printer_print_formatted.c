#include "printer_krn.h"

void printer_print_formatted(const char *format, ...)
{
    va_list args;
    formatter_stream_t *stream = print_stream_get();

    va_start(args, format);

    formatter_parse(stream, format, args);

    va_end(args);
}
