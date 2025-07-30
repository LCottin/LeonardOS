#include "strings_utils_usr.h"

void strings_utils_reverse(char_t *str, const size_t length)
{
    if (length > 0)
    {
        uint32_t start = 0;
        uint32_t end   = length - 1U;

        while (start < end)
        {
            char_t temp = str[start];
            str[start]  = str[end];
            str[end]    = temp;
            start++;
            end--;
        }
    }
    else
    {
        /* Nothing to do */
    }
}
