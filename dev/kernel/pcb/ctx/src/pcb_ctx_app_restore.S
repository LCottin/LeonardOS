.section .text
.global  pcb_ctx_app_restore
.type    pcb_ctx_app_restore, %function

pcb_ctx_app_restore:

    pcb_ctx_app_restore_get_pcb_ctx_addr:
        // Load the address of the global variable g_pcb_ctx_table into register x10
        adrp    x10, g_pcb_ctx_table  // ADRP: Load the page-aligned address of g_pcb_ctx_table into x10
        add     x10, x10, :lo12:g_pcb_ctx_table  // ADD: Add the lower 12 bits to get the exact address of g_pcb_ctx_table

    pcb_ctx_app_restore_get_app_count:
        ldr x12, [x10, #400]  // LDR: Load the 64-bit value at address x10 + 400 into x12
                        // This value is the number of applications (tasks) in the system

    pcb_ctx_app_restore_compare_task_id:
        cmp     x0, x12                                         /* Compare task_id with the number of applications */
        bge     pcb_ctx_app_restore_done                       /* If task_id >= app_count, return */
        // At this point, x0 contains the task_id (application ID) to restore
        // and x12 contains the number of applications (app_count).

    pcb_ctx_app_restore_get_registers_addr:
        // Load the address stored in the pcb_apps_ctx field of g_pcb_ctx_table into register x2
        ldr x11, [x10, #392]  // LDR: Load the 64-bit value at address x10 + 392 into x2
                        // This value is the pointer to the array of pcb_ctx_bin_t structures
                        // Assuming pcb_apps_ctx is the second field in pcb_ctx_table_t (after pcb_krn_ctx)

        // Calculate the address of the element at index task_id in the pcb_apps_ctx array
        // task_id is in register w0 (x0)
        // Each element in the pcb_apps_ctx array is of type pcb_ctx_bin_t, which is 392 bytes
        mov x12, #392  // Move the size of pcb_ctx_bin_t into x12
        mul x12, x0, x12  // MUL: Multiply task_id by 392 to get the offset in bytes
        add x11, x11, x12  // ADD: Add the offset to the base address in x11 to get the address of pcb_apps_ctx[task_id]

        // Since the registers field is the first field in pcb_ctx_bin_t, its offset is 0
        // Therefore, the address in x11 is already the address of pcb_apps_ctx[task_id].registers

    pcb_ctx_app_restore_branch_ctx_restore:
        // Now, x0 contains the address of g_pcb_ctx_table.pcb_apps_ctx[task_id].registers
        mov x0, x11  // Move the address from x11 to x0
        mov x2, x1  // x2 contains the boolean indicating if this is the first run
        mov x1, lr  // Move the link register (return address) to x1
        b      pcb_ctx_restore                /* Call the function to restore registers */

    pcb_ctx_app_restore_done:
        br     lr                                               /* Return from subroutine */
