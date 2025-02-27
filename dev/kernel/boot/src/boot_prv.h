#ifndef __BOOT_PRV_H__
#define __BOOT_PRV_H__

#include "types.h"

/**
 * @brief The start address of the stack.
 */
extern addr_t __stack_end;

/**
 * @brief Parses memory to find ELF binaries.
 *
 * This function scans the memory to locate ELF binaries and adds them to the BMT table.
 */
extern void boot_parse_memory(void);

/**
 * @brief Prints a message in a loop.
 *
 * This function continuously prints a given message to the console.
 *
 * @param message The message to print.
 * @return None.
 */
extern void boot_print(const char_t *message);

#endif /* __BOOT_PRV_H__ */
