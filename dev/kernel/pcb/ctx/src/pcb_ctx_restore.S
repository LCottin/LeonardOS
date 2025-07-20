.section .text
.global  pcb_ctx_restore
.type    pcb_ctx_restore, %function

pcb_ctx_restore:

    pcb_ctx_restore_first_run:
        cmp     x2, #1                                       /* Check if this is the first run */
        beq     pcb_ctx_restore_callee_save_specific_regs   /* If first run, get PCB context address */

    pcb_ctx_restore_callee_save_regs:
        ldp     x19, x20, [x0, #0]                          /* Restore x19 and x20 */
        ldp     x21, x22, [x0, #16]                         /* Restore x21 and x22 */
        ldp     x23, x24, [x0, #32]                         /* Restore x23 and x24 */
        ldp     x25, x26, [x0, #48]                         /* Restore x25 and x26 */
        ldp     x27, x28, [x0, #64]                         /* Restore x27 and x28 */

    pcb_ctx_restore_callee_save_specific_regs:
        ldr     x10, [x0, #80]                              /* Restore the stack pointer from the PCB context */
        mov     sp, x10                                     /* Restore the stack pointer */

    pcb_ctx_restore_done:
        br      x1                      /* Branch to the return address */
