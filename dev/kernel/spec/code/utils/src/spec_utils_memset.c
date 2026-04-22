#include "spec_utils_krn.h"

void spec_utils_memset(ptr_t dest, const uint8_t c, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ((uint8_t *)dest)[i] = c;
    }
}
