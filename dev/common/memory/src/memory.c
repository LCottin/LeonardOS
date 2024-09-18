#include "memory.h"

ptr_t memcpy(ptr_t dest, cptr_t src, const size_t size)
{
    uint8_t *d        = (uint8_t *)dest;
    const uint8_t *s  = (const uint8_t *)src;
    size_t sizeToCopy = size;

    while(sizeToCopy--)
    {
        *d++ = *s++;
    }

    return dest;
}

ptr_t memset(ptr_t dest, const int32_t value, const size_t size)
{
    uint8_t *d       = (uint8_t *)dest;
    size_t sizeToFill = size;

    while(sizeToFill--)
    {
        *d++ = (uint8_t)value;
    }

    return dest;
}
