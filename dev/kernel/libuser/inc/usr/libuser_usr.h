#ifndef __LIBUSER_USR_H__
#define __LIBUSER_USR_H__

#include "types_usr.h"
#include "strings_utils_usr.h"


/**********************************************************************
 * @brief Constant from sleep service
 **********************************************************************/
#define K_CLOCK_1NS_NS  1LL
#define K_CLOCK_1US_NS  1000LL
#define K_CLOCK_1MS_NS  1000000LL
#define K_CLOCK_1S_NS   1000000000LL


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
extern void user_print_int(const int32_t num, const strings_utils_base_t base);


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
 * @brief Prints a char to the console.
 *
 * This function uses a system call to print a char to the console.
 *
 * @param c char to be printed.
 * @return None.
 **********************************************************************/
extern void user_print_char(const char_t c);


/**********************************************************************
 * @brief Gets the current time in ns.
 *
 * @param time Pointer to a time_t variable where the current time will be stored.
 * @return None.
 **********************************************************************/
extern void user_get_time(time_t *time);


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


/**********************************************************************
 * @brief Prints a formatted string to the console.
 *
 * @param format Pointer to the format string.
 * @param ... Additional arguments for formatting.
 * @return None.
 **********************************************************************/
extern void user_print_formatted(const char_t *format, ...);


/**********************************************************************
 * @brief Get the next char in console buffer
 *
 * @param None.
 * @return Oldest char in console buffer.
 **********************************************************************/
extern char_t user_console_get(void);


/**********************************************************************
 * @brief Request to execute a command.
 *
 * @param cmd Command to execute in string format.
 * @return None.
 **********************************************************************/
extern void user_execute_cmd(const char_t *cmd);


#endif /* __LIBUSER_USR_H__ */
