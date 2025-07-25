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
 * @brief Print an integer in a specified base.
 *
 * @param value The integer value to be printed.
 * @param base  The base for the integer representation (e.g., 10 for decimal, 16 for hexadecimal).
 *
 * @return None.
 **********************************************************************/
extern void printer_print_int(const int32_t value, const printer_base_t base);


/**********************************************************************
 * @brief Print an address.
 *
 * @param value The address value to be printed.
 *
 * @return None.
 **********************************************************************/
extern void printer_print_address(const addr_t value);


#endif /* __PRINTER_KRN_H__ */
