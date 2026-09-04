#include "memory_stream_prv.h"
#include "memory_krn.h"

stream_t *memory_stream_get(void)
{
    return &memory_stream;
}
