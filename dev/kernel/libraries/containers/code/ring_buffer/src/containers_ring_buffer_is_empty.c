#include "containers_ring_buffer_usr.h"

bool_t containers_ring_buffer_is_empty(const ring_buffer_t *rb)
{
    return (bool_t)(rb->size == 0);
}
