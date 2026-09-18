#include "libuser_usr.h"
#include "syscall_krn.h"
#include "libuser_handler_prv.h"

void user_print_addr(const addr_t addr)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_PRINT_ADDR,
        .flags      = 0,
        .input =
        {
            .buffer = &addr,
            .size   = sizeof(addr_t)
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size   = 0
        }
    };

    libuser_launch_syscall(&request);
}
