#include "libuser_usr.h"
#include "syscall_krn.h"

time_t user_get_time(void)
{
    time_t time;

    syscall_handler(SYSCALL_GET_TIME, NULL_PTR, NULL_PTR, (ptr_t)&time);

    return time;
}
