/* Entry point */
ENTRY(_boot_main)

/* Define memory regions */
MEMORY
{
    ROM (rx) : ORIGIN = 0x00000000, LENGTH = 32K   /* Bootloader in ROM */
}

/* Sections */
SECTIONS
{
    . = ORIGIN(ROM);

    /* ROM sections */
    .text :
    {
        *(.text*)                /* Code */
        *(.rodata*)              /* Read-only data */
        *(.data*)                /* Initialized data */
    } > ROM
}
