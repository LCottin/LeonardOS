#ifndef __SERIAL_PRINT_H__
#define __SERIAL_PRINT_H__

#include "types.h"

/**
 * @brief Prints a null-terminated string.
 *
 * @param str A pointer to the null-terminated string to be printed.
 *
 * @return None.
 */
extern void serial_print_string(const char_t *str);

#endif /* __SERIAL_PRINT_H__ */
