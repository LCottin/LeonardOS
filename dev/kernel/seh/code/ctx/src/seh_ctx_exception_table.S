.section .ivt, "a"  /* Mark the section as allocatable (associate a load address at runtime) */
.global   seh_ctx_ivt

seh_ctx_ivt:
    /* EL1t (SP_EL0) synchronous exception (offset 0x000) */
    sync_el1t:
        b seh_handler_sync
        .balign 0x80

    /* EL1t IRQ (offset 0x080) */
    irq_el1t:
        b seh_handler_irq
        .balign 0x80

    /* EL1t FIQ (offset 0x100) */
    fiq_el1t:
        b seh_handler_fiq
        .balign 0x80

    /* EL1t SError (offset 0x180) */
    serr_el1t:
        b seh_handler_serr
        .balign 0x80

    /* EL1h (SP_EL1) synchronous exception (offset 0x200) */
    sync_el1h:
        b seh_handler_sync
        .balign 0x80

    /* EL1h IRQ (offset 0x280) */
    irq_el1h:
        b seh_handler_irq
        .balign 0x80

    /* EL1h FIQ (offset 0x300) */
    fiq_el1h:
        b seh_handler_fiq
        .balign 0x80

    /* EL1h SError (offset 0x380) */
    serr_el1h:
        b seh_handler_serr
        .balign 0x80
