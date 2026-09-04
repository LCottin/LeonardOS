.section .text
.global  scheduler_ctx_save_address
.type    scheduler_ctx_save_address, %function

scheduler_ctx_save_address:
    msr     tpidr_el1, x0          /* Write the address of g_p_scheduler_ctx_table to TPIDR_EL1 */
    br      lr                     /* Return from subroutine */
