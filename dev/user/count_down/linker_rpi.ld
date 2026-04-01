/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(count_down_entry)

/* Define memory regions */
MEMORY
{
    ROM_METADATA(r) : ORIGIN = 0x00321000, LENGTH = 0x1000
    ROM_CODE(r)     : ORIGIN = 0x00322000, LENGTH = 0x8000
    ROM_DATA(r)     : ORIGIN = 0x0032a000, LENGTH = 0x8000

    RAM_CODE(rx)    : ORIGIN = 0x01300000, LENGTH = 0x8000
    RAM_DATA(rw)    : ORIGIN = 0x01308000, LENGTH = 0x8000
    RAM_STACK (rw)  : ORIGIN = 0x01310000, LENGTH = 0x1000
    RAM_GUARD (r)   : ORIGIN = 0x01311000, LENGTH = 0x1000
    RAM_HEAP (rw)   : ORIGIN = 0x01312000, LENGTH = 0x1000
}

/* Include generic sections for user binaries */
INCLUDE "linker_sections.ld"
