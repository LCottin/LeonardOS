#include "scheduler_switch.h"
#include "scheduler_ctx.h"
#include "pcb_krn.h"
#include "strings_utils_usr.h"
#include "memory_ops_usr.h"
#include "printer_krn.h"

void scheduler_switch_task(const bool_t is_first_run)
{
    printer_print_string("[KERN] Switching task ...\n\n");
    const uint32_t next_task = scheduler_ctx_get_next_task();
    uint32_t current_task    = scheduler_ctx_get_current_task();

    /* Update PCB context for the current and next tasks */
    pcb_ctx_app_update(current_task, next_task);

    scheduler_ctx_set_current_task(next_task);
    current_task = next_task;

    /* Save kernel context and restore app context */
    pcb_ctx_krn_save();
    printer_print_string("[KERN] krn ctx saved ...\n\n");

    /* Save app context */
    printer_print_string("[KERN] restoring app ctx ...\n\n");
    pcb_ctx_app_restore(current_task, is_first_run);
    printer_print_string("[KERN] app ctx restored ...\n\n");

    /* Call the application entry point */
    const addr_t app_entry = pcb_ctx_get_app_entry(current_task);
    printer_print_string("[KERN] Going to app ...\n\n");
    void (*app_func)(void) = (void (*)(void))app_entry;
    app_func();
    printer_print_string("[KERN] Returning from app ...\n\n");

    /* Save app context and restore kernel context */
    pcb_ctx_app_save(current_task);
    printer_print_string("[KERN] app ctx saved ...\n\n");
    pcb_ctx_krn_restore();
    printer_print_string("[KERN] krn ctx restored ...\n\n");
}
