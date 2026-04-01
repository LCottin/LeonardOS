/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(count_down_entry)

/* Define memory regions */
MEMORY
{
    ROM_METADATA(r) : ORIGIN = 0x00701000, LENGTH = 0x1000
    ROM_CODE(r)     : ORIGIN = 0x00702000, LENGTH = 0x8000
    ROM_DATA(r)     : ORIGIN = 0x0070a000, LENGTH = 0x8000

    RAM_CODE(rx)    : ORIGIN = 0x45200000, LENGTH = 0x8000
    RAM_DATA(rw)    : ORIGIN = 0x45208000, LENGTH = 0x8000
    RAM_STACK (rw)  : ORIGIN = 0x45210000, LENGTH = 0x1000
    RAM_GUARD (r)   : ORIGIN = 0x45211000, LENGTH = 0x1000
    RAM_HEAP (rw)   : ORIGIN = 0x45212000, LENGTH = 0x1000
}

/* Include generic sections for user binaries */
INCLUDE "linker_sections.ld"
