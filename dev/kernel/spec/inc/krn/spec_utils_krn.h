#ifndef __SPEC_UTILS_KRN_H__
#define __SPEC_UTILS_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Copies n bytes from memory area src to memory area dest.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return None.
 **********************************************************************/
extern void spec_utils_memcpy(ptr_t dest, cptr_t src, const size_t n);


/**********************************************************************
 * @brief Compares the first n bytes of two memory areas.
 *
 * @param ptr1 Pointer to the first memory area.
 * @param ptr2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the
 *         first n bytes of ptr1 is found, respectively, to be less than,
 *         to match, or be greater than the first n bytes of ptr2.
 **********************************************************************/
extern int32_t spec_utils_memcmp(cptr_t ptr1, cptr_t ptr2, const size_t n);


/**********************************************************************
 * @brief Fills the first n bytes of the memory area pointed to by dest
 *        with the constant byte c.
 *
 * @param dest Pointer to the memory area to fill.
 * @param c The byte value to set (converted to uint8_t).
 * @param n Number of bytes to fill.
 * @return None.
 **********************************************************************/
extern void spec_utils_memset(ptr_t dest, const uint8_t c, const size_t n);


/**********************************************************************
 * @brief Prints a null-terminated string to the console.
 *
 * @param str Pointer to the null-terminated string to print.
 * @return None.
 **********************************************************************/
extern void spec_utils_print_string(const char_t *str);


/**********************************************************************
 * @brief Prints a unsigned integer to the console.
 *
 * @param number The unsigned integer to print.
 * @return None.
 **********************************************************************/
extern void spec_utils_print_uint(const uint32_t number);


#endif /* __SPEC_UTILS_KRN_H__ */
