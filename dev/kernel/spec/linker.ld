/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(__spec_run_entry)

/* Define memory regions */
MEMORY
{
    ALL_CODE(rx)    : ORIGIN = 0x45000000, LENGTH = 0x100000
    RAM_STACK (rw)  : ORIGIN = 0x45100000, LENGTH = 0x10000
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Code + Read-Only Data */
    . = ORIGIN(ALL_CODE);
    .code ALIGN(16):
    {
        *(.text*)        /* Code */
        *(.rodata*)      /* Read-only data */
        *(.data*)       /* Data */
        *(.bss*)        /* BSS */
        . = ALIGN(16);
    } > ALL_CODE

    /* Stack */
    . = ORIGIN(RAM_STACK);
    .stack (NOLOAD):
    {
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_end = .;
    } > RAM_STACK
}
