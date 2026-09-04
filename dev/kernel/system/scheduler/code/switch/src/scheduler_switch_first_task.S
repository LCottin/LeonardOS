.section .text
.global  scheduler_switch_first_task
.type    scheduler_switch_first_task, %function

scheduler_switch_first_task:

    scheduler_switch_first_task_get_krn_ctx:
        bl scheduler_ctx_get_krn_ctx                        /* Get kernel PCB context address */

    scheduler_switch_first_task_save_krn_ctx:
        stp     x19, x20, [x0, #0]                          /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]                         /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]                         /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]                         /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]                         /* Save x27 and x28 */
        stp     x29, x30, [x0, #80]                         /* Save x29 and x30 */

        mov      x1, sp                                     /* Load the current stack pointer */
        str      x1, [x0, #96]                              /* Save the stack pointer to the PCB context */

        mrs     x1, ELR_EL1                                 /* Read the Exception Link Register (ELR) value */
        mrs     x2, SPSR_EL1                                /* Read the SPSR value */
        stp     x1,  x2, [x0, #112]                       /* Save ELR and SPSR */

    scheduler_switch_first_task_get_app_ctx:
        bl      scheduler_ctx_get_next_task                 /* Get next task id */
        bl      scheduler_ctx_set_current_task              /* Set current task id */
        bl      scheduler_ctx_get_app_ctx                   /* Get user PCB context address */

    scheduler_switch_first_task_set_app_ctx:

        ldr     x1, [x0, #96]                               /* Set the stack pointer from the PCB context */
        mov     sp, x1                                      /* Set the stack pointer */

        ldp     x2, x3, [x0, #112]                        /* Restore ELR and SPSR from PCB context */
        msr     ELR_EL1, x2                                 /* Restore ELR */
        msr     SPSR_EL1, x3                                /* Restore SPSR */

    scheduler_switch_first_task_launch_app:
        eret                                                /* Launch next application */
