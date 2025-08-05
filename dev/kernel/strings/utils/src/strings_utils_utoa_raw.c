#include "strings_utils_prv.h"

size_t strings_utils_utoa_raw(const printer_base_t base, const uint64_t value, char_t *str)
{
    const char_t digits[64] = "0123456789abcdef";
    size_t length           = 0;
    uint64_t raw_value      = value;

    if (raw_value == 0)
    {
        str[length++] = '0';
    }
    else
    {
        /* Nothing to do */
    }

    while (raw_value > 0)
    {
        str[length++] = digits[raw_value % base];
        raw_value /= base;
    }

    return length;
}
