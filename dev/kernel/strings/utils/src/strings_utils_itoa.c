#include "strings_utils_usr.h"
#include "strings_utils_prv.h"
#include "printer_usr.h"

char_t *strings_utils_itoa(const printer_base_t base, const int64_t value, char_t *str)
{
    if (str != NULL_PTR)
    {
        size_t str_length = 0;

        if ((base != PRINTER_BASE_BINARY)      &&
            (base != PRINTER_BASE_HEXADECIMAL) &&
            (base != PRINTER_BASE_OCTAL)       &&
            (base != PRINTER_BASE_DECIMAL))
        {
            str[str_length] = '\0';
        }
        else
        {
            char_t prefix[2];
            bool_t is_value_negative;
            uint64_t raw_value;
            size_t prefix_len = strings_utils_get_base_prefix(base, prefix);

            /* Get signedness and raw value for conversion */
            if ((base == PRINTER_BASE_DECIMAL) && (value < 0))
            {
                is_value_negative = TRUE;
                raw_value         = (uint64_t)(-(value + 1)) + 1;
            }
            else
            {
                is_value_negative = FALSE;
                raw_value         = (uint64_t)value;
            }

            /* Conversion of raw value to string */
            str_length += strings_utils_utoa_raw(base, raw_value, str);

            /* Add prefix and sign if needed according to the base */
            for (int32_t idx = (int32_t)prefix_len - 1; idx >= 0; idx--)
            {
                str[str_length++] = prefix[idx];
            }

            if (is_value_negative)
            {
                str[str_length++] = '-';
            }
            else
            {
                /* Nothing to do */
            }

            str[str_length] = '\0';

            /* Reverse string to get correct order */
            strings_utils_reverse(str, str_length);
        }
    }
    else
    {
        /* Nothing to do */
    }

    return str;
}
