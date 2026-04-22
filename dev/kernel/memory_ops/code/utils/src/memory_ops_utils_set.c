#include "memory_ops_usr.h"
#include "memory_krn.h"

ptr_t memory_ops_utils_set(ptr_t dest, const int32_t value, const size_t size)
{
    if (size > 0)
    {
        size_t remaining_size = size;

        /* Set data until destination address is aligned */
        byte_t *d = (byte_t *)dest;

        while((((addr_t)dest & (MEMORY_ALIGNMENT - 1U)) != 0) && (remaining_size > 0))
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

        while(remaining_size >= MEMORY_ALIGNMENT)
        {
            *d_chunk++      = chunk;
            remaining_size -= MEMORY_ALIGNMENT;
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
