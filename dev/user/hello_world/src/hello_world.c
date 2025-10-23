#include "hello_world.h"
#include "types_usr.h"
#include "libuser_usr.h"

void hello_world_entry(void)
{
    while (TRUE)
    {
        user_print_string("[USER] Hello world from user !\n");
        user_yield();
    }
}
