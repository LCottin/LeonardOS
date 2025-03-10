#ifndef __LIBUSER_H__
#define __LIBUSER_H__

#include "types_usr.h"
#include "syscall.h"

/**
 * @brief Prints a string to the console.
 *
 * This function uses a system call to print a string to the console.
 *
 * @param str Pointer to the string to be printed.
 * @return None.
 */
void user_print_string(const char_t *str);

#endif /* __LIBUSER_H__ */
