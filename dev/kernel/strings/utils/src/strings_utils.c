#include "strings_utils_usr.h"

char_t *string_utils_itoa(const int32_t num, char_t *str, const int32_t base)
{
    char_t *str_to_return;

    /* Check for base between 2 (binary) and 16 (hexadecimal) */
    if ((base < 2) || (base > 16))
    {
        str[0]        = '\0';
        str_to_return = NULL;
    }
    else
    {
        bool_t  is_negative;
        int32_t number;
        size_t  length = 0;

        /* Handle negative number in decimal base */
        if ((num < 0) && (base == 10))
        {
            number      = -num;
            is_negative = TRUE;
        }
        else
        {
            number      = num;
            is_negative = FALSE;
        }

        /* Process digit to convert to string */
        do
        {
            int32_t remainder = number % base;
            str[length++] = (remainder > 9) ? (char_t)((remainder - 10) + (int32_t)'a') : (char_t)(remainder + (int32_t)'0');
            number /= base;
        } while (number != 0);

        /* Add negative sign if needed */
        if (is_negative == TRUE)
        {
            str[length++] = '-';
        }

        /* Null-terminate the string */
        str[length] = '\0';

        /* Reverse the string */
        string_utils_reverse(str, length);

        str_to_return = str;
    }

    return str_to_return;
}

void string_utils_reverse(char_t *str, const size_t length)
{
    if (length > 0)
    {
        uint32_t start = 0;
        uint32_t end   = length - 1U;

        while (start < end)
        {
            char temp  = str[start];
            str[start] = str[end];
            str[end]   = temp;
            start++;
            end--;
        }
    }
}
