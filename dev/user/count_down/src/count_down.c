#include "count_down.h"
#include "types_usr.h"
#include "libuser_usr.h"
#include "clock_usr.h"

void count_down_entry(void)
{
    /* Initialize the countdown */
    const int32_t count = 5;
    user_print_string("[USER] Starting countdown...\n");

    /* Countdown loop */
    for (int32_t i = 0; i < count; i++)
    {
        user_print_string("[USER] ");
        user_print_int(count - i, PRINTER_BASE_DECIMAL);
        user_print_string("\n");

        /* Sleep for 1 second */
        user_sleep(K_CLOCK_1S_NS);
    }

    user_print_string("[USER] Countdown finished!\n");
}
