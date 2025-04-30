#include "pcb_krn.h"
#include "pcb_ctx.h"

void pcb_ctx_app_update(const uint32_t current_task, const uint32_t next_task)
{
    /* Update the PCB state of the current and next tasks */
    // todo faire un accesseur pour le PCB
    g_pcb_ctx_table.pcb_apps_ctx[current_task].state = PCB_STATE_TERMINATED;
    g_pcb_ctx_table.pcb_apps_ctx[next_task].state    = PCB_STATE_RUNNING;

    /* Reset stack pointer as the task is terminated, next time it is scheduled it will restart */
    // todo faire un accesseur pour le PCB
    g_pcb_ctx_table.pcb_apps_ctx[current_task].registers.sp = bmt_info_get_app_stack_top(current_task);
}
