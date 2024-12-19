#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include "types.h"

typedef enum syscall_numbers
{
    SYSCALL_PRINT_STRING = 0,

    SYSCALL_TOTAL
} syscall_numbers_t;

extern void syscall_handler(const syscall_numbers_t number, cptr_t arg);

#endif /* __SYSCALL_H__ */
