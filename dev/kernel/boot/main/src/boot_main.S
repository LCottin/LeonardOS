.section .text
.global  _boot_main_entry
.type    _boot_main_entry, %function

_boot_main_entry:

    boot_main_set_stack_pointer:
        ldr     x10, =__stack_end
        and     x10, x10, #0xFFFFFFFFFFFFFFF0           /* Align to 16 bytes */
        mov     sp, x10

    boot_main_print_hello:
        ldr     x0, =K_BOOT_MAIN_HELLO_MSG              /* Address of message  */
        bl      boot_print_msg                          /* Print message */

    /* Initialize BMT */
    bl      bmt_ctx_init                                /* Initialize BMT */

    /* Parse memory to find all ELF */
    bl      boot_parse_memory                           /* Parse memory to find all ELF */

    /* Build BMT table from ELF found */
    boot_main_build_table:
        ldr     x0, =K_BOOT_MAIN_BUILD_bmt_MSG          /* Address of message */
        bl      boot_print_msg                          /* Print message */
        bl      bmt_build_table                         /* Build BMT table */
        bl      bmt_info_print_table                    /* Print BMT table */

    /* Load binaries into RAM */
    boot_main_copy_binaries:
        ldr     x0, =K_BOOT_MAIN_COPY_BINARIES_MSG      /* Address of message */
        bl      boot_print_msg                          /* Print message */
        bl      bmt_build_copy_binaries                 /* Copy binaries to RAM */
        ldr     x0, =K_BOOT_MAIN_DONE_MSG               /* Address of message */
        bl      boot_print_msg                          /* Print message */

    /* Get kernel entry point and stack pointer */
    boot_main_get_kernel_info:
        bl      bmt_info_get_kernel_entry               /* Get kernel entry point */
        mov     x19, x0                                 /* Save kernel entry point in non volatile register */
        bl      bmt_info_get_kernel_stack_top           /* Get kernel stack pointer */
        mov     x20, x0                                 /* Save kernel stack top in non volatile register */

    /* Jump to kernel entry point */
    boot_main_jump_to_kernel:
        ldr     x0, =K_BOOT_MAIN_BRANCH_KERNEL          /* Address of message */
        bl      boot_print_msg                          /* Print message */
        mov     sp, x0                                  /* Set stack pointer */
        br      x19                                     /* Jump to kernel entry point */

done:
    b       done                                        /* Infinite loop */

/* Read-only data section */
.section .rodata

K_BOOT_MAIN_HELLO_MSG:
    .asciz "\n[BOOT] Hello World!\n"

K_BOOT_MAIN_BUILD_bmt_MSG:
    .asciz "[BOOT] Building BMT table...\n"

K_BOOT_MAIN_COPY_BINARIES_MSG:
    .asciz "[BOOT] Copying binaries to RAM...\n"

K_BOOT_MAIN_DONE_MSG:
    .asciz "[BOOT] Done!\n"

K_BOOT_MAIN_BRANCH_KERNEL:
    .asciz "[BOOT] Launching kernel ...\n"
