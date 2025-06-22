#include "libuser_usr.h"
#include "printer_usr.h"

void user_sleep(const time_t time_ns)
{
    if (time_ns > 0)
    {
        /* Save the start time */
        const time_t start_time = user_get_time();
        time_t now_time;

        do
        {
            /* Get the current time */
            now_time = user_get_time();
        } while ((now_time - start_time) < time_ns);
    }
    else
    {
        /* If time is zero or negative, do nothing */
    }
}
