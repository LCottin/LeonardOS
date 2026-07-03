#include "printer_stream_prv.h"
#include "printer_krn.h"

formatter_stream_t *print_stream_get(void)
{
    return &printer_stream_string;
}
