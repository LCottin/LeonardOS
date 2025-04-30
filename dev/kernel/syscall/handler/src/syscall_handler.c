#include "syscall_krn.h"
#include "serial_krn.h"
#include "clock_krn.h"

void syscall_handler(const syscall_numbers_t number, cptr_t arg, ptr_t ret)
{
    switch (number)
    {
        case SYSCALL_PRINT_STRING:
        {
            serial_print_string((const char_t *)arg);
            break;
        }

        case SYSCALL_GET_TIME:
        {
            *(time_t *)ret = clock_info_get_time();
            break;
        }

        default:
            break;
    }
}
