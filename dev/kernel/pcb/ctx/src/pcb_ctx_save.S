.section .text
.global  pcb_ctx_save
.type    pcb_ctx_save, %function

pcb_ctx_save:

    pcb_ctx_save_callee_save_regs:
        stp     x19, x20, [x0, #0]          /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]         /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]         /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]         /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]         /* Save x27 and x28 */

    pcb_ctx_save_callee_save_specific_regs:
        mov     x10, sp                     /* Load the current stack pointer */
        str     x10, [x0, #80]              /* Save the stack pointer to the PCB context */

    pcb_ctx_save_done:
        br      lr                          /* Return from subroutine */
