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
    __stack_size = LENGTH(RAM_STACK);    /* Size of stack section */
    .stack (NOLOAD):
    {
        . = . + LENGTH(RAM_STACK);
        . = ALIGN(16);
        __stack_top = .;
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

    /* SCH */
    . = ORIGIN(RAM_SCH);
    .sch (NOLOAD):
    {
        __sch_start = .;
        . = . + LENGTH(RAM_SCH);
        . = ALIGN(16);
        __sch_end = .;
    } > RAM_SCH
}
