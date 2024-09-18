#ifndef __STRING_H__
#define __STRING_H__

/**
 * @brief Converts an integer to a string in a specified base.
 *
 * This function takes an integer, a pointer to a character array, and a base as input.
 * It converts the integer to a string representation in the specified base and stores
 * the result in the character array pointed to by 'string'.
 *
 * @param num The integer to be converted.
 * @param str A pointer to the character array where the result will be stored.
 * @param base The base in which the integer should be converted. It must be between 2 and 36.
 *
 * @return A pointer to the character array 'string' containing the converted string.
 */
extern char *itoa(const int num, char *str, const int base);

#endif
