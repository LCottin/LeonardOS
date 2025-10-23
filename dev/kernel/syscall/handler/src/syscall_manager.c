#include "syscall_krn.h"
#include "syscall_handler_prv.h"
#include "scheduler_krn.h"
#include "printer_krn.h"
#include "clock_krn.h"

void syscall_manager(const syscall_numbers_e syscall_number, cptr_t arg1, cptr_t arg2, ptr_t ret)
{
    switch (syscall_number)
    {
        case SYSCALL_PRINT_STRING:
        {
            printer_print_string((const char_t *)arg1);
            break;
        }

        case SYSCALL_PRINT_INT:
        {
            printer_print_signed(*(const int32_t *)arg1, *(const printer_base_t *)arg2);
            break;
        }

        case SYSCALL_PRINT_ADDR:
        {
            printer_print_address(*(const addr_t *)arg1);
            break;
        }

        case SYSCALL_GET_TIME:
        {
            *(time_t *)ret = clock_info_get_time();
            break;
        }

        case SYSCALL_YIELD:
        {
            scheduler_switch_next_task();
            break;
        }

        default:
            break;
    }
}
