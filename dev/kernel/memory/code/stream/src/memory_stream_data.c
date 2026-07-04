#include "memory_stream_prv.h"

memory_stream_context_t g_memory_stream_buffer;

stream_t memory_stream =
{
    .write_byte = &memory_stream_write_byte,
    .reset      = &memory_stream_reset,
    .context    = (ptr_t)&g_memory_stream_buffer,
};
