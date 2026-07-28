.section .text
.global  syscall_handler
.type    syscall_handler, %function

syscall_handler:

    syscall_handler_save_syscall_request_addr:
        mov x19, x0                                          /* Save syscall request address in x19 */

    syscall_handler_save_on_stack:
        mrs     x1, ELR_EL1                                 /* Read the Exception Link Register (ELR) value */
        mrs     x2, SPSR_EL1                                /* Read the SPSR value */
        stp     x1, x2, [sp, #-16]!                         /* Save ELR and SPSR on stack */

        stp     x19, x20, [sp, #-16]!                        /* Save x19 and x20 on stack */
        stp     x21, x22, [sp, #-16]!                        /* Save x21 and x22 on stack */
        stp     x23, x24, [sp, #-16]!                        /* Save x23 and x24 on stack */
        stp     x25, x26, [sp, #-16]!                        /* Save x25 and x26 on stack */
        stp     x27, x28, [sp, #-16]!                        /* Save x27 and x28 on stack */
        stp     x29, x30, [sp, #-16]!                        /* Save x29 and x30 on stack */

    syscall_handler_restore_scheduler_ctx:
        ldr     x1, =g_p_scheduler_ctx_table                /* Load address of scheduler context table */
        mrs     x2, tpidr_el1                               /* Read scheduler address from TPIDR_EL1 */
        str     x2, [x1]                                    /* Restore scheduler context table */

    syscall_handler_get_app_ctx:
        bl      scheduler_ctx_get_current_task              /* Get current task ID */
        bl      scheduler_ctx_get_app_ctx                   /* Get current task PCB context address */

    syscall_handler_save_app_ctx:
        ldp     x29, x30, [sp], #16                        /* Restore x29 and x30 from stack */
        ldp     x27, x28, [sp], #16                        /* Restore x27 and x28 from stack */
        ldp     x25, x26, [sp], #16                        /* Restore x25 and x26 from stack */
        ldp     x23, x24, [sp], #16                        /* Restore x23 and x24 from stack */
        ldp     x21, x22, [sp], #16                        /* Restore x21 and x22 from stack */
        ldp     x19, x20, [sp], #16                        /* Restore x19 and x20 from stack */
        ldp      x1,  x2, [sp], #16                        /* Restore ELR and SPSR from stack */

        stp     x19, x20, [x0, #0]                          /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]                         /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]                         /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]                         /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]                         /* Save x27 and x28 */
        stp     x29, x30, [x0, #80]                         /* Save x29 and x30 */

        stp      x1, x2, [x0, #112]                       /* Save ELR and SPSR */

        mov      x1, sp                                     /* Load the current stack pointer */
        str      x1, [x0, #96]                              /* Save the stack pointer to the PCB context */

    syscall_handler_restore_syscall_request_addr:
        mov x4, x19                                         /* Restore syscall request address from x19 */

    syscall_handler_restore_kernel_ctx:
        bl      scheduler_ctx_get_krn_ctx                   /* Get kernel PCB context address */

        ldp     x19, x20, [x0, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]                         /* Restore x27 and x28 */
        ldp     x29, x30, [x0, #80]                         /* Restore x29 and x30 */

        ldr     x1, [x0, #96]                               /* Restore the stack pointer from the PCB context */
        mov     sp, x1                                      /* Restore the stack pointer */

        ldp     x2, x3, [x0, #112]                        /* Restore ELR and SPSR from PCB context */
        msr     ELR_EL1, x2                                 /* Restore ELR */
        msr     SPSR_EL1, x3                                /* Restore SPSR */

    syscall_handler_save_kernel_ctx_addr:
        str    x0, [sp, #-8]!                               /* Save kernel ctx address on stack */

    syscall_handler_call_manager:
        mov     x0, x4                                      /* Syscall request address */
        bl      syscall_manager

    syscall_handler_save_return:
        mov     x4, x0

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

        mrs     x1, ELR_EL1                                 /* Read the Exception Link Register (ELR) value */
        mrs     x2, SPSR_EL1                                /* Read the SPSR value */
        stp     x1, x2, [x0, #112]                        /* Save ELR and SPSR to the PCB context */

    syscall_handler_restore_app_ctx:
        ldp     x19, x20, [x4, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x4, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x4, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x4, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x4, #64]                         /* Restore x27 and x28 */
        ldp     x29, x30, [x4, #80]                         /* Restore x29 and x30 */

        ldr     x1, [x4, #96]                               /* Restore the stack pointer from the PCB context */
        mov     sp, x1                                      /* Restore the stack pointer */

        ldp     x2, x3, [x4, #112]                        /* Restore ELR and SPSR from PCB context */
        msr     ELR_EL1, x2                                 /* Restore ELR */
        msr     SPSR_EL1, x3                                /* Restore SPSR */

    syscall_handler_return:
        eret
