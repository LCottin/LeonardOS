#include "printer_stream.h"
#include "printer_krn.h"

formatter_stream_t printer_stream_string =
{
    .write_char = &printer_print_char,
    .context    = NULL_PTR,
};
