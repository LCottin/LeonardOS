.section .text
.global  _arch_entry
.type    _arch_entry, %function

_arch_entry:

    arch_entry_clear_registers:
        mov      x0, xzr
        mov      x1, xzr
        mov      x2, xzr
        mov      x3, xzr
        mov      x4, xzr
        mov      x5, xzr
        mov      x6, xzr
        mov      x7, xzr
        mov      x8, xzr
        mov      x9, xzr
        mov     x11, xzr
        mov     x12, xzr
        mov     x13, xzr
        mov     x14, xzr
        mov     x15, xzr
        mov     x16, xzr
        mov     x17, xzr
        mov     x18, xzr
        mov     x19, xzr
        mov     x20, xzr
        mov     x21, xzr
        mov     x22, xzr
        mov     x23, xzr
        mov     x24, xzr
        mov     x25, xzr
        mov     x26, xzr
        mov     x27, xzr
        mov     x28, xzr
        mov     x29, xzr
        mov     x30, xzr

    arch_entry_set_stack_pointer:
        ldr     x10, =__stack_top                       /* Load stack top address */
        and     x10, x10, #0xFFFFFFFFFFFFFFF0           /* Align to 16 bytes */
        mov     sp, x10

    arch_entry_launch_boot:
        b       boot_main                               /* Launch boot main services */
