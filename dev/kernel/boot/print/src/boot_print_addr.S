.section .text
.global  boot_print_addr
.type    boot_print_addr, %function

#include "boot_print_prv.h"

boot_print_addr:
    ldr     x15, =K_BOOT_CTX_QEMU_UART_ADDR      /* Load UART base address */
    mov     x1, x0                               /* Copy the register value to x1 */
    mov     x2, 16                               /* Set loop counter for 16 hex digits */

    boot_print_addr_loop:
        lsr     x3, x1, 60                       /* Extract top 4 bits (1 hex digit) */
        and     x3, x3, #0xF                     /* Mask to get the hex digit */
        cmp     x3, #9                           /* Compare the digit with 9 */
        add     x3, x3, #'0'                     /* Convert to ASCII for '0'-'9' */
        ble     boot_print_addr_continue         /* Branch if digit <= 9 */
        add     x3, x3, #('A' - '9' - 1)         /* Convert to 'A'-'F' */

    boot_print_addr_continue:
        strb    w3, [x15]                        /* Write character to UART */
        lsl     x1, x1, 4                        /* Shift left by 4 bits */
        subs    x2, x2, #1                       /* Decrement loop counter */
        bne     boot_print_addr_loop             /* Continue until all digits are printed */

    boot_print_addr_done:
        br      lr                                   /* Return from subroutine */
