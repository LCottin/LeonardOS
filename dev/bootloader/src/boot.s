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

print_loop:
    ldrb w4, [x2], #1    /* Load byte from message and increment pointer */
    cbz w4, done         /* Jump to done if end of string (null terminator) */
    strb w4, [x1]        /* Write byte to UART */
    b print_loop         /* Repeat until end of message */

done:
    b done               /* Infinite loop to stop execution */

/* Read only section */
.section .rodata
message:
    .asciz "Hello, World!\n"  /* Null-terminated string */
