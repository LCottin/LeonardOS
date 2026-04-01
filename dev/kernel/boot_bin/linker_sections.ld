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

    /* SCH */
    . = ORIGIN(RAM_SCH);
    .ivt (NOLOAD):
    {
        __sch_start = .;
        . = . + LENGTH(RAM_SCH);
        . = ALIGN(16);
        __sch_end = .;
    } > RAM_SCH
}
