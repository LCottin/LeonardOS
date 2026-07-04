#include "hello_world.h"
#include "types_usr.h"
#include "libuser_usr.h"


void hello_world_entry(void)
{
    static uint32_t hello_world_counter = 0;
    while (TRUE)
    {
        user_print_string("[USER] Hello world from user !\n");
        user_print_formatted("[USER] Hello world counter: %d\n\n", hello_world_counter++);
        user_yield();
    }
}
