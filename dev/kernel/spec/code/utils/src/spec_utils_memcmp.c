#include "spec_utils_krn.h"

int32_t spec_utils_memcmp(cptr_t ptr1, cptr_t ptr2, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        const uint8_t byte1 = ((const uint8_t *)ptr1)[i];
        const uint8_t byte2 = ((const uint8_t *)ptr2)[i];

        if (byte1 != byte2)
        {
            return (byte1 < byte2) ? -1 : 1;
        }
    }

    return 0;
}
