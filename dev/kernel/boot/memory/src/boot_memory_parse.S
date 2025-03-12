.section .text
.global  boot_parse_memory
.type    boot_parse_memory, %function

#include "boot_memory_prv.h"

boot_parse_memory:

    stp lr, x30, [sp, #-16]!                                /* Save lr on stack */

    ldr     x9,  =0x00101000                                /* Start address to parse in ROM, avoiding boot itself */
    ldr     x10, =0x00FFFFFF                                /* End of ROM */
    ldr     x12, =K_BOOT_MEMORY_PAGE_SIZE                   /* Load page size */

    ldr     x0, =K_BOOT_PARSE_MEMORY_MSG_START_PARSING      /* Load message address */
    bl      boot_print_msg                                  /* Print message */

    boot_parse_memory_loop:
        cmp     x9, x10                                     /* Ensure address is still in ROM region */
        bge     boot_parse_memory_end                       /* Return if outside ROM region */

        mov     x0, x9                                      /* Load address to parse */
        stp     x9,  x10, [sp, #-16]!                       /* Save x9 and x10 on stack */
        stp     x11, x12, [sp, #-16]!                       /* Save x11 and x12 on stack */

        bl      elf_check_match_magic                       /* Call function to check if ELF is valid */
        ldp     x11, x12, [sp], #16                         /* Restore x11 and x12 from stack */
        ldp     x9,  x10, [sp], #16                         /* Restore x9 and x10 from stack */

        cmp     x0, #1                                      /* Check if ELF is valid */
        beq     boot_parse_memory_match                     /* If match, call function to store address */

    boot_parse_memory_resume_loop:
        add     x9, x9, x12                                 /* Increase address to parse */
        b       boot_parse_memory_loop                      /* Resume loop */

    boot_parse_memory_match:
        ldr     x0, =K_BOOT_PARSE_MEMORY_MSG_ELF_FOUND      /* Load message address */
        bl      boot_print_msg                              /* Print message */

        mov     x0, x9                                      /* Load ELF address */
        bl      boot_print_addr                             /* Print address */

        boot_parse_memory_save_working_registers:
            stp     x9,  x10, [sp, #-16]!                   /* Save x9 and x10 on stack */
            stp     x11, x12, [sp, #-16]!                   /* Save x11 and x12 on stack */

        bl      bmt_build_add_elf                                 /* Add ELF address to BMT table */

        boot_parse_memory_restore_working_registers:
            ldp     x11, x12, [sp], #16                     /* Restore x11 and x12 from stack */
            ldp     x9,  x10, [sp], #16                     /* Restore x9 and x10 from stack */

        b       boot_parse_memory_resume_loop               /* Go to resume loop */

    boot_parse_memory_end:
        ldr     x0, =K_BOOT_PARSE_MEMORY_MSG_DONE_PARSING   /* Load message address */
        bl      boot_print_msg                              /* Print message */

        ldp     lr, x30, [sp], #16                          /* Restore lr from stack */
        br      lr                                          /* Return from subroutine */

/* Read-only data section */
.section .rodata

K_BOOT_PARSE_MEMORY_MSG_ELF_FOUND:
    .asciz "\n[BOOT]   Found ELF at address: "

K_BOOT_PARSE_MEMORY_MSG_START_PARSING:
    .asciz "\n[BOOT] Parsing memory for ELF ... "

K_BOOT_PARSE_MEMORY_MSG_DONE_PARSING:
    .asciz "\n[BOOT] Done parsing memory for ELF\n\n"
