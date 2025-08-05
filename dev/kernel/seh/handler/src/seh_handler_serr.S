.section .text
.global  seh_handler_serr
.type    seh_handler_serr, %function

seh_handler_serr:
    mrs     x0, ELR_EL1         /* Read the Exception Link Register (ELR) value */
    mrs     x1, ESR_EL1         /* Read the Exception Syndrome Register (ESR) value */
    ldr     x2, =0x2            /* Set the exception type */

    bl  seh_handler
