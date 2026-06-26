#include "strings_utils_usr.h"
#include "strings_utils_prv.h"

char_t *strings_utils_utoa(const strings_utils_base_t base, const uint64_t value, char_t *str)
{
    if (str != NULL_PTR)
    {
        size_t str_length = 0;

        if ((base != STRINGS_UTILS_BASE_BINARY)      &&
            (base != STRINGS_UTILS_BASE_HEXADECIMAL) &&
            (base != STRINGS_UTILS_BASE_OCTAL)       &&
            (base != STRINGS_UTILS_BASE_DECIMAL))
        {
            str[str_length] = '\0';
        }
        else
        {
            char_t prefix[2];
            size_t prefix_len = strings_utils_get_base_prefix(base, prefix);

            /* Convert value to string */
            str_length += strings_utils_utoa_raw(base, value, str);

            /* Add prefix if needed according to the base */
            for (int32_t idx = (int32_t)prefix_len - 1; idx >= 0; idx--)
            {
                str[str_length++] = prefix[idx];
            }

            str[str_length] = '\0';

            /* Reverse string to get correct order */
            strings_utils_reverse(str, str_length);
        }
    }

    return str;
}
