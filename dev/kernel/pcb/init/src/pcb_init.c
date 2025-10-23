#include "pcb_krn.h"
#include "pcb_ctx.h"
#include "printer_krn.h"
#include "memory_krn.h"
#include "memory_ops_usr.h"
#include "bmt_krn.h"
#include "elf_krn.h"
#include "strings_utils_usr.h"

void pcb_init()
{
    printer_print_string("[KERN] PCB driver initialization ...\n");

    memory_ops_set(&g_pcb_ctx_table, 0, sizeof(g_pcb_ctx_table));

    /* Initialize the PCB kernel context table */
    g_pcb_ctx_table.pcb_krn_ctx.ident.id         = 0;
    g_pcb_ctx_table.pcb_krn_ctx.state            = PCB_STATE_RUNNING;
    g_pcb_ctx_table.pcb_krn_ctx.control.priority = 0;
    g_pcb_ctx_table.pcb_krn_ctx.registers.pc     = bmt_info_get_kernel_entry();
    g_pcb_ctx_table.pcb_krn_ctx.registers.sp     = bmt_info_get_kernel_stack_top();

    /* Initialize the PCB APP context table */
    g_pcb_ctx_table.pcb_apps_count = bmt_info_get_app_count();

    for (uint32_t idx = 0; idx < g_pcb_ctx_table.pcb_apps_count; idx++)
    {
        g_pcb_ctx_table.pcb_apps_ctx[idx].ident.id         = idx;
        g_pcb_ctx_table.pcb_apps_ctx[idx].state            = PCB_STATE_NEW;
        g_pcb_ctx_table.pcb_apps_ctx[idx].control.priority = idx;
        g_pcb_ctx_table.pcb_apps_ctx[idx].registers.pc     = bmt_info_get_app_entry(idx);
        g_pcb_ctx_table.pcb_apps_ctx[idx].registers.sp     = bmt_info_get_app_stack_top(idx);
    }

    printer_print_string("[KERN] PCB driver initialization done.\n");
}
