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
    SYSCALL_PRINT_STRING,   /* System call to print a string */
    SYSCALL_PRINT_INT,      /* System call to print an integer */
    SYSCALL_PRINT_UINT,     /* System call to print an unsigned integer */
    SYSCALL_PRINT_LONG,     /* System call to print a long integer */
    SYSCALL_PRINT_ULONG,    /* System call to print an unsigned long integer */
    SYSCALL_PRINT_ADDR,     /* System call to print an address */
    SYSCALL_GET_TIME,       /* System call to get time */
    SYSCALL_YIELD,          /* System call to yield an application */

    SYSCALL_TOTAL           /* Total number of system calls */
} syscall_numbers_e;


/**********************************************************************
 * @brief Handles a system call.
 *
 * This function is the entry point for handling system calls. It takes
 * a system call number and an argument, switch back to the kernel mode
 * to process the request, and then returns the result to the caller.
 *
 * @param syscall_number The system call number.
 * @param arg1 The first argument for the system call.
 * @param arg2 The second argument for the system call.
 * @param ret The return value of the system call.
 * @return None.
 **********************************************************************/
extern void syscall_handler(const syscall_numbers_e syscall_number, cptr_t arg1, cptr_t arg2, ptr_t ret);


#endif /* __SYSCALL_KRN_H__ */
