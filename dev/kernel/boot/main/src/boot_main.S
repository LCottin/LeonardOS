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
        bl      printer_print_string                    /* Print message */

    /* Initialize BMT */
    bl      bmt_ctx_init                                /* Initialize BMT */

    /* Parse memory to find all ELF */
    bl      boot_parse_memory                           /* Parse memory to find all ELF */

    /* Build BMT table from ELF found */
    boot_main_build_table:
        ldr     x0, =K_BOOT_MAIN_BUILD_BMT_MSG          /* Address of message */
        bl      printer_print_string                    /* Print message */
        bl      bmt_build_table                         /* Build BMT table */
        bl      bmt_info_print_table                    /* Print BMT table */

    /* Load binaries into RAM */
    boot_main_copy_binaries:
        ldr     x0, =K_BOOT_MAIN_COPY_BINARIES_MSG      /* Address of message */
        bl      printer_print_string                    /* Print message */
        bl      bmt_build_copy_binaries                 /* Copy binaries to RAM */
        ldr     x0, =K_BOOT_MAIN_DONE_MSG               /* Address of message */
        bl      printer_print_string                    /* Print message */

    /* Get kernel entry point and stack pointer */
    boot_main_get_kernel_info:
        bl      bmt_info_get_kernel_entry               /* Get kernel entry point */
        mov     x19, x0                                 /* Save kernel entry point in non volatile register */
        bl      bmt_info_get_kernel_stack_top           /* Get kernel stack pointer */
        mov     x20, x0                                 /* Save kernel stack top in non volatile register */

    /* Jump to kernel entry point */
    boot_main_jump_to_kernel:
        stp     x19, x20, [sp, #-16]!                   /* Save x19 and x20 on stack */
        ldr     x0, =K_BOOT_MAIN_BRANCH_KERNEL          /* Address of message */
        bl      printer_print_string                    /* Print message */
        ldp     x19, x20, [sp], #16                     /* Restore x19 and x20 from stack */
        mov     sp, x20                                 /* Set stack pointer */
        ldr     x0, =__bmt_start                        /* Load BMT start address */
        br      x19                                     /* Jump to kernel entry point */

done:
    b       done                                        /* Infinite loop */

/* Read-only data section */
.section .rodata

K_BOOT_MAIN_HELLO_MSG:
    .asciz "\n[BOOT] Hello World!\n"

K_BOOT_MAIN_BUILD_BMT_MSG:
    .asciz "[BOOT] Building BMT table...\n"

K_BOOT_MAIN_COPY_BINARIES_MSG:
    .asciz "[BOOT] Copying binaries to RAM...\n"

K_BOOT_MAIN_DONE_MSG:
    .asciz "[BOOT] Done!\n"

K_BOOT_MAIN_BRANCH_KERNEL:
    .asciz "[BOOT] Launching kernel ...\n"
