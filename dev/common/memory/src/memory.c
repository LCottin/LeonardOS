#include "memory.h"

void *memcpy(void *dest, const void *src, const int size)
{
    unsigned char *d       = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    int sizeToCopy         = size;

    while(sizeToCopy--)
    {
        *d++ = *s++;
    }

    return dest;
}

void *memset(void *dest, const int value, const int size)
{
    unsigned char *d = (unsigned char *)dest;
    int sizeToFill   = size;

    while(sizeToFill--)
    {
        *d++ = (unsigned char)value;
    }

    return dest;
}
