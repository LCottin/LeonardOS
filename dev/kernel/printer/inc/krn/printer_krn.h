#ifndef __PRINTER_KRN_H__
#define __PRINTER_KRN_H__

#include "types_usr.h"
#include "strings_utils_usr.h"
#include "stream_krn.h"

/**********************************************************************
 * @brief Print a null-terminated string.
 *
 * @param str A pointer to the null-terminated string to be printed.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_string(const char_t *str);


/**********************************************************************
 * @brief Print a signed integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_signed(const int32_t value, const strings_utils_base_t base);


/**********************************************************************
 * @brief Print an unsigned integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_unsigned(const uint32_t value, const strings_utils_base_t base);


/**********************************************************************
 * @brief Print a long signed integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_long_signed(const int64_t value, const strings_utils_base_t base);


/**********************************************************************
 * @brief Print a long unsigned integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_long_unsigned(const uint64_t value, const strings_utils_base_t base);


/**********************************************************************
 * @brief Print a char.
 *
 * @param c The char value to be printed.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_char(const char_t c);


/**********************************************************************
 * @brief Print an address.
 *
 * @param value The address value to be printed.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_address(const addr_t value);


/**********************************************************************
 * @brief Print a formatted string.
 *
 * @param format String to print before being formatted.
 * @param ... Arguments to format.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_formatted(const char *format, ...);


/**********************************************************************
 * @brief Returns the stream for printing formatted strings.
 *
 * @param None.
 * @return Pointer to the formatter stream.
 **********************************************************************/
extern stream_t *printer_stream_get(void);


#endif /* __PRINTER_KRN_H__ */
