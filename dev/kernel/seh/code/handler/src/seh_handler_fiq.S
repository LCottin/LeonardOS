.section .text
.global  seh_handler_fiq
.type    seh_handler_fiq, %function

seh_handler_fiq:
    mrs     x0, ELR_EL1         /* Read the Exception Link Register (ELR) value */
    mrs     x1, ESR_EL1         /* Read the Exception Syndrome Register (ESR) value */
    ldr     =0x0                /* Set the exception type */

    bl  seh_handler
