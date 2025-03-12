#ifndef __BOOT_PRINT_H__
#define __BOOT_PRINT_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Prints a message in a loop.
 *
 * This function continuously prints a given message to the console.
 *
 * @param message The message to print.
 * @return None.
 **********************************************************************/
extern void boot_print_msg(const char_t *message);


/**********************************************************************
 * @brief Prints a n address in a loop.
 *
 * This function continuously prints a given address to the console.
 *
 * @param addr The address to print.
 * @return None.
 **********************************************************************/
extern void boot_print_addr(const addr_t addr);


#endif /* __BOOT_PRINT_H__ */
