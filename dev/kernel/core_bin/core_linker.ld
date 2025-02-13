/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(_core_entry)

/* Define memory regions */
MEMORY
{
    ROM_TEXT(rx)   : ORIGIN = 0x00050000, LENGTH = 0xC0000
    ROM_CODE(r)     : ORIGIN = 0x00502000, LENGTH = 0x20000
    ROM_DATA(r)     : ORIGIN = 0x00582000, LENGTH = 0x10000

    RAM_CODE(rx)    : ORIGIN = 0x45000000, LENGTH = 0x80000
    RAM_DATA(rw)    : ORIGIN = 0x45080000, LENGTH = 0x80000
    RAM_STACK (rw)  : ORIGIN = 0x45100000, LENGTH = 0x10000
    RAM_GUARD (r)   : ORIGIN = 0x45110000, LENGTH = 0x10000
    RAM_HEAP (rw)   : ORIGIN = 0x45120000, LENGTH = 0x10000
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Code + Read-Only Data */
    . = ORIGIN(RAM_CODE);
    .code ALIGN(16):
    {
        *(.text*)        /* Code */
        *(.rodata*)      /* Read-only data */
        . = ALIGN(16);
    } > RAM_CODE AT > ROM_CODE

    /* Writable Data + Uninitialized Data */
    . = ORIGIN(RAM_DATA);
    .data ALIGN(16):
    {
        *(.data*)       /* Data */
        *(.bss*)        /* BSS */
        . = ALIGN(16);
    } > RAM_DATA AT > ROM_DATA

    /* Stack */
    . = ORIGIN(RAM_STACK);
    .stack (NOLOAD):
    {
        __stack_start = .;
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_end = .;
    } > RAM_STACK

    /* Heap */
    . = ORIGIN(RAM_HEAP);
    __heap_size = LENGTH(RAM_HEAP);      /* Size of heap section */
    .heap (NOLOAD):
    {
        __heap_start = .;
        . = . + LENGTH(RAM_HEAP);
        . = ALIGN(16);
        __heap_end = .;
    } > RAM_HEAP
}
