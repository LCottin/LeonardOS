#include "printer_krn.h"
#include "formatter_krn.h"
#include "stream_krn.h"

void printer_print_formatted(const char *format, ...)
{
    va_list args;
    stream_t *stream = printer_stream_get();

    va_start(args, format);

    formatter_parse(stream, format, args);

    va_end(args);
}
