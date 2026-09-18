#include "printer_stream_prv.h"
#include "printer_krn.h"

stream_t printer_stream =
{
    .write_byte = &printer_stream_print_byte,
    .reset      = NULL_PTR,
    .context    = NULL_PTR,
};
