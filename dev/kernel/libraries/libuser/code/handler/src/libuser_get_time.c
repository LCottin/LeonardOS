#include "libuser_usr.h"
#include "syscall_krn.h"
#include "libuser_handler_prv.h"

void user_get_time(time_t *time)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_GET_TIME,
        .flags      = 0,
        .input =
        {
            .buffer = NULL_PTR,
            .size   = 0
        },
        .output =
        {
            .buffer = (ptr_t)time,
            .size   = sizeof(time_t)
        }
    };

    libuser_launch_syscall(&request);
}
