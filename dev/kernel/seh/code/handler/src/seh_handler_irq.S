.section .text
.global  seh_handler_irq
.type    seh_handler_irq, %function

seh_handler_irq:
    mrs     x0, ELR_EL1         /* Read the Exception Link Register (ELR) value */
    mrs     x1, ESR_EL1         /* Read the Exception Syndrome Register (ESR) value */
    ldr     x2, =0x1            /* Set the exception type */

    bl  seh_handler
