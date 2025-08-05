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
    } > RAM_CODE

    /* Writable Data + Uninitialized Data */
    . = ORIGIN(RAM_DATA);
    .data ALIGN(16):
    {
        *(.data*)       /* Data */
        *(.bss*)        /* BSS */
        . = ALIGN(16);
    } > RAM_DATA

    /* Stack */
    . = ORIGIN(RAM_STACK);
    .stack (NOLOAD):
    {
        __stack_start = .;
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_end = .;
    } > RAM_STACK

    /* BMT */
    . = ORIGIN(RAM_BMT);
    .bmt (NOLOAD):
    {
        __bmt_start = .;
        . = . + LENGTH(RAM_BMT);
        . = ALIGN(16);
        __bmt_end = .;
    } > RAM_BMT

    /* IVT */
    . = ORIGIN(RAM_IVT);
    .ivt (NOLOAD):
    {
        __ivt_start = .;
        *(ivt*)             /* IVT (Interrupt Vector Table) */
        . = ALIGN(16);
        __ivt_end = .;
    } > RAM_IVT
}
