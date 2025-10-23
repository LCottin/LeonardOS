#include "libuser_usr.h"
#include "syscall_krn.h"

void user_yield(void)
{
    syscall_handler(SYSCALL_YIELD, NULL_PTR, NULL_PTR, NULL_PTR);
}
