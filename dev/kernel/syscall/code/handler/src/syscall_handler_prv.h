#ifndef __SYSCALL_HANDLER_PRV_H__
#define __SYSCALL_HANDLER_PRV_H__

#include "types_usr.h"
#include "syscall_krn.h"

/**********************************************************************
 * @brief Manage a system call.
 *
 * This function performs the corresponding system call function.
 *
 * @param syscall_request Pointer to the system call request structure.
 * @return None.
 **********************************************************************/
extern void syscall_manager(syscall_request_t *request);


#endif /* __SYSCALL_HANDLER_PRV_H__ */
