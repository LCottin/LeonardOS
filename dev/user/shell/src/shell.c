#include "shell.h"
#include "types_usr.h"
#include "libuser_usr.h"


void shell_entry(void)
{
    while (TRUE)
    {
        user_print_string("[SHELL]: ");
        const char c = user_console_get();
        user_print_char(c);

        user_print_string("\r\n");
        user_yield();
    }
}
