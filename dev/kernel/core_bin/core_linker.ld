/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(_core_entry)

/* Define the memory regions and their attributes */
MEMORY
{
    ROM_TEXT(rx)   : ORIGIN = 0x00050000, LENGTH = 0xC0000
    ROM_RODATA(r)  : ORIGIN = 0x00110000, LENGTH = 0x10000
    ROM_DATA(rw)   : ORIGIN = 0x00120000, LENGTH = 0x20000

    RAM_TEXT(rx)   : ORIGIN = 0x45000000, LENGTH = 0x10000
    RAM_RODATA(rx) : ORIGIN = 0x45010000, LENGTH = 0x40000
    RAM_DATA(rw)   : ORIGIN = 0x45050000, LENGTH = 0x40000
    RAM_BSS (rw)   : ORIGIN = 0x45090000, LENGTH = 0x40000
    RAM_STACK (rw) : ORIGIN = 0x450d0000, LENGTH = 0x10000
    RAM_HEAP (rw)  : ORIGIN = 0x450e0000, LENGTH = 0x10000
}

/* Define the sections and their placement in memory */
SECTIONS
{
    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_TEXT);
    . = ALIGN(16);

    /* Place all the code sections into the .text section */
    __text_load = LOADADDR(.text);       /* Load address of text section */
    .text ALIGN(16):
    {
        __text_start = .;                /* Start of the text section */
        *(.text*)                        /* Include all .text sections */
        . = ALIGN(16);                   /* Ensure alignment after .text section */
        __text_end = .;                  /* End of text section */
    } > RAM_TEXT AT > ROM_TEXT

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_RODATA);
    . = ALIGN(16);

    /* Place all read only section into the .rodata section */
    __rodata_load = LOADADDR(.rodata);   /* Load address of rodata section */
    .rodata ALIGN(16):
    {
        __rodata_start = .;              /* Start of rodata section */
        *(.rodata*)                      /* Collect all read-only data sections */
        . = ALIGN(16);                   /* Ensure alignment after .rodata section */
        __rodata_end = .;                /* End of rodata section */
    } > RAM_RODATA AT > ROM_RODATA

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_DATA);
    . = ALIGN(16);

    /* Place all the initialized data sections into the .data section */
    __data_load = LOADADDR(.data);       /* Load address of data section */
    .data ALIGN(16):
    {
        __data_start = .;                /* Start of data section */
        *(.data*)                        /* Place all .data sections */
        . = ALIGN(16);                   /* Ensure alignment after .data section */
        __data_end = .;                  /* End of data section */
    } > RAM_DATA AT > ROM_DATA

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_BSS);
    . = ALIGN(16);

    /* Place all the uninitialized data sections into the .bss section */
    .bss (NOLOAD):
    {
        __bss_start = .;                 /* Start of bss section */
        *(.bss*)                         /* Place all .bss sections */
        . = ALIGN(16);                   /* Ensure alignment after .bss section */
        __bss_end = .;                   /* End of bss section */
    } > RAM_BSS

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_STACK);
    . = ALIGN(16);

    /* Place the stack section into the RAM */
    __stack_size = LENGTH(RAM_STACK);    /* Size of stack section */
    .stack(NOLOAD):
    {
        __stack_start = .;               /* Start of the stack section */
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_end = .;                 /* End of stack section */
    } > RAM_STACK

    /* Set the starting address and alignment of the section */
    . = ORIGIN(RAM_HEAP);
    . = ALIGN(16);

    /* Place the heap section into the RAM */
    __heap_size = LENGTH(RAM_HEAP);      /* Size of heap section */
    .heap (NOLOAD):
    {
        __heap_start = .;                /* Start of the heap section */
        . = . + LENGTH(RAM_HEAP);
        . = ALIGN(16);
        __heap_end = .;                  /* End of heap section */
    } > RAM_HEAP
}
