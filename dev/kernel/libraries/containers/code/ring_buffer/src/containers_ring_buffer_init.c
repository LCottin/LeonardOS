#include "containers_ring_buffer_usr.h"

void containers_ring_buffer_init(ring_buffer_t *rb, ptr_t buffer, const size_t capacity, const size_t element_size)
{
    rb->buffer       = buffer;
    rb->capacity     = capacity;
    rb->element_size = element_size;
    rb->size         = 0;
    rb->tail         = 0;
    rb->head         = 0;
}
