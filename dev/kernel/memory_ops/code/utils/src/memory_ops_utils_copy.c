#include "memory_ops_usr.h"
#include "memory_krn.h"

void *memcpy(void *dest, const void *src, size_t n) __attribute__((alias("memory_ops_utils_copy")));

ptr_t memory_ops_utils_copy(ptr_t dest, cptr_t src, const size_t size)
{
    if (size > 0)
    {
        size_t remaining_size = size;

        /* Convert to byte pointers */
        byte_t *d       = (byte_t *)dest;
        const byte_t *s = (const byte_t *)src;

        /* Align both source and destination */
        while (((((addr_t)d & (MEMORY_ALIGNMENT - 1U)) != 0) || ((addr_t)s & (MEMORY_ALIGNMENT - 1U)) != 0) && (remaining_size > 0))
        {
            *d++ = *s++;
            remaining_size--;
        }

        /* Bulk copy only when both addresses are aligned */
        if ((((addr_t)d & (MEMORY_ALIGNMENT - 1U)) == 0) && (((addr_t)s & (MEMORY_ALIGNMENT - 1U)) == 0))
        {
            uint64_t *d_chunk       = (uint64_t *)d;
            const uint64_t *s_chunk = (const uint64_t *)s;

            while (remaining_size >= MEMORY_ALIGNMENT)
            {
                *d_chunk++ = *s_chunk++;
                remaining_size -= MEMORY_ALIGNMENT;
            }

            /* Update pointers for remaining data */
            d       = (byte_t *)d_chunk;
            s = (const byte_t *)s_chunk;
        }

        /* Copy any remaining bytes one by one */
        while (remaining_size > 0)
        {
            *d++ = *s++;
            remaining_size--;
        }
    }

    return dest;
}
