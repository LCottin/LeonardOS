/* Binary entry point */
ENTRY(_boot_main)

/* Define the memory regions and their attributes */
MEMORY
{
    ROM_TEXT (rx)  : ORIGIN = 0x00000000, LENGTH = 0x20000
    ROM_RODATA (r) : ORIGIN = 0x00020000, LENGTH = 0x10000
    ROM_DATA (rw)  : ORIGIN = 0x00030000, LENGTH = 0x10000

    RAM_DATA (rw)  : ORIGIN = 0x40000000, LENGTH = 0x8000
    RAM_BSS (rw)   : ORIGIN = 0x40080000, LENGTH = 0x10000
    RAM_STACK (rw) : ORIGIN = 0x40180000, LENGTH = 0x10000
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Set the starting address and alignment of the section */
    . = ORIGIN(ROM_TEXT);
    . = ALIGN(16);

    /* Place all the code sections into the .text section */
    .text ALIGN(16):
    {
        __text_start = .;       /* Start of the text section */
        *(.text*)               /* Include all .text sections */
        . = ALIGN(16);          /* Ensure alignment after .text section */
        __text_end = .;         /* End of text section */
    } > ROM_TEXT

    /* Set the starting address and alignment of the section */
    . = ORIGIN(ROM_RODATA);
    . = ALIGN(16);

    /* Place all read only section into the .rodata section */
    .rodata ALIGN(16):
    {
        __rodata_start = .;     /* Start of rodata section */
        *(.rodata*)             /* Collect all read-only data sections */
        . = ALIGN(16);          /* Ensure alignment after .rodata section */
        __rodata_end = .;       /* End of rodata section */
    } > ROM_RODATA

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_DATA);
    . = ALIGN(16);

    /* Place all the initialized data sections into the .data section */
    __data_load = LOADADDR(.data);
    .data ALIGN(16):
    {
        __data_start = .;       /* Start of data section */
        *(.data*)               /* Place all .data sections */
        . = ALIGN(16);          /* Ensure alignment after .data section */
        __data_end = .;         /* End of data section */
    } > RAM_DATA AT > ROM_DATA

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_BSS);
    . = ALIGN(16);

    /* Place all the uninitialized data sections into the .bss section */
    .bss (NOLOAD):
    {
        __bss_start = .;        /* Start of bss section */
        *(.bss*)                /* Place all .bss sections */
        *(COMMON)               /* Place all .bss sections */
        . = ALIGN(16);          /* Ensure alignment after .bss section */
        __bss_end = .;          /* End of bss section */
    } > RAM_BSS

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_STACK);
    . = ALIGN(16);

    /* Place the stack section into the RAM */
    __stack_size = LENGTH(RAM_STACK);          /* Size of stack section */
    .stack(NOLOAD):
    {
        __stack_start = .;                     /* Start of the stack section */
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_end = .;                       /* End of stack section */
    } > RAM_STACK
}
