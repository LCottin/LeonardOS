#include "printer_stream_prv.h"
#include "printer_krn.h"

stream_t *printer_stream_get(void)
{
    return &printer_stream;
}
