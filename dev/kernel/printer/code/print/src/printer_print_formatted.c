#include "printer_krn.h"
#include "printer_stream.h"

void printer_print_formatted(const char *format, ...)
{
    va_list args;

    va_start(args, format);

    formatter_parse(&printer_stream_string, format, args);

    va_end(args);
}
