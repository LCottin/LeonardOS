#ifndef __BOOT_MEMORY_H__
#define __BOOT_MEMORY_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Parses memory to find ELF binaries.
 *
 * This function scans the memory to locate ELF binaries and adds them to the BMT table.
 **********************************************************************/
extern void boot_memory_parse(void);


#endif /* __BOOT_MEMORY_H__ */
