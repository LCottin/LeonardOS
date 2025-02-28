#include "string_ops.h"

size_t string_ops_len(const char_t *str)
{
    size_t length = 0;

    /* Loop until end of string */
    while(*str != '\0')
    {
        length += 1U;
        str++;
    }

    return length;
}

size_t string_ops_len_n(const char_t *str, const size_t size)
{
    size_t length = 0;

    /* Loop until end of string or maximum size is reached */
    while((*str != '\0') && (length < size))
    {
        length += 1U;
        str++;
    }

    return length;
}

char_t *string_ops_copy(char_t *dest, const char_t *src)
{
    /* Save original address of destination */
    char_t *original_dest = dest;

    /* Loop until end of string */
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return original_dest;
}

char_t *string_ops_copy_n(char_t *dest, const char_t *src, const size_t size)
{
    /* Save original address of destination */
    char_t *original_dest = dest;

    size_t length = 0;

    /* Loop until end of string or maximum size is reached */
    while ((*src != '\0') && (length < size))
    {
        *dest++ = *src++;
        length++;
    }

    /* Pad the remaining size with null characters */
    while (length < size)
    {
        *dest++ = '\0';
        length++;
    }

    return original_dest;
}

char_t *string_ops_cat(char_t *dest, const char_t *src)
{
    /* Save original address of destination */
    char_t *original_dest = dest;

    dest += string_ops_len(dest);

    /* Loop until end of string */
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return original_dest;
}

char_t *string_ops_cat_n(char_t *dest, const char_t *src, const size_t size)
{
    /* Save original address of destination */
    char_t *original_dest = dest;

    size_t length = 0;

    /* Add size of the first string to destination */
    dest += string_ops_len(dest);

    /* Loop until end of string or maximum size is reached */
    while ((*src != '\0') && (length < size))
    {
        *dest++ = *src++;
        length++;
    }

    *dest = '\0';
    return original_dest;
}

int32_t string_ops_cmp(const char_t *str1, const char_t *str2)
{
    /* Loop until end of one string or until a character differs */
    while ((*str1 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (int32_t)((uint8_t)*str1 - (uint8_t)*str2);
}

int32_t string_ops_cmp_n(const char_t *str1, const char_t *str2, const size_t size)
{
    size_t  length = 0;
    int32_t to_return;

    /* Loop until end of one string, maximum size is reached, or a character differs */
    while ((length < size) && (*str1 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
        length++;
    }
    if (length == size)
    {
        to_return = 0;
    }
    else
    {
        to_return = (uint8_t)*str1 - (uint8_t)*str2;
    }
    return to_return;
}
