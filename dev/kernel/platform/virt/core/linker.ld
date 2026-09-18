/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(_core_main_entry)

/* Define memory regions */
MEMORY
{
    ROM_METADATA(r) : ORIGIN = 0x00501000, LENGTH = 0x01000
    ROM_CODE(r)     : ORIGIN = 0x00502000, LENGTH = 0x20000
    ROM_DATA(r)     : ORIGIN = 0x00582000, LENGTH = 0x10000

    RAM_CODE(rx)    : ORIGIN = 0x45000000, LENGTH = 0x80000
    RAM_DATA(rw)    : ORIGIN = 0x45080000, LENGTH = 0x80000
    RAM_STACK(rw)   : ORIGIN = 0x45100000, LENGTH = 0x10000
    RAM_GUARD(r)    : ORIGIN = 0x45110000, LENGTH = 0x10000
    RAM_HEAP(rw)    : ORIGIN = 0x45120000, LENGTH = 0x10000
}

/* Define the sections and their placement in memory */
INCLUDE "core/sections.ld"
