#ifndef __STRING_OPS_H__
#define __STRING_OPS_H__

#include "types.h"

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * @param str Pointer to the null-terminated string.
 * @return The length of the string, not including the null terminator.
 */
extern size_t string_ops_len(const char_t *str);

/**
 * @brief Calculates the length of a string up to a specified size.
 *
 * @param str Pointer to the string.
 * @param size Maximum number of characters to consider.
 * @return The length of the string, not including the null terminator, up to the specified size.
 *         If the null terminator is not found within the specified size, the function returns the size.
 */
extern size_t string_ops_len_n(const char_t *str, const size_t size);

/**
 * @brief Copies the contents of a source string to a destination string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @return Pointer to the destination string.
 * @note The destination string must be large enough to hold the source string and a null terminator.
 */
extern char_t *string_ops_copy(char_t *dest, const char_t *src);

/**
 * @brief Copies a specified number of characters from a source string to a destination string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @param size Maximum number of characters to copy.
 * @return Pointer to the destination string.
 * @note The destination string must be large enough to hold the specified number of characters and a null terminator.
 * @warning If the source string is truncated, the destination string is not null terminated.
 */
extern char_t *string_ops_copy_n(char_t *dest, const char_t *src, const size_t size);

/**
 * @brief Appends a copy of a source string to a destination string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @return Pointer to the destination string.
 * @note The destination string must be large enough to hold the concatenated string and a null terminator.
 */
extern char_t *string_ops_cat(char_t *dest, const char_t *src);

/**
 * @brief Appends a specified number of characters from a source string to a destination string.
 *
 * @param dest Pointer to the destination string.
 * @param src Pointer to the source string.
 * @param size Maximum number of characters to append.
 * @return Pointer to the destination string.
 * @note The destination string must be large enough to hold the appended characters and a null terminator.
 */
extern char_t *string_ops_cat_n(char_t *dest, const char_t *src, const size_t size);

/**
 * @brief Compares two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @return An integer less than, equal to, or greater than zero if the first string is found, respectively,
 *         to be less than, to match, or to be greater than the second string.
 */
extern int32_t string_ops_cmp(const char_t *str1, const char_t *str2);

/**
 * @brief Compares a specified number of characters in two strings.
 *
 * @param str1 Pointer to the first string.
 * @param str2 Pointer to the second string.
 * @param size Maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if the first string is found, respectively,
 *         to be less than, to match, or to be greater than the second string.
 */
extern int32_t string_ops_cmp_n(const char_t *str1, const char_t *str2, const size_t size);

#endif /* __STRING_OPS_H__ */
