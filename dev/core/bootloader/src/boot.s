.section .text
.global _start

_start:
    /* Set the stack pointer */
    /* This function initializes the stack pointer to the top of the stack. */
    /* The stack is used to store local variables, function parameters, and return addresses. */
    ldr x0, =_stack_end
    and x0, x0, #0xFFFFFFFFFFFFFFF0  /* Align to 16 bytes */
    mov sp, x0


    /* Copy .data section */
    /* This function copies the initialized data from the read-only section to the writable section. */
    /* The .data section contains initialized global and static variables. */
    ldr x1, =_erodata
    ldr x2, =_data_start
    ldr x3, =_data_end

done_copy_data:
    /* Zero out the .bss section */
    /* This function initializes the .bss section to zero. */
    /* The .bss section contains uninitialized global and static variables. */
    ldr x1, = _bss_start
    ldr x2, = _bss_end

zero_bss:
    /* Loop through the .bss section and zero each word */
    cmp x1, x2
    bge done_zero_bss
    str xzr, [x1], #16
    b zero_bss

done_zero_bss:
    /* UART base address for QEMU virt machine */
    /* This constant holds the base address of the UART (Universal Asynchronous Receiver/Transmitter) */
    /* The UART is used for communication with external devices. */
    ldr x1, =0x09000000  /* Base address of UART */

    ldr x2, =currentEL          /* Address of message start */
    ldr  x3, =10                /* \n */
    strb w3, [x1]               /* Write byte to UART */

print_loop2:
    /* Load byte from message and increment pointer */
    /* This loop loads each byte of the message from memory and writes it to the UART. */
    ldrb w4, [x2], #1           /* Load byte from message and increment pointer */
    cbz w4, done_print_loop2     /* Jump to next if end of string (null terminator) */
    strb w4, [x1]               /* Write byte to UART */
    b print_loop2                /* Keep printing */

done_print_loop2:
    mrs x3, CurrentEL
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
    /* Load byte from message and increment pointer */
    /* This loop loads each byte of the message from memory and writes it to the UART. */
    ldrb w4, [x2], #1           /* Load byte from message and increment pointer */
    cbz w4, done_print_loop     /* Jump to next if end of string (null terminator) */
    strb w4, [x1]               /* Write byte to UART */
    b print_loop                /* Keep printing */

done_print_loop:
    /* Jump to main program entry point */
    /* This function jumps to the main program entry point, allowing the program to continue execution. */
    ldr x0, =main
    blr x0

done:
    /* Infinite loop to stop execution */
    /* This loop is an infinite loop that prevents the program from terminating. */
    b done

/* Read only section */
.section .rodata
message:
    /* Null-terminated string */
    /* This section contains the example message that will be printed to the UART. */
    .asciz "[BOOT] Hello World!\n\n"  /* Null-terminated string */

currentEL:
    /* Null-terminated string */
    /* This section contains the example message that will be printed to the UART. */
    .asciz "[BOOT] Current EL: "  /* Null-terminated string */
