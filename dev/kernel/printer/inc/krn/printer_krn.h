#ifndef __PRINTER_KRN_H__
#define __PRINTER_KRN_H__

#include "types_usr.h"
#include "printer_usr.h"

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
extern void printer_print_signed(const int32_t value, const printer_base_t base);


/**********************************************************************
 * @brief Print an unsigned integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_unsigned(const uint32_t value, const printer_base_t base);


/**********************************************************************
 * @brief Print a long signed integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_long_signed(const int64_t value, const printer_base_t base);


/**********************************************************************
 * @brief Print a long unsigned integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_long_unsigned(const uint64_t value, const printer_base_t base);


/**********************************************************************
 * @brief Print an address.
 *
 * @param value The address value to be printed.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_address(const addr_t value);


#endif /* __PRINTER_KRN_H__ */
