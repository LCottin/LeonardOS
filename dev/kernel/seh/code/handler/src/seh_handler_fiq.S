.section .text
.global  seh_handler_fiq
.type    seh_handler_fiq, %function

seh_handler_fiq:

    seh_handler_fiq_save_all_regs:
        stp     x0, x1,   [sp, #-16]!                   /* Save x0 and x1 on the stack */
        stp     x2, x3,   [sp, #-16]!                   /* Save x2 and x3 on the stack */
        stp     x4, x5,   [sp, #-16]!                   /* Save x4 and x5 on the stack */
        stp     x6, x7,   [sp, #-16]!                   /* Save x6 and x7 on the stack */
        stp     x8, x9,   [sp, #-16]!                   /* Save x8 and x9 on the stack */
        stp     x10, x11, [sp, #-16]!                   /* Save x10 and x11 on the stack */
        stp     x12, x13, [sp, #-16]!                   /* Save x12 and x13 on the stack */
        stp     x14, x15, [sp, #-16]!                   /* Save x14 and x15 on the stack */
        stp     x16, x17, [sp, #-16]!                   /* Save x16 and x17 on the stack */
        stp     x18, x19, [sp, #-16]!                   /* Save x18 and x19 on the stack */
        stp     x20, x21, [sp, #-16]!                   /* Save x20 and x21 on the stack */
        stp     x22, x23, [sp, #-16]!                   /* Save x22 and x23 on the stack */
        stp     x24, x25, [sp, #-16]!                   /* Save x24 and x25 on the stack */
        stp     x26, x27, [sp, #-16]!                   /* Save x26 and x27 on the stack */
        stp     x28, x29, [sp, #-16]!                   /* Save x28 and x29 on the stack */
        str     x30,      [sp, #-8]!                    /* Save x30 on the stack */

    seh_handler_fiq_prepare_args:
        mrs     x0, ELR_EL1                             /* Read the Exception Link Register (ELR) value */
        mrs     x1, ESR_EL1                             /* Read the Exception Syndrome Register (ESR) value */
        ldr     x2, =0x0                                /* Set the exception type */

    seh_handler_fiq_call_handler:
        bl  seh_handler

    seh_handler_fiq_restore_all_regs:
        ldr     x30,      [sp], #8                      /* Restore x30 from the stack */
        ldp     x28, x29, [sp], #16                     /* Restore x28 and x29 from the stack */
        ldp     x26, x27, [sp], #16                     /* Restore x26 and x27 from the stack */
        ldp     x24, x25, [sp], #16                     /* Restore x24 and x25 from the stack */
        ldp     x22, x23, [sp], #16                     /* Restore x22 and x23 from the stack */
        ldp     x20, x21, [sp], #16                     /* Restore x20 and x21 from the stack */
        ldp     x18, x19, [sp], #16                     /* Restore x18 and x19 from the stack */
        ldp     x16, x17, [sp], #16                     /* Restore x16 and x17 from the stack */
        ldp     x14, x15, [sp], #16                     /* Restore x14 and x15 from the stack */
        ldp     x12, x13, [sp], #16                     /* Restore x12 and x13 from the stack */
        ldp     x10, x11, [sp], #16                     /* Restore x10 and x11 from the stack */
        ldp     x8, x9,   [sp], #16                     /* Restore x8 and x9 from the stack */
        ldp     x6, x7,   [sp], #16                     /* Restore x6 and x7 from the stack */
        ldp     x4, x5,   [sp], #16                     /* Restore x4 and x5 from the stack */
        ldp     x2, x3,   [sp], #16                     /* Restore x2 and x3 from the stack */
        ldp     x0, x1,   [sp], #16                     /* Restore x0 and x1 from the stack */

    seh_handler_fiq_return:
        eret                                            /* Return from exception */
