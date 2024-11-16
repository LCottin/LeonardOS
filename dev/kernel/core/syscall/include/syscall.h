#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "types.h"

typedef enum SyscallNumbers
{
    SYSCALL_PRINT_STRING = 0,

    SYSCALL_TOTAL
} SyscallNumbers_t;

extern void syscall_handler(const SyscallNumbers_t number, cptr_t arg);

#endif /* __SYSCALL_H__ */
