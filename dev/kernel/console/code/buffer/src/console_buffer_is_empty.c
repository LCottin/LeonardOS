#include "console_krn.h"
#include "console_ctx.h"
#include "containers_ring_buffer_usr.h"

bool_t console_buffer_is_empty(void)
{
    return containers_ring_buffer_is_empty(&console_ring_buffer);
}
