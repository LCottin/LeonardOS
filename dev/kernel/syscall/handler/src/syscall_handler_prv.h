#ifndef __SYSCALL_HANDLER_PRV_H__
#define __SYSCALL_HANDLER_PRV_H__

#include "types_usr.h"
#include "syscall_krn.h"

/**********************************************************************
 * @brief Manage a system call.
 *
 * This function performs the corresponding system call function.
 *
 * @param syscall_number The system call number.
 * @param arg1 The first argument for the system call.
 * @param arg2 The second argument for the system call.
 * @param ret The return value of the system call.
 * @return None.
 **********************************************************************/
extern void syscall_manager(const syscall_numbers_e syscall_number, cptr_t arg1, cptr_t arg2, ptr_t ret);


#endif /* __SYSCALL_HANDLER_PRV_H__ */
