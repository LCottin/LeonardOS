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
    SYSCALL_PRINT_STRING,    /* System call to print a string */
    SYSCALL_PRINT_INT,       /* System call to print an integer */
    SYSCALL_PRINT_UINT,      /* System call to print an unsigned integer */
    SYSCALL_PRINT_LONG,      /* System call to print a long integer */
    SYSCALL_PRINT_ULONG,     /* System call to print an unsigned long integer */
    SYSCALL_PRINT_ADDR,      /* System call to print an address */
    SYSCALL_PRINT_FORMATTED, /* System call to print a formatted string */
    SYSCALL_GET_TIME,        /* System call to get time */
    SYSCALL_YIELD,           /* System call to yield an application */

    SYSCALL_TOTAL            /* Total number of system calls */
} syscall_numbers_e;


/**********************************************************************
 * @brief Buffer input structure for system calls.
 *
 * This structure defines the buffer used for passing data
 * from user to kernel space during system calls.
 **********************************************************************/
typedef struct
{
    cptr_t        buffer;
    const size_t  size;
    const uint8_t reserved[4]; /* Reserved for future use or alignment */
} syscall_input_buffer_t;


/**********************************************************************
 * @brief Buffer output structure for system calls.
 *
 * This structure defines the buffer used for passing data
 * from kernel to user space during system calls.
 **********************************************************************/
typedef struct
{
    ptr_t        buffer;
    size_t       size;
    const uint8_t reserved[4]; /* Reserved for future use or alignment */
} syscall_output_buffer_t;


/**********************************************************************
 * @brief Structure for system call requests.
 *
 * This structure defines the request format for system calls,
 * including the system call ID, flags, and input/output buffers.
 **********************************************************************/
typedef struct
{
    syscall_numbers_e       syscall_id;
    uint32_t                flags;
    syscall_input_buffer_t  input;
    syscall_output_buffer_t output;
} syscall_request_t;


/**********************************************************************
 * @brief Handles a system call.
 *
 * This function is the entry point for handling system calls. It takes
 * a system call request structure, switch back to the kernel mode
 * to process the request, and then returns the result to the caller.
 *
 * @param syscall__request The system call request structure
 * @return None.
 **********************************************************************/
extern void syscall_handler(syscall_request_t *request);


#endif /* __SYSCALL_KRN_H__ */
