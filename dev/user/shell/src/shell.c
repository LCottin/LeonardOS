#include "shell.h"
#include "types_usr.h"
#include "libuser_usr.h"


void shell_entry(void)
{
    static int32_t cpt = 0;
    while (TRUE)
    {
        user_print_formatted("[SHELL] Hello world n°%d from shell !\r\n", cpt++);
        user_yield();
    }
}
