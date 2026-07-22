#include "libuser_usr.h"
#include "syscall_krn.h"

char_t user_console_get(void)
{
    char_t c;

    syscall_request_t request =
    {
        .syscall_id = SYSCALL_CONSOLE_GET,
        .flags      = 0,
        .input =
        {
            .buffer = NULL_PTR,
            .size   = 0,
        },
        .output =
        {
            .buffer = &c,
            .size   = sizeof(c),
        }
    };

    syscall_handler_svc(&request);

    return c;
}
