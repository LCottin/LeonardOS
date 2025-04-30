#ifndef __LIBUSER_USR_H__
#define __LIBUSER_USR_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Prints a string to the console.
 *
 * This function uses a system call to print a string to the console.
 *
 * @param str Pointer to the string to be printed.
 * @return None.
 **********************************************************************/
void user_print_string(const char_t *str);


/**********************************************************************
 * @brief Gets the current time.
 *
 * @param None.
 * @return time_t The current time.
 **********************************************************************/
time_t user_get_time(void);


#endif /* __LIBUSER_USR_H__ */
