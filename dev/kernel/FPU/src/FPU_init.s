.section .text
.global  FPU_init
.type    FPU_init, %function

FPU_init:
    mrs     x0, CPACR_EL1   /* Read the value of CPACR_EL1 */
    ldr     x1, =0b11       /* Load the value to enable FPU */
    lsl     x1, x1, #20     /* Shift x1 left by 20 bits to position the enable bits */
    orr     x0, x0, x1      /* Set the corresponding bits in x0 to enable FPU */
    msr     CPACR_EL1, x0   /* Write the new value back to CPACR_EL1 */
    isb                     /* Instruction synchronization barrier */
    br      lr              /* Return from subroutine */
