#include "memory.h"

void memcpy(void *dest, const void *src, const int size)
{
    unsigned char *d       = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    int sizeToCopy         = size;

    while(sizeToCopy--)
    {
        *d++ = *s++;
    }
}
