#ifndef __BOOT_MAIN_PRV_H__
#define __BOOT_MAIN_PRV_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Symbols from linker script
 **********************************************************************/
extern addr_t __stack_top;


/**********************************************************************
 * @brief Boot main entry point.
 *
 * @param None.
 * @return None.
 **********************************************************************/
extern void boot_main(void);


#endif /* __BOOT_MAIN_PRV_H__ */
