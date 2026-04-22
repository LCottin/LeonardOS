#include "scheduler_krn.h"
#include "scheduler_switch.h"
#include "pcb_krn.h"
#include "printer_krn.h"

void scheduler_run(void)
{
    /* Set all application to ready state */
    pcb_state_set_apps_ready();

    const uint32_t app_count = scheduler_ctx_get_task_count();

    if (app_count > 0)
    {
        printer_print_string("[KERN] Launching application ...\n\n");
        scheduler_switch_first_task();

        /* Not reached, applications are running and shall not return */
    }
    else
    {
        printer_print_string("[KERN] No application to run.\n");
    }
}
