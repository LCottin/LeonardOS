.section .text
.global  scheduler_switch_next_task
.type    scheduler_switch_next_task, %function

scheduler_switch_next_task:

    str     x30, [sp, #-8]!                                 /* Save return address on stack  */

    scheduler_switch_next_task_get_app_ctx:
        bl      scheduler_ctx_get_next_task                 /* Get next task id */
        bl      scheduler_ctx_set_current_task              /* Set current task id */
        bl      scheduler_ctx_get_app_ctx                   /* Get user PCB context address */

    ldr     x30, [sp], #8                                   /* Restore return address from stack */
    br      x30                                             /* Return from subroutine */
