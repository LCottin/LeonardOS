#include "libtest.h"

void libtest_memcpy(ptr_t dest, cptr_t src, const size_t size)
{
    uint8_t *d       = (uint8_t *)dest;
    const uint8_t *s = (const uint8_t *)src;

    for (size_t i = 0; i < size; i++)
    {
        d[i] = s[i];
    }
}
