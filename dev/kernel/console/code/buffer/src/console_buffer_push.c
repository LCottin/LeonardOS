#include "console_krn.h"
#include "console_ctx.h"
#include "containers_ring_buffer_usr.h"

void console_buffer_push(const char_t c)
{
    containers_ring_buffer_push(&console_ring_buffer, &c);
}
