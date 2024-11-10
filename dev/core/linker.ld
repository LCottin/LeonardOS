ENTRY(_start)

/* Define the memory regions and their attributes */
MEMORY
{
    /* RAM region with read, write, and execute permissions */
    STACK (rw)  : ORIGIN = 0x40000000, LENGTH = 64K
    RAM (rx)    : ORIGIN = 0x40020000, LENGTH = 256K
    DATA (rw)   : ORIGIN = 0x50000000, LENGTH = 256K
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Set the starting address of the sections to the start of STACK */
    . = ORIGIN(STACK);

    /* Ensure starting alignment */
    . = ALIGN(16);

    /* Place the stack section into the RAM */
    __stack_size = LENGTH(STACK);             /* Size of stack section */
    .stack ALIGN(16):
    {
        __stack_start = .;                    /* Start of the stack section */
        . = . + LENGTH(STACK);
        __stack_end = .;                      /* End of stack section */
    } > STACK

    /* Set the starting address of the sections to the start of RAM */
    . = ORIGIN(RAM);

    /* Ensure starting alignment */
    . = ALIGN(16);

    /* Place all the code sections into the .text section */
    .text ALIGN(16):
    {
        __text_start = .;       /* Start of the text section */
        *(.text*)               /* Include all .text sections */
        *(.text.*)              /* Include all .text sections */
        . = ALIGN(16);          /* Ensure alignment after .text section */
        __text_end = .;         /* End of text section */
    } > RAM

    /* Place all read only section into the .rodata section */
    .rodata ALIGN(16):
    {
        __rodata_start = .;     /* Start of rodata section */
        *(.rodata*)             /* Collect all read-only data sections */
        *(.rodata.*)            /* Collect all read-only data sections */
        . = ALIGN(16);          /* Ensure alignment after .rodata section */
        __rodata_end = .;       /* End of rodata section */
    } > RAM

    /* Set the starting address of the sections to the start of DATA */
    . = ORIGIN(DATA);

    /* Ensure starting alignment */
    . = ALIGN(16);

    /* Place all the initialized data sections into the .data section */
    .data ALIGN(16):
    {
        __data_start = .;       /* Start of data section */
        *(.data*)               /* Place all .data sections */
        *(.data.*)              /* Place all .data sections */
        . = ALIGN(16);          /* Ensure alignment after .data section */
        __data_end = .;         /* End of data section */
    } > DATA

    /* Place all the uninitialized data sections into the .bss section */
    .bss ALIGN(16):
    {
        __bss_start = .;        /* Start of bss section */
        *(.bss*)                /* Place all .bss sections */
        *(.bss.*)               /* Place all .bss sections */
        *(COMMON)               /* Place all .bss sections */
        . = ALIGN(16);          /* Ensure alignment after .bss section */
        __bss_end = .;          /* End of bss section */
    } > DATA
}
