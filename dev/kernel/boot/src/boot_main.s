.section .text
.global _boot_main

_boot_main:

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
