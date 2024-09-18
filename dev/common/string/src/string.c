#include "string.h"

size_t strlen(const char_t *str)
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

size_t strnlen(const char_t *str, const size_t size)
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

char_t *strcpy(char_t *dest, const char_t *src)
{
    /* Save original address of destination */
    char_t *originalDest = dest;

    /* Loop until end of string */
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return originalDest;
}

char_t *strncpy(char_t *dest, const char_t *src, const size_t size)
{
    /* Save original address of destination */
    char_t *originalDest = dest;

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

    return originalDest;
}

char_t *strcat(char_t *dest, const char_t *src)
{
    /* Save original address of destination */
    char_t *originalDest = dest;

    dest += strlen(dest);

    /* Loop until end of string */
    while (*src != '\0')
    {
        *dest++ = *src++;
    }

    *dest = '\0';
    return originalDest;
}

char_t *strncat(char_t *dest, const char_t *src, const size_t size)
{
    /* Save original address of destination */
    char_t *originalDest = dest;

    size_t length = 0;

    /* Add size of the first string to destination */
    dest += strlen(dest);

    /* Loop until end of string or maximum size is reached */
    while ((*src != '\0') && (length < size))
    {
        *dest++ = *src++;
        length++;
    }

    *dest = '\0';
    return originalDest;
}

int32_t strcmp(const char_t *str1, const char_t *str2)
{
    int32_t cmp;

    /* Loop until end of one string or until a character differs */
    while ((*str1 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return (int32_t)((uint8_t)*str1 - (uint8_t)*str2);
}

int32_t strncmp(const char_t *str1, const char_t *str2, const size_t size)
{
    size_t  length = 0;
    int32_t toReturn;

    /* Loop until end of one string, maximum size is reached, or a character differs */
    while ((length < size) && (*str1 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
        length++;
    }
    if (length == size)
    {
        toReturn = 0;
    }
    else
    {
        toReturn = (uint8_t)*str1 - (uint8_t)*str2;
    }
    return toReturn;
}
