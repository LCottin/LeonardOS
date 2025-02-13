/* Read-only data section */
.section .rodata

/* Define global symbols */
.global K_BOOT_PRV_ELF_MAGIC
.global K_BOOT_PRV_PAGE_SIZE
.global K_BOOT_PRV_QEMU_UART_ADDR

/* ELF magic number used to identify ELF files */
.equ K_BOOT_PRV_ELF_MAGIC, 0x464C457F

/* Page size used for memory operations */
.equ K_BOOT_PRV_PAGE_SIZE, 0x1000

/* Base address of the UART for QEMU virtual machine */
.equ K_BOOT_PRV_QEMU_UART_ADDR, 0x09000000
