#include "libuser_usr.h"
#include "syscall_krn.h"
#include "printer_krn.h"
#include "formatter_krn.h"
#include "strings_ops_usr.h"

void user_print_formatted(const char_t *format, ...)
{
    va_list args;
    stream_t *stream = printer_stream_get();

    va_start(args, format);
    formatter_parse(stream, format, args);
    va_end(args);

    syscall_request_t request =
    {
        .syscall_id = SYSCALL_PRINT_FORMATTED,
        .flags      = 0,
        .input =
        {
            .buffer = stream->context,
            .size   = string_ops_len((const char_t *)stream->context)
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size   = 0
        }
    };

    syscall_handler(&request);
}
