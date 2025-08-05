.section .data

g_is_first_run:
    .word 0

g_current_task:
    .word 0

.section .text
.global  scheduler_switch_task
.type    scheduler_switch_task, %function

scheduler_switch_task:

    scheduler_switch_task_save_lr:
        sub sp, sp, #16                                     /* Allocate space on the stack */
        str lr, [sp, #0]                                    /* Save the link register (return address) on the stack */

    scheduler_switch_task_save_is_first_run:
        ldr x6, =g_is_first_run
        str x0, [x6]                                        /* Store the value of x0 (is_first_run) in the global variable */

    scheduler_switch_task_get_next_task:
        bl scheduler_ctx_get_next_task
        mov x19, x0                                         /* Save the result (next_task) in x19 */

    scheduler_switch_task_get_current_task:
        bl scheduler_ctx_get_current_task
        ldr x6, =g_current_task
        str x0, [x6]                                        /* Store the result (current_task) in the global variable */

    sheduler_switch_task_update_app_context:
        ldr x0, [x6]                                        /* Load current_task into w0 */
        mov x1, x19                                         /* Move next_task into w1 */
        bl pcb_ctx_app_update

    scheduler_switch_task_set_current_task:
        mov x0, x19
        bl scheduler_ctx_set_current_task

    scheduler_switch_task_update_current_task:
        ldr x6, =g_current_task
        str x19, [x6]                                       /* Store next_task in current_task */

    scheduler_switch_task_save_krn_context:
        //bl pcb_ctx_krn_save                               /* Save the kernel context (not implemented in this snippet) */

    scheduler_switch_task_restore_app_context:
        // ldr x4, =g_current_task
        // ldr x5, =g_is_first_run
        // ldr x0, [x4]                                     /* Load current_task into x0 */
        // ldr x1, [x5]                                     /* Load is_first_run into x1 */
        // bl pcb_ctx_app_restore

    scheduler_switch_task_get_app_entry:
        ldr x4, =g_current_task
        ldr x0, [x4]                                        /* Load current_task into x0 */
        sub sp, sp, #16                                     /* Allocate space on the stack */
        str lr, [sp, #0]                                    /* Save the link register (return address) on the stack */
        bl pcb_ctx_get_app_entry
        ldr lr, [sp, #0]                                    /* Restore the link register (return address) from the stack */
        add sp, sp, #16                                     /* Deallocate space on the stack */

    scheduler_switch_task_jump_to_app:
        adr x1, scheduler_switch_task_restore_from_app      /* Load the address of restore_from_app into x1 */
        mov lr, x1
        blr x0                                              /* Branch to the application entry point */

    scheduler_switch_task_restore_from_app:
        ldr x4, =g_current_task
        ldr x0, [x4]                                        /* Load current_task into */

    scheduler_switch_task_save_app_context:
        //bl pcb_ctx_app_save                               /* Save the application context (not implemented in this snippet) */

    scheduler_switch_task_restore_krn_context:
        //bl pcb_ctx_krn_restore                            /* Restore the kernel context (not implemented in this snippet) */

    scheduler_switch_task_restore_lr:
        ldr lr, [sp, #0]                                    /* Restore the link register (return address) from the stack */
        add sp, sp, #16                                     /* Deallocate space on the stack */

    scheduler_switch_task_return:
        blr lr                                              /* Return from the function */
