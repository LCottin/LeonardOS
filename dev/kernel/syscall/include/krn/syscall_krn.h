#ifndef __SYSCALL_KRN_H__
#define __SYSCALL_KRN_H__

#include "types_usr.h"

/**********************************************************************
 * @brief Enumeration of system call numbers.
 *
 * This enumeration defines the system call numbers used to identify
 * different system call functions.
 **********************************************************************/
typedef enum
{
    SYSCALL_PRINT_STRING = 0, /* System call to print a string */
    SYSCALL_PRINT_INT    = 1, /* System call to print an integer */
    SYSCALL_PRINT_ADDR   = 2, /* System call to print an address */

    SYSCALL_TOTAL            /* Total number of system calls */
} syscall_numbers_t;


/**********************************************************************
 * @brief Handles a system call.
 *
 * This function is the entry point for handling system calls. It takes
 * a system call number and an argument, and performs the corresponding
 * system call function.
 *
 * @param number The system call number.
 * @param arg1 The first argument for the system call.
 * @param arg2 The second argument for the system call.
 * @return None.
 **********************************************************************/
extern void syscall_handler(const syscall_numbers_t number, cptr_t arg1, cptr_t arg2);


#endif /* __SYSCALL_KRN_H__ */
