#include "memory_stream_prv.h"

void memory_stream_write_byte(const byte_t byte, stream_t *stream)
{
    memory_stream_context_t *context = (memory_stream_context_t *)stream->context;

    if (context->length < (MEMORY_STREAM_BUFFER_SIZE - 1))
    {
        context->buffer[context->length] = byte;
        context->length++;
    }
}
