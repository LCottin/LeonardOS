.section .text
.global  pcb_ctx_restore
.type    pcb_ctx_restore, %function

pcb_ctx_restore:

    pcb_ctx_restore_callee_save_regs:
        ldp     x19, x20, [x0, #0]      /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]     /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]     /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]     /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]     /* Restore x27 and x28 */
        ldp     x29, x30, [x0, #80]     /* Restore x29 and x30 */

    pcb_ctx_restore_callee_save_sp:
        ldr     x8, [x0, #96]           /* Get stack pointer in PCB */
        mov     sp, x8                  /* Restore current stack pointer */

    pcb_ctx_restore_done:
        stp     x29, x30, [sp, #-16]!   /* Save x29 and x30 on the stack */
        mov     x29, sp                 /* Set new frame pointer */
        mov     x8, x29                 /* Load current frame pointer */
        ldr     x9, [x8, #0]            /* Get caller frame pointer */
        ldr     x10, [x9, #8]           /* Get return address */
        br      x10                     /* Branch to the return address */
