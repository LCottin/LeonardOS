#include "libuser_usr.h"
#include "syscall_krn.h"
#include "strings_utils_usr.h"
#include "syscall_types.h"

void user_print_int(const int32_t num, const strings_utils_base_t base)
{
    syscall_print_int_t print_int_data =
    {
        .value = num,
        .base  = base
    };

    syscall_request_t request =
    {
        .syscall_id = SYSCALL_PRINT_INT,
        .flags      = 0,
        .input =
        {
            .buffer = (cptr_t)&print_int_data,
            .size   = sizeof(syscall_print_int_t)
        },
        .output =
        {
            .buffer = NULL_PTR,
            .size   = 0
        }
    };

    syscall_handler(&request);
}
