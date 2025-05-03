#include "syscall_krn.h"
#include "printer_krn.h"

void syscall_handler(const syscall_numbers_t number, cptr_t arg1, cptr_t arg2)
{
    switch (number)
    {
        case SYSCALL_PRINT_STRING:
        {
            printer_print_string((const char_t *)arg1);
            break;
        }

        case SYSCALL_PRINT_INT:
        {
            printer_print_int(*(const int32_t *)arg1, *(const printer_base_t *)arg2);
            break;
        }

        case SYSCALL_PRINT_ADDR:
        {
            printer_print_address(*(const addr_t *)arg1);
            break;
        }

        default:
            break;
    }
}
