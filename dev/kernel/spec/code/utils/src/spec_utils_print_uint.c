#include "spec_utils_krn.h"
#include "spec_utils_prv.h"

void spec_utils_print_uint(const uint32_t number)
{
    char_t  buf[32];
    int32_t i = 0;

    if (number == 0U)
    {
        spec_utils_print_string("0");
    }
    else
    {
        uint32_t num = number;
        while (num > 0U)
        {
            buf[i++] = (char)('0' + (num % 10U));
            num /= 10U;
        }

        /* Reverse */
        for (int32_t lo = 0, hi = i - 1; lo < hi; lo++, hi--)
        {
            char_t tmp  = buf[lo];
            buf[lo]   = buf[hi];
            buf[hi]   = tmp;
        }
        buf[i] = '\0';

        spec_utils_print_string(buf);
    }
}
