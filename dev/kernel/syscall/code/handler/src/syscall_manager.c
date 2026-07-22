#include "syscall_krn.h"
#include "syscall_types.h"
#include "syscall_handler_prv.h"
#include "scheduler_krn.h"
#include "printer_krn.h"
#include "clock_krn.h"
#include "memory_ops_usr.h"
#include "console_krn.h"

void syscall_manager(syscall_request_t *request)
{
    switch (request->syscall_id)
    {
        case SYSCALL_PRINT_STRING:
        {
            printer_print_string((const char_t *)request->input.buffer);
            break;
        }

        case SYSCALL_PRINT_INT:
        {
            const syscall_print_int_t *args = (const syscall_print_int_t *)request->input.buffer;
            printer_print_signed(args->value, args->base);
            break;
        }

        case SYSCALL_PRINT_ADDR:
        {
            printer_print_address(*(const addr_t *)request->input.buffer);
            break;
        }

        case SYSCALL_PRINT_CHAR:
        {
            printer_print_char(*(const char_t *)request->input.buffer);
            break;
        }

        case SYSCALL_GET_TIME:
        {
            const time_t time = clock_info_get_time();
            memory_ops_utils_copy(request->output.buffer, &time, sizeof(time_t));
            break;
        }

        case SYSCALL_YIELD:
        {
            scheduler_switch_next_task();
            break;
        }

        case SYSCALL_CONSOLE_GET:
        {
            const char_t c = console_buffer_pop();
            memory_ops_utils_copy(request->output.buffer, &c, sizeof(char_t));
            request->output.size = sizeof(char_t);
            break;
        }

        case SYSCALL_EXECUTE_CMD:
        {
            // console_execute_cmd(request->input.buffer);
            break;
        }

        default:
            break;
    }
}
