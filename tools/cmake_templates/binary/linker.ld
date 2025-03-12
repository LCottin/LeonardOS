/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY()

/* Define memory regions */
MEMORY
{
    ROM_METADATA(r) : ORIGIN = , LENGTH =
    ROM_CODE(r)     : ORIGIN = , LENGTH =
    ROM_DATA(r)     : ORIGIN = , LENGTH =

    RAM_CODE(rx)    : ORIGIN = , LENGTH =
    RAM_DATA(rw)    : ORIGIN = , LENGTH =
    RAM_STACK (rw)  : ORIGIN = , LENGTH =
    RAM_GUARD (r)   : ORIGIN = , LENGTH =
    RAM_HEAP (rw)   : ORIGIN = , LENGTH =
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Metadata Section */
    . = ORIGIN(ROM_METADATA);
    .metadata ALIGN(16):
    {
        /* METADATA in string format */
        BYTE(0x4D) BYTE(0x45) BYTE(0x54) BYTE(0x41)
        BYTE(0x44) BYTE(0x41) BYTE(0x54) BYTE(0x41)

        /* Type of binary in string format (KERN for example) */
        BYTE(0x4B) BYTE(0x45) BYTE(0x52) BYTE(0x4E)

        /* Tag = 0x01, Data = Stack top address */
        LONG(0x01); LONG(ABSOLUTE(__stack_top));

        /* Tag = 0x02, Data = Stack size */
        LONG(0x02); LONG(ABSOLUTE(__stack_size));

        /* Tag = 0x03, Data = Heap start address */
        LONG(0x03); LONG(ABSOLUTE(__heap_start));

        /* Tag = 0x04, Data = Heap size */
        LONG(0x04); LONG(ABSOLUTE(__heap_size));

        . = ALIGN(16);  /* Ensure alignment after .metadata section */
    } > ROM_METADATA

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
    __stack_size = LENGTH(RAM_STACK);    /* Size of stack section */
    .stack (NOLOAD):
    {
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_top = .;
    } > RAM_STACK

    /* Heap */
    . = ORIGIN(RAM_HEAP);
    __heap_size = LENGTH(RAM_HEAP);      /* Size of heap section */
    .heap (NOLOAD):
    {
        __heap_start = .;
        . = . + LENGTH(RAM_HEAP);
        . = ALIGN(16);
    } > RAM_HEAP
}
