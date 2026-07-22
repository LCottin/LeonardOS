#include "libuser_usr.h"
#include "syscall_krn.h"
#include "strings_ops_usr.h"

void user_execute_cmd(const char_t *cmd)
{
    syscall_request_t request =
    {
        .syscall_id = SYSCALL_EXECUTE_CMD,
        .flags      = 0,
        .input =
        {
            .buffer = cmd,
            .size   = string_ops_len(cmd),
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size   = 0,
        }
    };

    syscall_handler_svc(&request);
}
