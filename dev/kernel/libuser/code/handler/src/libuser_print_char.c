#include "libuser_usr.h"
#include "syscall_krn.h"
#include "libuser_handler_prv.h"

void user_print_char(const char_t c)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_PRINT_CHAR,
        .flags      = 0,
        .input =
        {
            .buffer = &c,
            .size   = sizeof(char_t)
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size   = 0
        }
    };

    libuser_launch_syscall(&request);
}
