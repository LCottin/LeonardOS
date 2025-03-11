.section .text
.global  boot_print_msg
.type    boot_print_msg, %function

#include "boot_print_prv.h"

boot_print_msg:
    ldr     x15, =K_BOOT_CTX_QEMU_UART_ADDR     /* Load UART base address */

    boot_print_msg_loop:
        ldrb    w14, [x0], #1                   /* Load one byte from message */
        cbz     w14, boot_print_msg_done        /* Stop if end of string */
        strb    w14, [x15]                      /* Write byte to UART */
        b       boot_print_msg_loop             /* Resume loop */

    boot_print_msg_done:
        br      lr                              /* Return from subroutine */
