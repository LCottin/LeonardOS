.section .text
.global   seh_ctx_init
.type     seh_ctx_init, %function

seh_ctx_init:
    ldr     x0, =seh_ctx_ivt        /* Load address of Interrupt Vector Table */
    msr     VBAR_EL1, x0            /* Load Interrupt Vector Table in the register */
    msr     DAIFCLr, #0b1111      /* Clear flags to enable IRQ, FIQ, SError and Syn interruptions */
    br      lr                	    /* Return from subroutine */
