.section .text
.global  _boot_entry
.type    _boot_entry, %function

_boot_entry:

    boot_set_stack_pointer:
        ldr     x10, =__stack_end
        and     x10, x10, #0xFFFFFFFFFFFFFFF0               /* Align to 16 bytes */
        mov     sp, x10

    boot_print_hello:
        ldr     x0, =K_BOOT_MAIN_HELLO_MSG                  /* Address of message  */
        bl      boot_print                                  /* Print message */

    /* Initialize BMT */
    bl      BMT_init

    /* Parse memory to find all ELF */
    bl      boot_parse_memory

    /* Build BMT table from ELF found */
    ldr     x0, =K_BOOT_MAIN_BUILD_BMT_MSG       /* Address of message */
    bl      boot_print                           /* Print message */
    bl      BMT_build_table                      /* Build BMT table */
    bl      BMT_print_table                      /* Print BMT table */

    /* Load binaries into RAM */
    ldr     x0, =K_BOOT_MAIN_COPY_BINARIES_MSG   /* Address of message */
    bl      boot_print                           /* Print message */
    bl      BMT_copy_binaries                    /* Copy binaries to RAM */

    ldr     x0, =K_BOOT_MAIN_DONE_MSG            /* Address of message */
    bl      boot_print                           /* Print message */

    bl      BMT_get_kernel_entry                 /* Get kernel entry point */

    /* Set stack pointer */
    ldr x10, =0x45110000 // TODO: Get this address from BMT and metadata
    mov sp, x10

    /* Jump to kernel entry point */
    br      x0

done:
    b       done                                /* Infinite loop */

/* Read-only data section */
.section .rodata

K_BOOT_MAIN_HELLO_MSG:
    .asciz "\n[BOOT] Hello World!\n"

K_BOOT_MAIN_BUILD_BMT_MSG:
    .asciz "\n[BOOT] Building BMT table...\n"

K_BOOT_MAIN_COPY_BINARIES_MSG:
    .asciz "\n[BOOT] Copying binaries to RAM...\n"

K_BOOT_MAIN_DONE_MSG:
    .asciz "\n[BOOT] Done!\n"
