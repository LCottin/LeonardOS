/* Set the output format */
OUTPUT_FORMAT("elf64-littleaarch64")
OUTPUT_ARCH("aarch64")

/* Binary entry point */
ENTRY(_boot_main_entry)

/* Define memory regions */
MEMORY
{
    RAM_CODE(rx)           : ORIGIN = 0x41000000, LENGTH = 0x20000
    RAM_DATA(rw)           : ORIGIN = 0x41020000, LENGTH = 0x20000
    RAM_STACK (rw)         : ORIGIN = 0x41040000, LENGTH = 0x10000

    RAM_BMT(rw)            : ORIGIN = 0x4F000000, LENGTH = 0x10000
    RAM_IVT(rx)            : ORIGIN = 0x4F020000, LENGTH = 0x10000
    RAM_SCH(rw)            : ORIGIN = 0x4F040000, LENGTH = 0x10000
    RAM_MMU_KERNEL_EL0(rw) : ORIGIN = 0x4F060000, LENGTH = 0x10000
    RAM_MMU(rw)            : ORIGIN = 0x4F080000, LENGTH = 0x100000
}

/* Define the sections and their placement in memory */
SECTIONS
{

    /* Code + Read-Only Data */
    . = ORIGIN(RAM_CODE);
    .code ALIGN(16):
    {
        __text_start = .;
        *(.text*)        /* Code */
        . = ALIGN(16);
        __text_end = .;
        __rodata_start = .;
        *(.rodata*)      /* Read-only data */
        . = ALIGN(16);
        __rodata_end = .;
    } > RAM_CODE

    /* Writable Data + Uninitialized Data */
    . = ORIGIN(RAM_DATA);
    .data ALIGN(16):
    {
        __data_start = .;
        *(.data*)       /* Data */
        . = ALIGN(16);
        __data_end = .;
        __bss_start = .;
        *(.bss*)        /* BSS */
        . = ALIGN(16);
        __bss_end = .;
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

    /* MMU Kernel EL0 */
    . = ORIGIN(RAM_MMU_KERNEL_EL0);
    .mmu_kernel_el0 (NOLOAD):
    {
        __mmu_kernel_el0_start = .;
        *(page_tables_kernel_l0*)             /* Kernel L0 page table */
        . = ALIGN(16);
        __mmu_kernel_el0_end = .;
    } > RAM_MMU_KERNEL_EL0

    /* MMU Page Frame Pool */
    . = ORIGIN(RAM_MMU);
    .page_pool (NOLOAD):
    {
        __page_pool_start = .;
        . = . + LENGTH(RAM_MMU);
        . = ALIGN(16);
        __page_pool_end = .;
    } > RAM_MMU
}
