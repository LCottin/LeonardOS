#include "memory_ops_lib.h"
#include "memory_alloc_lib.h"

void *memcpy(void *dest, const void *src, size_t n) __attribute__((alias("memory_ops_copy")));

ptr_t memory_ops_copy(ptr_t dest, cptr_t src, const size_t size)
{
    byte_t *d           = (byte_t *)dest;
    const byte_t *s     = (const byte_t *)src;
    size_t size_to_copy = size;

    while(size_to_copy--)
    {
        *d++ = *s++;
    }

    return dest;
}

ptr_t memory_ops_set(ptr_t dest, const int32_t value, const size_t size)
{
    byte_t *d           = (byte_t *)dest;
    size_t size_to_fill = size;

    while(size_to_fill--)
    {
        *d++ = (uint8_t)value;
    }

    return dest;
}
