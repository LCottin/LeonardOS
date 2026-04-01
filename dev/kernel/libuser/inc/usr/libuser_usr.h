#ifndef __LIBUSER_USR_H__
#define __LIBUSER_USR_H__

#include "types_usr.h"
#include "printer_usr.h"

/**********************************************************************
 * @brief Prints a string to the console.
 *
 * This function uses a system call to print a string to the console.
 *
 * @param str Pointer to the string to be printed.
 * @return None.
 **********************************************************************/
extern void user_print_string(const char_t *str);


/**********************************************************************
 * @brief Prints a number to the console.
 *
 * This function uses a system call to print a number to the console.
 *
 * @param num Number to be printed.
 * @param base Base for the number representation.
 * @return None.
 **********************************************************************/
extern void user_print_int(const int32_t num, const printer_base_t base);


/**********************************************************************
 * @brief Prints an address to the console.
 *
 * This function uses a system call to print an address to the console.
 *
 * @param addr Address to be printed.
 * @return None.
 **********************************************************************/
extern void user_print_addr(const addr_t addr);


/**********************************************************************
 * @brief Gets the current time in ns.
 *
 * @param None.
 * @return time_t The current time in nanoseconds since the system started.
 **********************************************************************/
extern time_t user_get_time(void);


/**********************************************************************
 * @brief Sleep for a specified time in nanoseconds.
 *
 * @param time_ns The time to sleep in nanoseconds.
 * @return None.
 **********************************************************************/
extern void user_sleep(const time_t time_ns);


/**********************************************************************
 * @brief Application yield.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void user_yield(void);


#endif /* __LIBUSER_USR_H__ */
