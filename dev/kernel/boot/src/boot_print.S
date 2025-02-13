.section .text
.global  boot_print
.type    boot_print, %function

boot_print:
    ldr     x15, =K_BOOT_PRV_QEMU_UART_ADDR  /* Load UART base address */

    boot_print_loop:
        ldrb    w14, [x0], #1                /* Load one byte from message */
        cbz     w14, boot_print_done         /* Stop if end of string */
        strb    w14, [x15]                   /* Write byte to UART */
        b       boot_print_loop              /* Resume loop */

    boot_print_done:
        br      lr                           /* Return from subroutine */
