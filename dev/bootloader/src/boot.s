.section .text
.global _start

_start:
    /* Set the stack pointer */
    ldr x0, =0x80000
    mov sp, x0

    /* UART base address for QEMU virt machine */
    ldr x1, =0x09000000  /* Base address of UART */

    /* Example message */
    ldr x2, =message     /* Address of message start */
    bl print_loop        /* Branch to function to print message */

    /* Jump to main program entry point */
    ldr x0, =main
    blr x0

/* Function to print a null-terminated string to the UART.
*
* @param
* x1 - Base address of the UART.
* x2 - Address of the start of the null-terminated string.
*
* @return:
* None.
*/
print_loop:
    ldrb w4, [x2], #1    /* Load byte from message and increment pointer */
    cbz w4, next         /* Jump to next if end of string (null terminator) */
    strb w4, [x1]        /* Write byte to UART */
    b print_loop         /* Keep printing */

next:
    blr lr               /* Branch to link register, return to caller */

done:
    b done               /* Infinite loop to stop execution */

/* Read only section */
.section .rodata
message:
    .asciz "[BOOT] Hello world!\n"  /* Null-terminated string */