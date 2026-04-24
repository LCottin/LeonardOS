.section .text
.global mmu_init
.type   mmu_init, %function

/**********************************************************************
 * void mmu_init(const bmt_ctx_table_t *p_bmt)
 *
 * x0 = p_bmt (preserved across internal calls via callee-saved x19)
 *
 *   1. Call mmu_page_init()
 *   2. Call _mmu_identity_map_all(p_bmt) — kernel linker symbols + BMT
 *   3. Write MAIR_EL1
 *   4. Write TCR_EL1
 *   5. Write TTBR1_EL1 + TTBR0_EL1
 *   6. DSB
 *   7. Set SCTLR_EL1.M|C|I
 *   8. ISB + DSB
 **********************************************************************/
mmu_init:
    stp     x29, x30, [sp, #-32]!
    mov     x29, sp
    str     x19, [sp, #16]

    /* Save p_bmt across calls */
    mov     x19, x0

    /* 1. Initialize page frame pool */
    bl      mmu_page_init

    /* 2. Populate page tables via BMT + linker symbols */
    mov     x0, x19
    bl      mmu_map_all

    /* 3. MAIR_EL1
     *    Index 0 = Normal memory  (0xFF = WB/WA inner+outer)
     *    Index 1 = Device memory  (0x00 = nGnRnE)
     */
    ldr     x0, =0x00FF
    msr     mair_el1, x0

    /* 4. TCR_EL1 */
    ldr     x0, =0x0000000000803510
    msr     tcr_el1, x0
    isb

    /* 5. TTBR1_EL1 + TTBR0_EL1 — kernel L0 page table */
    bl      mmu_map_get_kernel_pgd
    msr     ttbr1_el1, x0
    msr     ttbr0_el1, x0
    isb

    /* 6. Ensure all table writes visible before MMU on */
    dsb     ish

    /* 7. Enable MMU: M | C | I */
    mrs     x0, sctlr_el1
    orr     x0, x0, #(1 << 0)
    orr     x0, x0, #(1 << 2)
    orr     x0, x0, #(1 << 12)
    msr     sctlr_el1, x0

    /* 8. Re-fetch pipeline with MMU active */
    isb
    dsb     ish

    ldr     x19, [sp, #16]
    ldp     x29, x30, [sp], #32
    ret

