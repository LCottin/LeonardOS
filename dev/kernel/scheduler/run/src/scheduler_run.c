#include "scheduler_krn.h"
#include "scheduler_switch.h"
#include "pcb_krn.h"
#include "serial_krn.h"

void scheduler_run(void)
{
    /* Set all application to ready state */
    pcb_state_set_apps_ready();

    /* Infinite loop until OS powers down */
    serial_print_string("[KERN] Launching application ...\n\n");
    scheduler_switch_task(TRUE);
    
    while (TRUE)
    {
        scheduler_switch_task(FALSE);
    }
}
