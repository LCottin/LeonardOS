#include "memory_ops_usr.h"

int32_t memory_ops_utils_cmp(cptr_t src1, cptr_t src2, const size_t size)
{
    size_t  length = 0;
    int32_t to_return;

    const byte_t *ptr1 = src1;
    const byte_t *ptr2 = src2;

    /* Loop until maximum size is reached or a byte differs */
    while ((length < size) && (*ptr1 == *ptr2))
    {
        ptr1++;
        ptr2++;
        length++;
    }

    if (length == size)
    {
        to_return = 0;
    }
    else
    {
        to_return = (uint8_t)*ptr1 - (uint8_t)*ptr2;
    }

    return to_return;
}
