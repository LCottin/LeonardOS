#include "pcb_krn.h"
#include "pcb_ctx.h"

void pcb_ctx_app_update(const uint32_t current_task, const uint32_t next_task)
{
    /* Update the PCB state of the current and next tasks */
    pcb_state_set_state(current_task, PCB_STATE_TERMINATED);
    pcb_state_set_state(next_task,    PCB_STATE_RUNNING);

    /* Reset stack pointer as the task is terminated, next time it is scheduled it will restart */
    const addr_t app_stack_top = bmt_info_get_app_stack_top(next_task);
    pcb_state_set_register(current_task, PCB_STATE_REGISTER_SP, app_stack_top);
}
