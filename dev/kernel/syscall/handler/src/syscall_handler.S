.section .text
.global  syscall_handler
.type    syscall_handler, %function

syscall_handler:

    syscall_handler_save_return_address:
        str    x30, [sp, #-8]!                              /* Save return address on stack */

    syscall_handler_save_arguments:
        mov      x9, x0                                     /* syscall number */
        mov     x10, x1                                     /* arg1 */
        mov     x11, x2                                     /* arg2 */
        mov     x12, x3                                     /* ret pointer */

        stp     x9, x10, [sp, #-16]!                        /* Save syscall number and arg1 on stack */
        stp     x11, x12, [sp, #-16]!                       /* Save syscall arg2 and arg3 on stack */

    syscall_handler_restore_scheduler_ctx:
        ldr     x4, =g_p_scheduler_ctx_table                /* Load address of scheduler context table */
        mrs     x5, tpidr_el1                               /* Read scheduler address from TPIDR_EL1 */
        str     x5, [x4]                                    /* Restore scheduler context table */

    syscall_handler_get_task_id:
        bl      scheduler_ctx_get_current_task              /* Get current task ID */

    syscall_handler_get_app_ctx:
        bl      scheduler_ctx_get_app_ctx                   /* Get current task PCB context address */

    syscall_handler_restore_args:
        ldp     x11, x12, [sp], #16                          /* Restore syscall arg2 and arg3 from stack */
        ldp     x9, x10, [sp], #16                           /* Restore syscall number and arg1 from stack */

    syscall_handler_save_app_ctx:
        stp     x19, x20, [x0, #0]                          /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]                         /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]                         /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]                         /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]                         /* Save x27 and x28 */
        stp     x29, x30, [x0, #80]                         /* Save x29 and x30 */
        mov      x1, sp                                     /* Load the current stack pointer */
        str      x1, [x0, #96]                              /* Save the stack pointer to the PCB context */

    syscall_handler_restore_kernel_ctx:
        bl      scheduler_ctx_get_krn_ctx                   /* Get krnel PCB context address */

        ldp     x19, x20, [x0, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]                         /* Restore x27 and x28 */
        ldp     x29, x30, [x0, #80]                         /* Restore x29 and x30 */
        ldr     x1, [x0, #96]                               /* Restore the stack pointer from the PCB context */
        mov     sp, x1                                      /* Restore the stack pointer */

    syscall_handler_save_kernel_ctx_addr:
        str    x0, [sp, #-8]!                               /* Save kernel ctx address on stack */

    syscall_handler_call_manager:
        mov     x0, x9                                      /* syscall number */
        mov     x1, x10                                     /* arg1 */
        mov     x2, x11                                     /* arg2 */
        mov     x3, x12                                     /* ret pointer */
        bl      syscall_manager

    syscall_handler_restore_kernel_ctx_addr:
        ldr    x0, [sp], #8                                 /* Restore kernel ctx address from stack */

    syscall_handler_save_krn_ctx:
        stp     x19, x20, [x0, #0]                          /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]                         /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]                         /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]                         /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]                         /* Save x27 and x28 */
        stp     x29, x30, [x0, #80]                         /* Save x29 and x30 */
        mov      x1, sp                                     /* Load the current stack pointer */
        str      x1, [x0, #96]                              /* Save the stack pointer to the PCB context */

    syscall_handler_get_task_id_2:
        bl      scheduler_ctx_get_current_task              /* Get current task ID */

    syscall_handler_get_app_ctx_2:
        bl      scheduler_ctx_get_app_ctx                   /* Get app PCB context address */

    syscall_handler_restore_app_ctx:
        ldp     x19, x20, [x0, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]                         /* Restore x27 and x28 */
        ldp     x29, x30, [x0, #80]                         /* Restore x29 and x30 */
        ldr     x1, [x0, #96]                               /* Restore the stack pointer from the PCB context */
        mov     sp, x1                                      /* Restore the stack pointer */

    syscall_handler_restore_return_address:
        ldr     x30, [sp], #8                               /* Restore return address from stack */
        br      x30                                         /* Branch to the return address */
