#include "console_ctx.h"
#include "console_ctx_prv.h"

ring_buffer_t console_ring_buffer;
char_t        console_buffer[CONSOLE_BUFFER_SIZE];
