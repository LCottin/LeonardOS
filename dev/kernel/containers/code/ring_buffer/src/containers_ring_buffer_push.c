#include "containers_ring_buffer_usr.h"
#include "memory_ops_usr.h"

void containers_ring_buffer_push(ring_buffer_t *rb, cptr_t element)
{
    memory_ops_utils_copy(
        (uint8_t *)rb->buffer + (rb->head * rb->element_size),
        element,
        rb->element_size);

    if (rb->size == rb->capacity)
    {
        /* Buffer is full: the write above overwrote the oldest element,
         * so the tail must advance too, otherwise pop() would return
         * the just-overwritten (newest) slot */
        rb->tail = (rb->tail + 1U) % rb->capacity;
    }

    rb->head = (rb->head + 1U) % rb->capacity;
    rb->size = (rb->size == rb->capacity) ? rb->capacity : (rb->size + 1U);
}
