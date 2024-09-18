#include "string.h"

/* Reverse a string */
static void reverseString(int8_t *str, const size_t length)
{
    if (length > 0)
    {
        uint32_t start = 0;
        uint32_t end   = length - 1;

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

int8_t *itoa(const int32_t num, int8_t *str, const int32_t base)
{
    int8_t *strToReturn;

    /* Check for base between 2 (binary) and 16 (hexadecimal) */
    if ((base < 2) || (base > 16))
    {
        str[0]      = '\0';
        strToReturn = 0;
    }
    else
    {
        uint32_t isNegative;
        int32_t  number;
        size_t   length = 0;

        /* Handle negative number in decimal base */
        if ((num < 0) && (base == 10))
        {
            number     = -num;
            isNegative = 1U;
        }
        else
        {
            number     = num;
            isNegative = 0U;
        }

        /* Process digit to convert to string */
        do
        {
            int32_t remainder = number % base;
            str[length++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
            number /= base;
        } while (number != 0);

        /* Add negative sign if needed */
        if (isNegative)
        {
            str[length++] = '-';
        }

        /* Null-terminate the string */
        str[length] = '\0';

        /* Reverse the string */
        reverseString(str, length);

        strToReturn = str;
    }

    return strToReturn;
}
