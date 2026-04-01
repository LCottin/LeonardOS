/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(_boot_main_entry)

/* Define memory regions */
MEMORY
{
    RAM_CODE(rx)   : ORIGIN = 0x41000000, LENGTH = 0x20000
    RAM_DATA(rw)   : ORIGIN = 0x41020000, LENGTH = 0x20000
    RAM_STACK (rw) : ORIGIN = 0x41040000, LENGTH = 0x10000

    RAM_BMT(rw)    : ORIGIN = 0x4F000000, LENGTH = 0x10000
    RAM_IVT(rx)    : ORIGIN = 0x4F020000, LENGTH = 0x10000
    RAM_SCH(rw)    : ORIGIN = 0x4F040000, LENGTH = 0x10000
}

INCLUDE "../../../../dev/kernel/boot_bin/linker_sections.ld"
