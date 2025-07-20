.section .text
.global  pcb_ctx_krn_restore
.type    pcb_ctx_krn_restore, %function

pcb_ctx_krn_restore:

    pcb_ctx_krn_restore_get_pcb_ctx_addr:
        // Load the address of the global variable g_pcb_ctx_table into register x10
        adrp    x10, g_pcb_ctx_table  // ADRP: Load the page-aligned address of g_pcb_ctx_table into x10
        add     x10, x10, :lo12:g_pcb_ctx_table  // ADD: Add the lower 12 bits to get the exact address of g_pcb_ctx_table

    pcb_ctx_krn_restore_branch_ctx_restore:
        // Now, x0 contains the address of g_pcb_ctx_table.pcb_krn_ctx.registers
        mov x0, x10  // Move the address from x10 to x0
        mov x1, lr  // Move the link register (return address) to x1
        mov x2, #0  // Set x2 to 1 to indicate this is the first run
        b      pcb_ctx_restore                /* Call the function to restore registers */
