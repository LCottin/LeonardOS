#include "libuser_usr.h"
#include "syscall_krn.h"
#include "strings_ops_usr.h"

void user_print_string(const char_t *str)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_PRINT_STRING,
        .flags      = 0,
        .input =
        {
            .buffer = (cptr_t)str,
            .size   = string_ops_len(str)
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size = 0
        }
    };

    syscall_handler(&request);
}
