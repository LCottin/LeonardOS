#ifndef __ARCH_KRN_H__
#define __ARCH_KRN_H__

#include "types_usr.h"

/*******************************************************************************
 * @brief Launches the kernel entry point with the given stack top.
 *
 * @param entry The entry point address of the kernel.
 * @param stack_top The top address of the kernel stack.
 ************************************************************************/
extern void arch_entry_launch_kernel(
                const addr_t entry,
                const addr_t stack_top);


#endif /* __ARCH_KRN_H__ */
