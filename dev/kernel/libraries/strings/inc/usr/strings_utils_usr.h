#ifndef __STRINGS_UTILS__USR_H__
#define __STRINGS_UTILS__USR_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Enumeration for different number bases.
 **********************************************************************/
typedef enum
{
    STRINGS_UTILS_BASE_BINARY      = 2,
    STRINGS_UTILS_BASE_OCTAL       = 8,
    STRINGS_UTILS_BASE_DECIMAL     = 10,
    STRINGS_UTILS_BASE_HEXADECIMAL = 16,
} strings_utils_base_t;


/**********************************************************************
 * @brief Reverse a string in place.
 *
 * @param str A pointer to the string to be reversed.
 * @param length Size of the string to be reversed.
 *
 * @return None.
 **********************************************************************/
extern void strings_utils_reverse(char_t *str, const size_t length);


/**********************************************************************
 * @brief Converts an unsigned integer to a string in a specified base.
 *
 * This function takes an unsigned integer, a pointer to a character array, and a base as input.
 * It converts the integer to a string representation in the specified base and stores
 * the result in the character array pointed to by 'string'.
 *
 * @param base The base in which the integer should be converted.
 * @param value The integer to be converted.
 * @param str A pointer to the character array where the result will be stored.
 *
 * @return A pointer to the character array 'string' containing the converted string.
 *
 * @note The str buffer must be large enough to hold the resulting string.
 **********************************************************************/
extern char_t *strings_utils_utoa(const strings_utils_base_t base, const uint64_t value, char_t *str);


/**********************************************************************
 * @brief Converts an integer to a string in a specified base.
 *
 * This function takes an integer, a pointer to a character array, and a base as input.
 * It converts the integer to a string representation in the specified base and stores
 * the result in the character array pointed to by 'string'.
 *
 * @param base The base in which the integer should be converted.
 * @param value The integer to be converted.
 * @param str A pointer to the character array where the result will be stored.
 *
 * @return A pointer to the character array 'string' containing the converted string.
 *
 * @note The str buffer must be large enough to hold the resulting string.
 **********************************************************************/
extern char_t *strings_utils_itoa(const strings_utils_base_t base, const int64_t value, char_t *str);


#endif /* __STRINGS_UTILS_USR_H__ */
