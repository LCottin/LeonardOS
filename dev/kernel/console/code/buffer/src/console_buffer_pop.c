#include "console_krn.h"
#include "console_ctx.h"
#include "containers_ring_buffer_usr.h"

char_t console_buffer_pop(void)
{
    cptr_t *ptr = containers_ring_buffer_pop(&console_ring_buffer);
    char_t c;

    if (ptr != NULL_PTR)
    {
        c = *(char_t *)ptr;
    }
    else
    {
        c = '\0';
    }

    return c;
}
