#include "memory_stream_prv.h"

void memory_stream_reset(stream_t *stream)
{
    memory_stream_context_t *context = (memory_stream_context_t *)stream->context;
    context->length = 0;
}
