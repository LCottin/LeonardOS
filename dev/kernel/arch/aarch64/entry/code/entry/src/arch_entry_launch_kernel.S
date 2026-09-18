.section .text
.global  arch_entry_launch_kernel
.type    arch_entry_launch_kernel, %function

arch_entry_launch_kernel:

    arch_entry_set_kernel_stack:
        and     x1, x1, #0xFFFFFFFFFFFFFFF0             /* Align to 16 bytes */
        mov     sp, x1

    arch_entry_jump:
        mov     x3, x0
        ldr     x0, =__bmt_start                        /* Load BMT start address */
        ldr     x1, =__sch_start                        /* Load SCH start address */
        br      x3                                      /* Launch kernel */
