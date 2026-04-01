/* ============================================================================
   Bootloader + Embedded Flash Linker Script
   Target: AArch64
   Load Address: 0x00080000  (Raspberry Pi requirement)
   ========================================================================== */

ENTRY(_boot_main_entry)

/* --------------------------------------------------------------------------
   Memory layout
   -------------------------------------------------------------------------- */

MEMORY
{
    RAM (rwx) : ORIGIN = 0x00080000, LENGTH = 512M
}

/* --------------------------------------------------------------------------
   Sections
   -------------------------------------------------------------------------- */

SECTIONS
{
    /* Base address (RPi loads kernel8.img at 0x80000) */
    . = ORIGIN(RAM);

    __boot_start = .;

    /* --------------------------------------------------
       Text (code)
       -------------------------------------------------- */
    .text ALIGN(16) :
    {
        __text_start = .;
        KEEP(*(.text.boot))      /* early startup */
        *(.text*)
        __text_end = .;
    } > RAM

    /* --------------------------------------------------
       Read-only data
       -------------------------------------------------- */
    .rodata ALIGN(16) :
    {
        __rodata_start = .;
        *(.rodata*)
        __rodata_end = .;
    } > RAM

    /* --------------------------------------------------
       Initialized data
       -------------------------------------------------- */
    .data ALIGN(16) :
    {
        __data_start = .;
        *(.data*)
        __data_end = .;
    } > RAM

    /* --------------------------------------------------
       BSS
       -------------------------------------------------- */
    .bss ALIGN(16) (NOLOAD) :
    {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    } > RAM


    /* Stack */
    .stack (NOLOAD):
    {
        __stack_start = .;
        . = ALIGN(16);
        __stack_end = .;
    } > RAM

    /* BMT */
    .bmt (NOLOAD):
    {
        __bmt_start = .;
        . = ALIGN(16);
        __bmt_end = .;
    } > RAM

    /* IVT */
    .ivt (NOLOAD):
    {
        __ivt_start = .;
        *(ivt*)             /* IVT (Interrupt Vector Table) */
        . = ALIGN(16);
        __ivt_end = .;
    } > RAM

    /* SCH */
    .ivt (NOLOAD):
    {
        __sch_start = .;
        . = ALIGN(16);
        __sch_end = .;
    } > RAM

    /* --------------------------------------------------
       Embedded Flash Image
       -------------------------------------------------- */
    .flash ALIGN(4096) :
    {
        __flash_start = .;

        /* flash.o section renamed to .flash */
        KEEP(*(.flash))

        __flash_end = .;
    } > RAM

    /* --------------------------------------------------
       End markers
       -------------------------------------------------- */
    __boot_end = .;
}
