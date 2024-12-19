#include "syscall.h"
#include "serial.h"

void syscall_handler(const syscall_numbers_t number, cptr_t arg)
{
    switch (number)
    {
        case SYSCALL_PRINT_STRING:
        {
            serial_print_string((const char_t *)arg);
            break;
        }

        default:
            break;
    }
}
