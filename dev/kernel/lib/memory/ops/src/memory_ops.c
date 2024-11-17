#include "memory_ops_lib.h"
#include "memory_alloc_lib.h"

void *memcpy(void *dest, const void *src, size_t n) __attribute__((alias("memory_ops_copy")));

ptr_t memory_ops_copy(ptr_t dest, cptr_t src, const size_t size)
{
    if (size > 0)
    {
        size_t remaining_size = size;

        /* Convert to byte pointers */
        byte_t *d = (byte_t *)dest;
        byte_t *s = (byte_t *)src;

        /* Align both source and destination */
        while ((((addr_t)d & (ALIGNMENT - 1U)) != 0 || ((addr_t)s & (ALIGNMENT - 1U)) != 0) && (remaining_size > 0))
        {
            *d++ = *s++;
            remaining_size--;
        }

        /* Bulk copy only when both addresses are aligned */
        if ((((addr_t)d & (ALIGNMENT - 1U)) == 0) && (((addr_t)s & (ALIGNMENT - 1U)) == 0))
        {
            uint64_t *d_chunk = (uint64_t *)d;
            uint64_t *s_chunk = (uint64_t *)s;

            while (remaining_size >= ALIGNMENT)
            {
                *d_chunk++ = *s_chunk++;
                remaining_size -= ALIGNMENT;
            }

            /* Update pointers for remaining data */
            d = (byte_t *)d_chunk;
            s = (byte_t *)s_chunk;
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

ptr_t memory_ops_set(ptr_t dest, const int32_t value, const size_t size)
{
    if (size > 0)
    {
        size_t remaining_size = size;

        /* Set data until destination address is aligned */
        byte_t *d = (byte_t *)dest;

        while((((addr_t)dest & (ALIGNMENT - 1U)) != 0) && (remaining_size > 0))
        {
            *d++ = (uint8_t)value;
            remaining_size--;
        }

        /* Create a ALIGNMENT-chunk with data */
        uint64_t chunk = (uint8_t)value;
        chunk         |= chunk <<  8U;
        chunk         |= chunk << 16U;
        chunk         |= chunk << 32U;

        /* Set data in 8-byte chunks */
        uint64_t *d_chunk = (uint64_t *)d;

        while(remaining_size >= ALIGNMENT)
        {
            *d_chunk++      = chunk;
            remaining_size -= ALIGNMENT;
        }

        /* Set remaining bytes one by one */
        d = (byte_t *)d_chunk;
        while(remaining_size > 0)
        {
            *d++ = (uint8_t)value;
            remaining_size--;
        }
    }

    return dest;
}
