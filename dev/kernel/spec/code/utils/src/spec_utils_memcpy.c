#include "spec_utils_krn.h"

void spec_utils_memcpy(ptr_t dest, cptr_t src, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ((uint8_t *)dest)[i] = ((const uint8_t *)src)[i];
    }
}
