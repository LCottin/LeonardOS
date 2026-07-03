#include "libuser_usr.h"
#include "syscall_krn.h"

void user_yield(void)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_YIELD,
        .flags      = 0,
        .input =
        {
            .buffer = NULL_PTR,
            .size = 0
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size = 0
        }
    };

    syscall_handler(&request);
}
