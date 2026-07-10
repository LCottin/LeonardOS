#include "console_ctx.h"
#include "console_ctx_prv.h"
#include "console_krn.h"

void console_ctx_init(void)
{
    containers_ring_buffer_init(
        &console_ring_buffer,
        console_buffer,
        CONSOLE_BUFFER_SIZE,
        sizeof(console_buffer[0]));
}
