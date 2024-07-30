ENTRY(_start)

SECTIONS
{
    /* Set the starting address of the sections to 0x40000000 */
    . = 0x40000000;

    /* Place all the code sections into the .text section */
    .text :
    {
        *(.text*)              /* Include all .text sections (including main) */
    }

    .rodata :
    {
        /* Place all the read-only data sections into the .rodata section */
        *(.rodata*)
    }

    .bss :
    {
        _bss_start = .;  /* Set the symbol _bss_start to the current location counter */
        *(.bss*)         /* Place all the uninitialized data sections into the .bss section */
        _bss_end = .;    /* Set the symbol _bss_end to the current location counter */
    }
}