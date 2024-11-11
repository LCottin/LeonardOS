.section .text
.global _start

_start:
    /* Set the stack pointer */
    /* This function initializes the stack pointer to the top of the stack. */
    /* The stack is used to store local variables, function parameters, and return addresses. */
    ldr x0, =__stack_end
    and x0, x0, #0xFFFFFFFFFFFFFFF0  /* Align to 16 bytes */
    mov sp, x0

    /* Zero out .bss section */
    ldr x1, =__bss_start    /* Start of .bss section */
    ldr x2, =__bss_end      /* End of .bss section */

zero_bss:
    cmp x1, x2           /* Compare _bss_start with _bss_end */
    bge done_zero_bss    /* Branch if _bss_start >= _bss_end */
    str xzr, [x1], #8    /* Store zero at _bss_start and increment */
    b zero_bss           /* Repeat until _bss_start >= _bss_end */

done_zero_bss:
    /* UART base address for QEMU virt machine */
    ldr x1, =0x09000000  /* Base address of UART for QEMU virt machine */

    ldr x2, =currentEL   /* Address of message start */
    ldr x3, =10          /* \n */
    strb w3, [x1]        /* Write byte to UART */

print_loop2:
    ldrb w4, [x2], #1            /* Load byte from message and increment pointer */
    cbz w4, done_print_loop2     /* Jump to next if end of string (null terminator) */
    strb w4, [x1]                /* Write byte to UART */
    b print_loop2                /* Keep printing */

done_print_loop2:
    mrs x3, CurrentEL           /* Current EL */
    lsr x3, x3, #2
    add x3, x3, #48
    strb w3, [x1]               /* Write byte to UART */
    ldr  x3, =10                /* \n */
    strb w3, [x1]               /* Write byte to UART */

    /* Example message */
    /* This constant holds the address of the start of the example message. */
    /* The message is a null-terminated string that will be printed to the UART. */
    ldr x2, =message     /* Address of message start */

print_loop:
    ldrb w4, [x2], #1        /* Load byte from message */
    cbz w4, done_print_loop  /* Stop if end of string */
    strb w4, [x1]            /* Write byte to UART */
    b print_loop

done_print_loop:
    /* Jump to main program entry point */
    ldr x0, =main
    blr x0

done:
    /* Infinite loop */
    b done

/* Read-only data section */
.section .rodata
message:
    /* Null-terminated string */
    /* This section contains the example message that will be printed to the UART. */
    .asciz "[BOOT] Hello World!\n\n"  /* Null-terminated string */

currentEL:
    /* Null-terminated string */
    /* This section contains the example message that will be printed to the UART. */
    .asciz "[BOOT] Current EL: "  /* Null-terminated string */
