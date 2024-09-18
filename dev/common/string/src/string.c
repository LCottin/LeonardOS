#include "string.h"

/* Reverse a string */
static void reverseString(char *str, const int length)
{
    int start = 0;
    int end   = length - 1;

    while (start < end)
    {
        char temp  = str[start];
        str[start] = str[end];
        str[end]   = temp;
        start++;
        end--;
    }
}

char *itoa(const int num, char *str, const int base)
{
    char *strToReturn;

    /* Check for base between 2 (binary) and 16 (hexadecimal) */
    if ((base < 2U) || (base > 16U))
    {
        str[0]      = '\0';
        strToReturn = 0;
    }
    else
    {
        int isNegative;
        int number;
        int length = 0;

        /* Handle negative number in decimal base */
        if ((num < 0) && (base == 10U))
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
            int remainder = number % base;
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
