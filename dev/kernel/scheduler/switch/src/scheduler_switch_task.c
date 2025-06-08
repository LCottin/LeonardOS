#include "scheduler_switch.h"
#include "scheduler_ctx.h"
#include "pcb_krn.h"
#include "serial_krn.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"

void scheduler_switch_task(const bool_t is_first_run)
{
    const uint32_t next_task = scheduler_ctx_get_next_task();
    uint32_t current_task    = scheduler_ctx_get_current_task();

    scheduler_ctx_set_current_task(next_task);
    current_task = next_task;

    const addr_t app_entry = pcb_ctx_get_app_entry(current_task);
    if (app_entry != NULL_ADDR)
    {
        /* Update PCB context for the current and next tasks */
        pcb_ctx_app_update(current_task, next_task);

        /* Save kernel context and restore app context */
        pcb_ctx_krn_save();

        /* Save app context if this is not the first run */
        if (is_first_run == FALSE)
        {
            pcb_ctx_app_restore(current_task);
        }

        /* Call the application entry point */
        void (*app_func)(void) = (void (*)(void))app_entry;
        app_func();

        /* Save app context and restore kernel context */
        pcb_ctx_app_save(current_task);
        pcb_ctx_krn_restore();
    }
    else
    {
        /* No entry point, nothing to do */
    }
}
