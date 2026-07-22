#include "libuser_usr.h"
#include "syscall_krn.h"

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

    syscall_handler_svc(&request);
}
