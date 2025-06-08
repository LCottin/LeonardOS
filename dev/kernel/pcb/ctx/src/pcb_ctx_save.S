.section .text
.global  pcb_ctx_save
.type    pcb_ctx_save, %function

pcb_ctx_save:

    pcb_ctx_save_callee_save_regs:
        stp     x19, x20, [x0, #0]      /* Save x19 and x20 */
        stp     x21, x22, [x0, #16]     /* Save x21 and x22 */
        stp     x23, x24, [x0, #32]     /* Save x23 and x24 */
        stp     x25, x26, [x0, #48]     /* Save x25 and x26 */
        stp     x27, x28, [x0, #64]     /* Save x27 and x28 */
        stp     x29, x30, [x0, #80]     /* Save x29 and x30 */

    pcb_ctx_save_callee_save_sp:
        mov     x1, sp                  /* Get current stack pointer */
        str     x1, [x0, #96]           /* Save stack pointer in PCB */

    pcb_ctx_save_done:
        br      lr                  /* Return from subroutine */
