#include "containers_ring_buffer_usr.h"

ptr_t containers_ring_buffer_pop(ring_buffer_t *rb)
{
    const bool_t is_empty = containers_ring_buffer_is_empty(rb);
    ptr_t pop;

    if (is_empty == FALSE)
    {
        pop = (uint8_t *)rb->buffer + (rb->tail * rb->element_size);

        rb->tail = (rb->tail + 1U) % rb->capacity;
        rb->size = (rb->size > 0) ? (rb->size - 1U) : rb->size;
    }
    else
    {
        pop = NULL_PTR;
    }

    return pop;
}
