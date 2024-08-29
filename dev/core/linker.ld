ENTRY(_start)

/* Define the memory regions and their attributes */
MEMORY
{
    /* RAM region with read, write, and execute permissions */
    RAM (rwx) : ORIGIN = 0x40000000, LENGTH = 256K
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Set the starting address of the sections to the start of RAM */
    . = ORIGIN(RAM);

    /* Ensure starting alignment */
    . = ALIGN(16);

    /* Define stack top (RAM end) */
    _stack_top = ORIGIN(RAM) + LENGTH(RAM);

    /* Place all the code sections into the .text section */
    .text :
    {
        *(.text*)              /* Include all .text sections (including main) */
        _etext = .;            /* Mark the end of the .text section */
    } > RAM
    . = ALIGN(16);              /* Ensure alignment after .text section */

    .rodata :
    {
        *(.rodata*)            /* Collect all read-only data sections */
        *(.rodata.*)           /* Collect .rodata.* sections */
        _erodata = .;          /* End of rodata section */
    } > RAM
    . = ALIGN(16);              /* Ensure alignment after .rodata section */

    /* Place all the initialized data sections into the .data section */
    .data : AT(_erodata)
    {
        _data_start = .;       /* Set the symbol _data_start to the current location counter */
        *(.data*)              /* Place all .data sections */
        _data_end = .;         /* Set the symbol _data_end to the current location counter */
    } > RAM
    . = ALIGN(16);              /* Ensure alignment after .data section */

    /* Place all the uninitialized data sections into the .bss section */
    .bss :
    {
        _bss_start = .;        /* Set the symbol _bss_start to the current location counter */
        *(.bss*)               /* Place all the uninitialized data sections into the .bss section */
        _bss_end = .;          /* Set the symbol _bss_end to the current location counter */
    } > RAM
    . = ALIGN(16);              /* Ensure alignment after .bss section */

    /* Reserve space for the stack */
    .stack :
    {
        _stack_start = .;
        . = . + 0x10000; /* Reserve 64KB for stack */
        _stack_end = .;
    } > RAM
    . = ALIGN(16);              /* Ensure alignment after .stack section */
}
