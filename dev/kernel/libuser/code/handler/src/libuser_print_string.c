#include "libuser_usr.h"
#include "syscall_krn.h"

void user_print_string(const char_t *str)
{
    syscall_handler(SYSCALL_PRINT_STRING, (cptr_t)str, NULL_PTR, NULL_PTR);
}
