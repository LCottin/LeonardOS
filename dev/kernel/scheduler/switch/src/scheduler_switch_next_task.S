.section .text
.global  scheduler_switch_next_task
.type    scheduler_switch_next_task, %function

scheduler_switch_next_task:

    scheduler_switch_next_task_get_app_ctx:
        bl      scheduler_ctx_get_next_task                 /* Get next task id */
        bl      scheduler_ctx_set_current_task              /* Set current task id */
        bl      scheduler_ctx_get_app_ctx                   /* Get user PCB context address */

    scheduler_switch_next_task_restore_app_ctx:
        ldp     x19, x20, [x0, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]                         /* Restore x27 and x28 */
        ldp     x29, x30, [x0, #80]                         /* Restore x29 and x30 */
        ldr     x1, [x0, #96]                               /* Restore the stack pointer from the PCB context */
        mov     sp, x1                                      /* Restore the stack pointer */
        ldr     x1, [x0, #104]                            /* Load the return address from the PCB context */

    scheduler_switch_next_task_launch_app:
        mov      x0, x1                                      /* Move return address to x0 */
        mov      x1, xzr                                     /* Clear x1 as it's not used in first task launch */
        mov      x2, xzr                                     /* Clear x2 as it's not used in first task launch */
        mov      x3, xzr                                     /* Clear x3 as it's not used in first task launch */
        mov      x4, xzr                                     /* Clear x4 as it's not used in first task launch */
        mov      x5, xzr                                     /* Clear x5 as it's not used in first task launch */
        mov      x6, xzr                                     /* Clear x6 as it's not used in first task launch */
        mov      x7, xzr                                     /* Clear x7 as it's not used in first task launch */
        mov      x8, xzr                                     /* Clear x8 as it's not used in first task launch */
        mov      x9, xzr                                     /* Clear x9 as it's not used in first task launch */
        mov     x10, xzr                                     /* Clear x10 as it's not used in first task launch */
        mov     x11, xzr                                     /* Clear x11 as it's not used in first task launch */
        mov     x12, xzr                                     /* Clear x12 as it's not used in first task launch */
        mov     x13, xzr                                     /* Clear x13 as it's not used in first task launch */
        mov     x14, xzr                                     /* Clear x14 as it's not used in first task launch */
        mov     x15, xzr                                     /* Clear x15 as it's not used in first task launch */
        mov     x16, xzr                                     /* Clear x16 as it's not used in first task launch */
        mov     x17, xzr                                     /* Clear x17 as it's not used in first task launch */
        mov     x18, xzr                                     /* Clear x18 as it's not used in first task launch */
        br      x0                                           /* Branch to the return address */
